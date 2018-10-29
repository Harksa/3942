#pragma once
#include "FontCache/SDL_FontCache.h"

/**
 * \brief Cette classe g�re l'interface utilisateur en jeu.
 */
class UIManager {
public:

	/**
	 * \brief Initialise l'UIManager
	 */
	void init();

	/**
	 * \brief Mets � jour l'UI
	 */
	void update();

	/**
	 * \brief Dessiner l'UIManager
	 */
	void draw() const;

	/**
	 * \brief Nettoie l'UIManager
	 */
	void clear() const;

	/**
	 * \brief D�termine si l'intro a �t� jou� et si l'on peut jouer
	 * \return Vrai si on peut lancer les vagues, faux sinon.
	 */
	bool canStartGame() const;

	UIManager() = default;
	~UIManager() = default;

private:

	/**
	 * \brief Le rect o� sera affich� le texte de reconnection de manette
	 */
	SDL_Rect text_rect;

	/**
	 * \brief Le rect o� sera affich� le "Start"
	 */
	SDL_Rect start_text_rect;

	/**
	 * \brief Le temps avant entr� en jeu
	 */
	unsigned int enter_game_timer{150};

	/**
	 * \brief Le timer
	 */
	unsigned int timer{0};

};
