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

protected:
	/**
	 * \brief Permet d'affecter les actions aux bouttons du menu.
	 * \param callbacks Les fonctions que l'on souhaiter affecter aux boutons.
	 */
	void setCallbacks(const std::vector<Callback>& callbacks) override;

private:

	/**
	 * L'ID de l'état.
	 */
	static const std::string menuID;

	/**
	 * \brief Fonction permettant d'aller au jeu.
	 */
	static void menuToPlay();

	/**
	 * \brief Fonction permettant de quitter le jeu.
	 */
	static void exitFromMenu();
};

