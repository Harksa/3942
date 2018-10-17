#pragma once
#include <map>
#include <SDL2/SDL.h>
#include "PlayerEnum.h"
#include "tinyxml2.h"

/**
 * \brief Les contr�les du clavier possibles de l'utilisateur
 */
enum CONTROLS {
	MOVE_UP_KEY,
	MOVE_LEFT_KEY,
	MOVE_DOWN_KEY,
	MOVE_RIGHT_KEY,
	FIRE_KEY
};

/**
 * \brief Le nom associ� au contr�le
 */
static const std::string ControlsToString[] = {"Move Up", "Move Left", "Move Down", "Move Right", "Fire"};

/**
 * \brief Cette classe permet de garder en m�moire les touches utilis�es par les joueurs
 */
class KeyboardControls {
public:

	/**
	 * \brief Retourne l'instance de KeyboardControls
	 * \return L'instance de KeyboardControls
	 */
	static KeyboardControls * Instance() {
		if(instance == nullptr) {
			instance = new KeyboardControls();
		}

		return instance;
	}

	/**
	 * \brief Initialise le KeyboardControls
	 */
	void init();

	/**
	 * \brief Change les contr�les avec la cl� donn�e en param�tre
	 * \param new_key_value La nouvelle cl� associ� au contr�les et au joueur rentr�s pr�c�dement en param�tres
	 */
	void changeKey(SDL_Scancode new_key_value);

	/**
	 * \brief Retourne le keycode du joueur associ� � un contr�le
	 * \param player L'ID du joueur dont ont souhaite obtenir la touche
	 * \param key Le contr�le associ� � la touche
	 */
	SDL_Scancode getKeyCode(PLAYER_NUM player, CONTROLS key) const {
		return controls[player].at(key);
	}

	/**
	 * \brief D�termine si les contr�les doivent �tre modifi�s ou non
	 * \param value Vrai si les contr�les doivent �tre modifi�s, faux sinon
	 */
	void askToChangeControls(bool value) {askToChange = value; }

	/**
	 * \brief D�finie le joueur et les contr�les qui doivent �tre chang�s
	 * \param player Le player dont les contr�les seront modifi�s
	 * \param control Le contr�le qui sera modifi�
	 */
	void setToChange(PLAYER_NUM player, CONTROLS control) {
		playerChange = player;
		controlsChange = control;
	}

	/**
	 * \brief Permet de savoir si les contr�les doivent �tre chang�s ou non.
	 * \return Vrai si les contr�les sont � modifier, faux sinon
	 */
	bool isAskingToChangeControls() const {return askToChange; }


	/**
	 * \brief Retourne le joueur dont les contr�les seront modifi�s
	 * \return Le joueur dont les c�ntroles seront modifi�s
	 */
	PLAYER_NUM getPlayerNumToChange() const {return playerChange;}

	/**
	 * \brief Retourne le contr�le qui sera modifi�
	 * \return Le contr�le qui sera modifi�
	 */
	CONTROLS getControlToChange() const {return controlsChange;}

private:

	/**
	 * \brief L'instance de KeyboardControls
	 */
	static KeyboardControls * instance;

	bool askToChange{false};

	/**
	 * \brief Le joueur qui vera ses contr�les �tres modifi�s
	 */
	PLAYER_NUM playerChange;

	/**
	 * \brief Le contr�le � modifier
	 */
	CONTROLS controlsChange;

	/**
	 * \brief Les contr�les des utilisateurs, associ�s � leurs touches du claviers
	 */
	std::map<CONTROLS, SDL_Scancode> controls[2];
};