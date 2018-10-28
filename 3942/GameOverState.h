#pragma once
#include "MenuState.h"

/**
 * \brief L'état de GameOver
 */
class GameOverState : public MenuState {
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
	 * \brief retour l'ID de l'état.
	 * \return l'ID de l'état.
	 */
	std::string getStateID() const override;

	GameOverState() = default;
	~GameOverState() = default;

private:
	/**
	 * \brief Fonction qui permet de revenir au menu principal.
	 */
	static void gameOverToMain();

	/**
	 * \brief Fonction qui permet de relancer le jeu.
	 */
	static void restartPlay();

	/**
	 * L'ID de l'état.
	 */
	static const std::string game_over_id;

};

