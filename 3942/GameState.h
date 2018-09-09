#pragma once
#include <string>
#include <vector>
#include "GameObject.h"
#include "Background.h"
#include "SoundManager.h"

/**
 * \brief Un GameState repr�sente un niveau dans le jeu.
 * (ex : Menu, niveau 1, game over, etc...)
 * Lorsque le joueur rentre dans un �tat, les actions d�finies dans "onEnter" sont effectu�es.
 * Lorsqu'il quitte l'�tat, celles dans "onExit" sont effectu�es.
 */
class GameState {
public:

	virtual ~GameState();

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

protected:
	/**
	 * \brief Liste des textures utilis�s dans cet �tat.
	 */
	std::vector<std::string> _textureIDList;

	/**
	 * \brief La liste des gameobjects comprit dans l'�tat.
	 */
	std::vector<GameObject *> _gameObjects;

	/**
	 * \brief Background du l'�tat
	 */
	Background * background = nullptr;
};
