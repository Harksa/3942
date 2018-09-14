#pragma once
#include <SDL2/SDL.h>
#include <vector>
#include "Vector2D.h"

/**
 * \brief Enum regroupant les diff�rents boutons de la souris
 */
enum mouseButtons {
	LEFT = 0,
	MIDDLE = 1,
	RIGHT = 2
};

/**
 * \brief Enum pour les diff�rents sticks du joystick
 */
enum stickPosition {
	LEFT_STICK,
	RIGHT_STICK
};

/**
 * G�re les inputs du joueur.
 */
class InputHandler {
public:

	/**
	 * \brief Initialise le joystick de SDL
	 */
	static void initialiseJoysticks();

	/**
	 * \brief Permet de savoir si le joystick a bien �t� initialis� ou non.
	 * \return vrai si le joystick a �t� initialis�, faux sinon.
	 */
	static bool joystickInitialised() { return _joystickInitialised; }

	/**
	 * \brief Permet d'obtenir l'�tat des boutons de la souris
	 * \param buttonNumber L'index du bouton
	 * \return vrai si le bouton est appuy�, faux sinon.
	 */
	static bool getMouseButtonState(int buttonNumber) { return _mouseButtonStates[buttonNumber]; }

	/**
	 * \brief Permet d'obtenir l'�tat d'un bouton du clavier
	 * \param key le bouton du clavier dont on souhaite conna�tre l'�tat
	 * \return vrai si le bouton est appuy�, faux sinon
	 */
	static bool isKeyDown(SDL_Scancode key);

	/**
	 * \brief Permet d'obtenir la position de la souris sur la fen�tre de jeu.
	 * \return La position de la souris
	 */
	static Vector2D * getMousePosition() { return mousePosition; }

	/**
	 * \brief Mets � jour les informations des events
	 */
	static void update();

	/**
	 * \brief Nettoie les events.
	 */
	static void clean();

	/**
	 * \brief R�initialise les events.
	 */
	static void reset();

	/**
	 * \brief Retourne le SDL_Joystick en fonction de son ID.
	 * \param id L'ID du joystick d�sir�
	 * \return Le joystick li� � l'ID
	 */
	static SDL_Joystick * getJoystickByID(int id) {return _joysticks[id];}

	/**
	 * \brief diviseur pour les axis du joysticks
	 */
	static constexpr float diviser = 32767.0f;

	/**
	 * \brief La zone morte du joystick
	 */
	static constexpr float _joystickDeadZone = 10000;


private:

	/**
	 * \brief G�re les connexions des joysticks
	 */
	static void handleJoysticksConnection();

	/**
	 * \brief G�re les �venements li�s � la souris
	 * \param event L'�venement SDL
	 */
	static void handleMouse(SDL_Event & event);

	/**
	 * \brief La position de la souris sur la fen�tre de jeu
	 */
	static Vector2D* mousePosition;

	/**
	 * \brief Tableau d'informations des touches du claviers
	 */
	static const Uint8 * keyStates;

	/**
	 * \brief Les joysticks initialis�s
	 */
	static std::vector<SDL_Joystick*> _joysticks;

	/**
	 * \brief bool�en d�terminant si au moins un joystick a �t� initialis� ou non.
	 */
	static bool _joystickInitialised;

	/**
	 * \brief Le nombre de joysticks actuellement branch�.
	 */
	static int currentNumberOfJoysticks;

	/**
	 * \brief Vecteur d�terminant les �tats des boutons de la souris
	 */
	static std::vector<bool> _mouseButtonStates;

};
