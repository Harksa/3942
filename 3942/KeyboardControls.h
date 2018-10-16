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

	void changeKey(SDL_Scancode new_key_value);

	/**
	 * \brief Retourne le keycode du joueur associé à un contrôle
	 * \param player L'ID du joueur dont ont souhaite obtenir la touche
	 * \param key Le contrôle associé à la touche
	 */
	SDL_Scancode getKeyCode(PLAYER_NUM player, CONTROLS key) const {
		return controls[player].at(key);
	}

	void askToChangeControls(bool value) {askToChange = value; }

	void setToChange(PLAYER_NUM player, CONTROLS controls) {
		playerChange = player;
		controlsChange = controls;
	}

	bool isAskingToChangeControls() const {return askToChange; }

	PLAYER_NUM getPlayerNumToChange() const { return playerChange; }

	CONTROLS getControlToChange() const { return controlsChange; }

private:

	/**
	 * \brief L'instance de KeyboardControls
	 */
	static KeyboardControls * instance;

	bool askToChange{false};

	PLAYER_NUM playerChange;

	CONTROLS controlsChange;

	/**
	 * \brief Les contrôles des utilisateurs, associés à leurs touches du claviers
	 */
	std::map<CONTROLS, SDL_Scancode> controls[2];
};