#pragma once
#include "MenuState.h"

enum Player2Choice {
	NO_PLAYER2 = 0,
	KEYBOARD = 1,
	GAMEPAD = 2
};

/**
 * \brief Etat de s�lection des configurations de jeu et du nombre de joueur
 */
class ChooseControlState :
	public MenuState {
public:

	/**
	 * \brief Mets � jour l'�tat
	 */
	void update() override;
	/**
	 * \brief Affiche l'�tat � l'�cran
	 */
	void render() override;

	/**
	 * \brief Actions r�alis�es lors de l'entr� dans cet �tat
	 */
	bool onEnter() override;

	/**
	 * \brief Actions r�alis�es lors de la sortie de cet �tat
	 */
	bool onExit() override;

	/**
	 * \brief Retourne le State ID de cet �tat
	 * \return Le stateID de cet �tat
	 */
	std::string getStateID() const override;

	ChooseControlState() = default;
	~ChooseControlState() = default;

private:
	/**
	 * \brief Le State ID de cet �tat
	 */
	static std::string control_choose_state_id;

	/**
	 * \brief L'Animated Graphic repr�sentant le choix de controle du joueur 1
	 */
	static GameObject * ag_controls_player1;

	/**
	 * \brief L'Animated Graphic repr�sentant le choix de controle du joueur 2
	 */
	static GameObject * ag_controls_player2;

	/**
	 * \brief Rect o� sera positionn� le texte pour le joueur 1 s'il n'a pas branch� sa manette
	 */
	SDL_Rect rect1;

	/**
	 * \brief Rect o� sera positionn� le texte pour le joueur 2 s'il n'a pas branch� sa manette
	 */
	SDL_Rect rect2;

	/**
	 * \brief Actions effectu�es lorsque le joueur appuie sur l'un des boutons associ� au joueur 1
	 */
	static void buttonChoicePlayer1();

	/**
	 * \brief Actions effectu�es lorsqu'un joueur appuie sur le bouton droite associ� au joueur 2
	 */
	static void buttonChoiceRightPlayer2();

	/**
	 * \brief Actions effectu�es lorsqu'un joueur appuie sur le bouton gauche associ� au joueur 2
	 */
	static void buttonChoiceLeftPlayer2();

	/**
	 * \brief G�re la selection du joueur 2
	 */
	static void handlePlayer2Choice();

	/**
	 * \brief Entre dans le jeu
	 */
	static void enterPlayMode();

	/**
	 * \brief Le choix du deuxi�me joueur
	 */
	static Player2Choice player2_choice;
};



