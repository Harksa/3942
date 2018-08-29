#pragma once
#include <vector>
#include "GameObject.h"
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
	 * L'ID de l'état.
	 */
	static const std::string gameOverID;

};

