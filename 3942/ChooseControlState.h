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
	std::string getStateID() const override { return ControlChooseStateID; }

	ChooseControlState() = default;
	~ChooseControlState() = default;

private:
	/**
	 * \brief Le State ID de cet état
	 */
	static std::string ControlChooseStateID;

	/**
	 * \brief L'Animated Graphic représentant le choix de controle du joueur 1
	 */
	static GameObject * ag_controls_player1;

	/**
	 * \brief L'Animated Graphic représentant le choix de controle du joueur 2
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



