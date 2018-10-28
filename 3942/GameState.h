#pragma once
#include <string>
#include <vector>

#include "GameObject.h"
#include "Background.h"
#include "FontManager.h"

/**
 * \brief Un GameState représente un niveau dans le jeu.
 * (ex : Menu, niveau 1, game over, etc...)
 * Lorsque le joueur rentre dans un état, les actions définies dans "onEnter" sont effectuées.
 * Lorsqu'il quitte l'état, celles dans "onExit" sont effectuées.
 */
class GameState {
public:

	/**
	 * \brief Mets à jour l'état.
	 */
	virtual void update() = 0;

	/**
	 * \brief Affiche l'état.
	 */
	virtual void render() = 0;

	/**
	 * \brief Actions effectuées lors de l'entré dans cet état.
	 */
	virtual bool onEnter() = 0;

	/**
	 * \brief Actions effectuées lors de la sortie de cet état.
	 */
	virtual bool onExit() = 0;

	/**
	 * \brief retour l'ID de l'état.
	 * \return l'ID de l'état.
	 */
	virtual std::string getStateID() const = 0;

	/**
	 * \brief Permet de savoir si l'état a été entièrement chargé
	 * \return Vrai si l'état à été correctement et entièrement chargé, faux sinon
	 */
	bool isLoaded() const;

	/**
	 * \brief Permet de savoir si l'état est en train d'être quitté
	 * \return Vrai si l'état est en train d'être quitté, faux sinon
	 */
	bool isExiting() const;


	/**
	 * \brief Nettoie les éléments communs des States.
	 * background, GameObjects et textures
	 */
	void clearState();

	GameState() = default;

	virtual ~GameState();

protected:
	/**
	 * \brief Liste des textures utilisés dans cet état.
	 */
	std::vector<std::string> texture_id_list;

	/**
	 * \brief La liste des gameobjects comprit dans l'état.
	 */
	std::vector<GameObject *> game_objects;

	/**
	 * \brief Définie si la scène a été entièrement chargé ou non.
	 */
	bool is_loaded{false};

	/**
	 * \brief Définie si la scène est en train d'être quitté ou non.
	 */
	bool is_exiting{false};

	/**
	 * \brief Background du l'état
	 */
	Background background{};

	/**
	 * \brief Permet de savoir si l'état a déjà été nettoyé ou non
	 */
	bool is_already_cleared{false};
};

inline void GameState::clearState() {
	background.clean();

	for (const auto& i : texture_id_list) {
		TextureManager::Instance()->clearFromTextureMapAndInformations(i);
	}

	texture_id_list.clear();

	for (auto object : game_objects) {
		object->clean();
		delete object;
	}

	game_objects.clear();

	FontManager::Instance()->clear();

	is_already_cleared = true;
}

inline GameState::~GameState() {
	if (!is_already_cleared)
		clearState();
}

inline bool GameState::isLoaded() const { return is_loaded; }

inline bool GameState::isExiting() const { return is_exiting; }
