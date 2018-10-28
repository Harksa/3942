#pragma once
#include "MenuState.h"
#include "KeyboardOptionButton.h"

/**
 * \brief Etat affichant les options du jeu
 */
class OptionsState : public MenuState {
public:
	/**
	 * \brief Mets � jour l'�tat d'options
	 */
	void update() override;

	/**
	 * \brief Affiche � l'�cran l'�tat d'options
	 */
	void render() override;

	/**
	 * \brief Actions effectu�es lors de l'entr� dans l'�tat
	 */
	bool onEnter() override;

	/**
	 * \brief Actions effectu�es lors de la sortie de l'�tat
	 */
	bool onExit() override;

	/**
	 * \brief Retourne le StateID de l'�tat
	 */
	std::string getStateID() const override;

	OptionsState() = default;
	~OptionsState() = default;

private:

	/**
	 * \brief Bool�en permettant de d�terminer si un scancode a d�j� �t� utilis�
	 */
	bool scancode_already_used{false};

	/**
	 * \brief Le state ID de cet �tat
	 */
	static std::string options_id;

	/**
	 * \brief Les vecteurs comprennant les boutons de changement de touches du clavier
	 */
	static std::vector<KeyboardOptionButton *> keyboard_options;

	/**
	 * \brief Le rect o� sera affich� le texte de selection de contr�les
	 */
	SDL_Rect text_rect{};

	/**
	 * \brief La fonction permettant de revenir au menu principal
	 */
	static void optionsToMenu();
};

