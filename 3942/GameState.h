#pragma once
#include <string>
#include <vector>

#include "GameObject.h"
#include "Background.h"
#include "FontManager.h"

/**
 * \brief Un GameState repr�sente un niveau dans le jeu.
 * (ex : Menu, niveau 1, game over, etc...)
 * Lorsque le joueur rentre dans un �tat, les actions d�finies dans "onEnter" sont effectu�es.
 * Lorsqu'il quitte l'�tat, celles dans "onExit" sont effectu�es.
 */
class GameState {
public:

	/**
	 * \brief Mets � jour l'�tat.
	 */
	virtual void update() = 0;

	/**
	 * \brief Affiche l'�tat.
	 */
	virtual void render() = 0;

	/**
	 * \brief Actions effectu�es lors de l'entr� dans cet �tat.
	 */
	virtual bool onEnter() = 0;

	/**
	 * \brief Actions effectu�es lors de la sortie de cet �tat.
	 */
	virtual bool onExit() = 0;

	/**
	 * \brief retour l'ID de l'�tat.
	 * \return l'ID de l'�tat.
	 */
	virtual std::string getStateID() const = 0;

	/**
	 * \brief Permet de savoir si l'�tat a �t� enti�rement charg�
	 * \return Vrai si l'�tat � �t� correctement et enti�rement charg�, faux sinon
	 */
	bool isLoaded() const;

	/**
	 * \brief Permet de savoir si l'�tat est en train d'�tre quitt�
	 * \return Vrai si l'�tat est en train d'�tre quitt�, faux sinon
	 */
	bool isExiting() const;


	/**
	 * \brief Nettoie les �l�ments communs des States.
	 * background, GameObjects et textures
	 */
	void clearState();

	GameState() = default;

	virtual ~GameState();

protected:
	/**
	 * \brief Liste des textures utilis�s dans cet �tat.
	 */
	std::vector<std::string> texture_id_list;

	/**
	 * \brief La liste des gameobjects comprit dans l'�tat.
	 */
	std::vector<GameObject *> game_objects;

	/**
	 * \brief D�finie si la sc�ne a �t� enti�rement charg� ou non.
	 */
	bool is_loaded{false};

	/**
	 * \brief D�finie si la sc�ne est en train d'�tre quitt� ou non.
	 */
	bool is_exiting{false};

	/**
	 * \brief Background du l'�tat
	 */
	Background background{};

	/**
	 * \brief Permet de savoir si l'�tat a d�j� �t� nettoy� ou non
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
