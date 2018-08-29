#pragma once
#include <SDL2/SDL.h>
#include <vector>
#include "Vector2D.h"

/**
 * \brief Enum regroupant les différents boutons de la souris
 */
enum mouseButtons {
	LEFT = 0,
	MIDDLE = 1,
	RIGHT = 2
};

/**
 * \brief Enum pour les différents sticks du joystick
 */
enum stickPosition {
	LEFT_STICK,
	RIGHT_STICK
};

/**
 * \brief Enum pour les différents boutons du joystick
 */
enum joystickButton {
	BUTTON_A,
	BUTTON_B,
	BUTTON_X,
	BUTTON_Y,
	BUTTON_START,
	BUTTON_SELECT,
	TRIGGER_LB,
	TRIGGER_LT,
	TRIGGER_RB,
	TRIGGER_RT,
	DPAD_LEFT_CLICK,
	DPAD_RIGHT_CLICK
};

/**
 * Gère les inputs du joueur.
 */
class InputHandler {
public:
	/**
	 * \brief Retourne l'instance d'InputHandler
	 * \return L'instance d'InputHandler
	 */
	static InputHandler * Instance() {
		if(instance == nullptr) {
			instance = new InputHandler();
		}
		return instance;
	}

	/**
	 * \brief Initialise le joystick de SDL
	 */
	void initialiseJoysticks();

	/**
	 * \brief Permet de savoir si le joystick a bien été initialisé ou non.
	 * \return vrai si le joystick a été initialisé, faux sinon.
	 */
	bool joystickInitialised() const { return _joystickInitialised; }

	/**
	 * \brief Permet d'obtenir l'état des boutons de la souris
	 * \param buttonNumber L'index du bouton
	 * \return vrai si le bouton est appuyé, faux sinon.
	 */
	bool getMouseButtonState(int buttonNumber) { return _mouseButtonStates[buttonNumber]; }

	/**
	 * \brief Permet d'obtenir l'état d'un bouton du clavier
	 * \param key le bouton du clavier dont on souhaite connaître l'état
	 * \return vrai si le bouton est appuyé, faux sinon
	 */
	bool isKeyDown(SDL_Scancode key) const;

	/**
	 * \brief Permet d'obtenir la position de la souris sur la fenêtre de jeu.
	 * \return La position de la souris
	 */
	Vector2D * getMousePosition() const { return mousePosition; }

	/**
	 * \brief Mets à jour les informations des events
	 */
	void update();

	/**
	 * \brief Nettoie les events.
	 */
	void clean();

	/**
	 * \brief Réinitialise les events.
	 */
	void reset();

	/**
	 * \brief Retourne le SDL_Joystick en fonction de son ID.
	 * \param id L'ID du joystick désiré
	 * \return Le joystick lié à l'ID
	 */
	SDL_Joystick * getJoystickByID(int id) {return _joysticks[id];}

	/**
	 * \brief Retourne la zone morte du joystick
	 * \return La zone morte du joystick
	 */
	float getJoystickDeadZone() const { return _joystickDeadZone;}

	/**
	 * \brief Retourne le diviser pour les axes du Joystick (afin d'avoir des valeurs comprises entre -1 et 1)
	 * \return Le diviser
	 */
	float getDiviser() {return diviser;}

private:
	InputHandler();
	~InputHandler() = default;

	/**
	 * \brief diviseur pour les axis du joysticks
	 */
	const float diviser = 32767.0f;

	/**
	 * \brief Gère les connexions des joysticks
	 */
	void handleJoysticksConnection();

	/**
	 * \brief Gère les évenements liés à la souris
	 * \param event L'évenement SDL
	 */
	void handleMouse(SDL_Event & event);

	/**
	 * \brief La position de la souris sur la fenêtre de jeu
	 */
	Vector2D* mousePosition;

	/**
	 * \brief Tableau d'informations des touches du claviers
	 */
	const Uint8 * keyStates;

	/**
	 * \brief Les joysticks initialisés
	 */
	std::vector<SDL_Joystick*> _joysticks;

	/**
	 * \brief booléen déterminant si au moins un joystick a été initialisé ou non.
	 */
	bool _joystickInitialised;

	/**
	 * \brief Le nombre de joysticks actuellement branché.
	 */
	int currentNumberOfJoysticks;

	/**
	 * \brief La zone morte du joystick
	 */
	const float _joystickDeadZone = 10000;

	/**
	 * \brief Vecteur déterminant les états des boutons de la souris
	 */
	std::vector<bool> _mouseButtonStates;

	/**
	 * \brief L'instance de l'InputHandler
	 */
	static InputHandler * instance;

};
