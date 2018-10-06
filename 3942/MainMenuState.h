#pragma once
#include "GameObject.h"
#include "MenuState.h"

/**
 * \brief Le menu principal
 */
class MainMenuState : public MenuState {
public:
	/**
	 * \brief Mets � jour l'�tat.
	 */
	void update() override;

	/**
	 * \brief Affiche l'�tat.
	 */
	void render() override;

	/**
	 * \brief Actions effectu�es lors de l'entr� dans cet �tat.
	 */
	bool onEnter() override;

	/**
	 * \brief Actions effectu�es lors de la sortie de cet �tat.
	 */
	bool onExit() override;

	/**
	 * \brief Retourne l'ID de l'�tat
	 * \return l'ID de l'�tat.
	 */
	std::string getStateID() const override {return menuID;}

	MainMenuState() = default;
	~MainMenuState() = default;

private:

	/**
	 * L'ID de l'�tat.
	 */
	static const std::string menuID;

	/**
	 * \brief Fonction permettant d'aller au jeu en mode solo
	 */
	static void menuToPlay();

	/**
	 * \brief Fonction permettant d'aller aux HighScores
	 */
	static void menuToHighScores() {}

	/**
	 * \brief Fonction permettant d'aller aux options
	 */
	static void menuToOptions() {}

	/**
	 * \brief Fonction permettant de quitter le jeu.
	 */
	static void exitFromMenu();
};

