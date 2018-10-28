#pragma once
#include "MenuState.h"

/**
 * \brief L'�tat de GameOver
 */
class GameOverState : public MenuState {
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
	 * \brief retour l'ID de l'�tat.
	 * \return l'ID de l'�tat.
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
	 * L'ID de l'�tat.
	 */
	static const std::string game_over_id;

};

