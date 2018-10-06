#pragma once
#include "GameObject.h"
#include "MenuState.h"

/**
 * \brief Le menu principal
 */
class MainMenuState : public MenuState {
public:
	/**
	 * \brief Mets à jour l'état.
	 */
	void update() override;

	/**
	 * \brief Affiche l'état.
	 */
	void render() override;

	/**
	 * \brief Actions effectuées lors de l'entré dans cet état.
	 */
	bool onEnter() override;

	/**
	 * \brief Actions effectuées lors de la sortie de cet état.
	 */
	bool onExit() override;

	/**
	 * \brief Retourne l'ID de l'état
	 * \return l'ID de l'état.
	 */
	std::string getStateID() const override {return menuID;}

	MainMenuState() = default;
	~MainMenuState() = default;

private:

	/**
	 * L'ID de l'état.
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

