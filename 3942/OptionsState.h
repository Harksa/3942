#pragma once
#include "MenuState.h"
#include "KeyboardOptionButton.h"
#include "FontCache/SDL_FontCache.h"

/**
 * \brief Etat affichant les options du jeu
 */
class OptionsState : public MenuState {
public:
	OptionsState() = default;
	~OptionsState() = default;

	/**
	 * \brief Mets à jour l'état d'options
	 */
	void update() override;

	/**
	 * \brief Affiche à l'écran l'état d'options
	 */
	void render() override;

	/**
	 * \brief Actions effectuées lors de l'entré dans l'état
	 */
	bool onEnter() override;

	/**
	 * \brief Actions effectuées lors de la sortie de l'état
	 */
	bool onExit() override;

	/**
	 * \brief Retourne le StateID de l'état
	 */
	std::string getStateID() const override {return optionsID;}

private:
	/**
	 * \brief Le state ID de cet état
	 */
	static std::string optionsID;

	/**
	 * \brief Les vecteurs comprennant les boutons de changement de touches du clavier
	 */
	static std::vector<KeyboardOptionButton *> keyboard_options;

	/**
	 * \brief Le rect où sera affiché le texte de selection de contrôles
	 */
	SDL_Rect text_rect;

	/**
	 * \brief La fonction permettant de revenir au menu principal
	 */
	static void optionsToMenu();
};

