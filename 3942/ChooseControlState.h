#pragma once
#include "MenuState.h"

enum Player2Choice {
	NO_PLAYER2 = 0,
	KEYBOARD = 1,
	GAMEPAD = 2
};

/**
 * \brief Etat de sélection des configurations de jeu et du nombre de joueur
 */
class ChooseControlState :
	public MenuState {
public:

	/**
	 * \brief Mets à jour l'état
	 */
	void update() override;
	/**
	 * \brief Affiche l'état à l'écran
	 */
	void render() override;

	/**
	 * \brief Actions réalisées lors de l'entré dans cet état
	 */
	bool onEnter() override;

	/**
	 * \brief Actions réalisées lors de la sortie de cet état
	 */
	bool onExit() override;

	/**
	 * \brief Retourne le State ID de cet état
	 * \return Le stateID de cet état
	 */
	std::string getStateID() const override;

	ChooseControlState() = default;
	~ChooseControlState() = default;

private:
	/**
	 * \brief Le State ID de cet état
	 */
	static std::string control_choose_state_id;

	/**
	 * \brief L'Animated Graphic représentant le choix de controle du joueur 1
	 */
	static GameObject * ag_controls_player1;

	/**
	 * \brief L'Animated Graphic représentant le choix de controle du joueur 2
	 */
	static GameObject * ag_controls_player2;

	/**
	 * \brief Rect où sera positionné le texte pour le joueur 1 s'il n'a pas branché sa manette
	 */
	SDL_Rect rect1;

	/**
	 * \brief Rect où sera positionné le texte pour le joueur 2 s'il n'a pas branché sa manette
	 */
	SDL_Rect rect2;

	/**
	 * \brief Actions effectuées lorsque le joueur appuie sur l'un des boutons associé au joueur 1
	 */
	static void buttonChoicePlayer1();

	/**
	 * \brief Actions effectuées lorsqu'un joueur appuie sur le bouton droite associé au joueur 2
	 */
	static void buttonChoiceRightPlayer2();

	/**
	 * \brief Actions effectuées lorsqu'un joueur appuie sur le bouton gauche associé au joueur 2
	 */
	static void buttonChoiceLeftPlayer2();

	/**
	 * \brief Gère la selection du joueur 2
	 */
	static void handlePlayer2Choice();

	/**
	 * \brief Entre dans le jeu
	 */
	static void enterPlayMode();

	/**
	 * \brief Le choix du deuxième joueur
	 */
	static Player2Choice player2_choice;
};



