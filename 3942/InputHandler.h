#pragma once
#include <SDL2/SDL.h>
#include <vector>
#include "Vector2D.h"

/**
 * \brief Enum regroupant les différents boutons de la souris
 */
enum mouseButtons {
	LEFT_BUTTON = 0,
	MIDDLE_BUTTON = 1,
	RIGHT_BUTTON = 2
};

/**
 * \brief Enum pour les différents sticks du joystick
 */
enum stickPosition {
	LEFT_STICK,
	RIGHT_STICK
};

/**
 * Gère les inputs du joueur.
 */
class InputHandler {
public:

	/**
	 * \brief Initialise le joystick de SDL
	 */
	static void initialiseJoysticks();

	/**
	 * \brief Permet de savoir si le joystick a bien été initialisé ou non.
	 * \return vrai si le joystick a été initialisé, faux sinon.
	 */
	static bool joystickInitialised();

	/**
	 * \brief Permet d'obtenir l'état des boutons de la souris
	 * \param pButtonNumber L'index du bouton
	 * \return vrai si le bouton est appuyé, faux sinon.
	 */
	static bool getMouseButtonState(int pButtonNumber);

	/**
	 * \brief Permet d'obtenir l'état d'un bouton du clavier
	 * \param pKey le bouton du clavier dont on souhaite connaître l'état
	 * \return vrai si le bouton est appuyé, faux sinon
	 */
	static bool isKeyDown(SDL_Scancode pKey);

	/**
	 * \brief Permet d'obtenir la position de la souris sur la fenêtre de jeu.
	 * \return La position de la souris
	 */
	static Vector2D* getMousePosition();

	/**
	 * \brief Mets à jour les informations des events
	 */
	static void update();

	/**
	 * \brief Nettoie les events.
	 */
	static void clean();

	/**
	 * \brief Réinitialise les events.
	 */
	static void reset();

	/**
	 * \brief Retourne le SDL_Joystick en fonction de son ID.
	 * \param pId L'ID du joystick désiré
	 * \return Le joystick lié à l'ID
	 */
	static SDL_Joystick* getJoystickByID(int pId);

	/**
	 * \brief Retourne le nombre de joysticks actuellement connectés au PC
	 * \return Le nombre de joysticks actuellement connectés
	 */
	static unsigned int getNumberOfJoysticks();

	/**
	 * \brief diviseur pour les axis du joysticks
	 */
	static constexpr float diviser{32767.0f};

	/**
	 * \brief La zone morte du joystick
	 */
	static constexpr float joystick_dead_zone{10000};

	/**
	 * \brief Détermine si le nombre de joysticks connectés correspond au nombre de joueurs jouant avec un joysticks
	 * \return Vrai si le nombre est correct, faux sinon
	 */
	static bool areNumberOfJoysticksEgalsToNumberOfPlayersUsingJoysticks();

	/**
	 * \brief Retourne le KeyState de SDL
	 * \return Le keyState de SDL
	 */
	static const Uint8* getKeyStates();

private:

	/**
	 * \brief Le nombre maximal de joueur pouvant jouer ensemble
	 */
	static constexpr unsigned int MAX_PLAYER_COUNT = 2;

	/**
	 * \brief Gère les connexions des joysticks
	 */
	static void handleJoysticksConnection();

	/**
	 * \brief Gère les évenements liés à la souris
	 * \param pEvent L'évenement SDL
	 */
	static void handleMouse(SDL_Event & pEvent);

	/**
	 * \brief La position de la souris sur la fenêtre de jeu
	 */
	static Vector2D* mouse_position;

	/**
	 * \brief Tableau d'informations des touches du claviers
	 */
	static const Uint8 * key_states;

	/**
	 * \brief Le tableau regroupant les joysticks
	 */
	static SDL_Joystick * joystick_arrays[MAX_PLAYER_COUNT];

	/**
	 * \brief Le tableau déterminant si le joystick à l'ID indiqué est connecté ou non
	 */
	static bool is_connected[MAX_PLAYER_COUNT];

	/**
	 * \brief booléen déterminant si au moins un joystick a été initialisé ou non.
	 */
	static bool joystick_initialised;

	/**
	 * \brief Le nombre de joysticks actuellement branché.
	 */
	static int current_number_of_joysticks;

	/**
	 * \brief Vecteur déterminant les états des boutons de la souris
	 */
	static std::vector<bool> mouse_button_states;

};
