#pragma once
#include "MenuState.h"

/**
 * \brief Etat de pause du jeu
 */
class PauseState : public MenuState {
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

	PauseState() = default;
	~PauseState() = default;

private:
	/**
	 * \brief Reviens du menu de pause au menu principal.
	 */
	static void pauseToMain();

	/**
	 * \brief Résume le jeu.
	 */
	static void resumePlay();

	/**
	 * L'ID de l'état.
	 */
	static const std::string pauseID;
};

