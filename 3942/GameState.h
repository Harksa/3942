#pragma once
#include <string>
#include <vector>
#include "GameObject.h"
#include "Background.h"

/**
 * \brief Un GameState représente un niveau dans le jeu.
 * (ex : Menu, niveau 1, game over, etc...)
 * Lorsque le joueur rentre dans un état, les actions définies dans "onEnter" sont effectuées.
 * Lorsqu'il quitte l'état, celles dans "onExit" sont effectuées.
 */
class GameState {
public:

	virtual ~GameState() = default;

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

protected:
	/**
	 * \brief Liste des textures utilisés dans cet état.
	 */
	std::vector<std::string> _textureIDList;

	/**
	 * \brief La liste des gameobjects comprit dans l'état.
	 */
	std::vector<GameObject *> _gameObjects;

	/**
	 * \brief Définie si la scène a été entièrement chargé ou non.
	 */
	bool is_loaded = false;

	/**
	 * \brief Background du l'état
	 */
	Background * background = nullptr;
};
