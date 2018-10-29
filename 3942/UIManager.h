#pragma once
#include "FontCache/SDL_FontCache.h"

/**
 * \brief Cette classe gère l'interface utilisateur en jeu.
 */
class UIManager {
public:

	/**
	 * \brief Initialise l'UIManager
	 */
	void init();

	/**
	 * \brief Mets à jour l'UI
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
	 * \brief Détermine si l'intro a été joué et si l'on peut jouer
	 * \return Vrai si on peut lancer les vagues, faux sinon.
	 */
	bool canStartGame() const;

	UIManager() = default;
	~UIManager() = default;

private:

	/**
	 * \brief Le rect où sera affiché le texte de reconnection de manette
	 */
	SDL_Rect text_rect;

	/**
	 * \brief Le rect où sera affiché le "Start"
	 */
	SDL_Rect start_text_rect;

	/**
	 * \brief Le temps avant entré en jeu
	 */
	unsigned int enter_game_timer{150};

	/**
	 * \brief Le timer
	 */
	unsigned int timer{0};

};
