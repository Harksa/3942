#pragma once
#include <vector>
#include "GameObject.h"
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
	std::string getStateID() const override {return gameOverID;}

protected:
	/**
	 * \brief Permet d'affecter les actions aux bouttons du menu.
	 * \param callbacks Les fonctions que l'on souhaiter affecter aux boutons.
	 */
	void setCallbacks(const std::vector<Callback>& callbacks) override;

private:
	/**
	 * \brief Fonction qui permet de revenir au menu principal.
	 */
	static void _gameOverToMain();

	/**
	 * \brief Fonction qui permet de relancer le jeu.
	 */
	static void _restartPlay();

	/**
	 * L'ID de l'�tat.
	 */
	static const std::string gameOverID;

};

