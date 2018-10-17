#pragma once
#include "MenuState.h"
#include "AnimatedGraphic.h"
#include "FontCache/SDL_FontCache.h"

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
	std::string getStateID() const override { return ControlChooseStateID; }

	ChooseControlState() = default;
	~ChooseControlState() = default;

private:
	/**
	 * \brief Le State ID de cet �tat
	 */
	static std::string ControlChooseStateID;

	/**
	 * \brief L'Animated Graphic repr�sentant le choix de controle du joueur 1
	 */
	static GameObject * ag_controls_player1;

	/**
	 * \brief L'Animated Graphic repr�sentant le choix de controle du joueur 2
	 */
	static GameObject * ag_controls_player2;

	SDL_Rect rect1;

	SDL_Rect rect2;

	static void buttonChoicePlayer1();

	static void buttonChoiceRightPlayer2();

	static void buttonChoiceLeftPlayer2();

	static void handlePlayer2Choice();

	static void enterPlayMode();

	static Player2Choice player2_choice;
};



