#pragma once
#include <map>
#include <SDL2/SDL.h>
#include "PlayerEnum.h"
#include "tinyxml2.h"

/**
 * \brief Les contrôles du clavier possibles de l'utilisateur
 */
enum CONTROLS {
	MOVE_UP_KEY,
	MOVE_LEFT_KEY,
	MOVE_DOWN_KEY,
	MOVE_RIGHT_KEY,
	FIRE_KEY
};

/**
 * \brief Le nom associé au contrôle
 */
static const std::string ControlsToString[] = {"Move Up", "Move Left", "Move Down", "Move Right", "Fire"};

/**
 * \brief Cette classe permet de garder en mémoire les touches utilisées par les joueurs
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
	 * \brief Change les contrôles avec la clé donnée en paramètre
	 * \param new_key_value La nouvelle clé associé au contrôles et au joueur rentrés précédement en paramètres
	 */
	void changeKey(SDL_Scancode new_key_value);

	/**
	 * \brief Retourne le keycode du joueur associé à un contrôle
	 * \param player L'ID du joueur dont ont souhaite obtenir la touche
	 * \param key Le contrôle associé à la touche
	 */
	SDL_Scancode getKeyCode(PLAYER_NUM player, CONTROLS key) const {
		return controls[player].at(key);
	}

	/**
	 * \brief Détermine si les contrôles doivent être modifiés ou non
	 * \param value Vrai si les contrôles doivent être modifiés, faux sinon
	 */
	void askToChangeControls(bool value) {askToChange = value; }

	/**
	 * \brief Définie le joueur et les contrôles qui doivent être changés
	 * \param player Le player dont les contrôles seront modifiés
	 * \param control Le contrôle qui sera modifié
	 */
	void setToChange(PLAYER_NUM player, CONTROLS control) {
		playerChange = player;
		controlsChange = control;
	}

	/**
	 * \brief Permet de savoir si les contrôles doivent être changés ou non.
	 * \return Vrai si les contrôles sont à modifier, faux sinon
	 */
	bool isAskingToChangeControls() const {return askToChange; }


	/**
	 * \brief Retourne le joueur dont les contrôles seront modifiés
	 * \return Le joueur dont les côntroles seront modifiés
	 */
	PLAYER_NUM getPlayerNumToChange() const {return playerChange;}

	/**
	 * \brief Retourne le contrôle qui sera modifié
	 * \return Le contrôle qui sera modifié
	 */
	CONTROLS getControlToChange() const {return controlsChange;}

private:

	/**
	 * \brief L'instance de KeyboardControls
	 */
	static KeyboardControls * instance;

	bool askToChange{false};

	/**
	 * \brief Le joueur qui vera ses contrôles êtres modifiés
	 */
	PLAYER_NUM playerChange;

	/**
	 * \brief Le contrôle à modifier
	 */
	CONTROLS controlsChange;

	/**
	 * \brief Les contrôles des utilisateurs, associés à leurs touches du claviers
	 */
	std::map<CONTROLS, SDL_Scancode> controls[2];
};