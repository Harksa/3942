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

	/**
	 * \brief Indique que le joueur a gagné la partie
	 */
	void setHasWon();

	/**
	 * \brief Permet de savoir si le joueur a gagné la partie
	 * \return Vrai s'il a gagné la partie, faux sinon
	 */
	bool hasWonGame() const;

	/**
	 * \brief Permet de savoir si le joueur peut avancer au niveau suivant
	 * \return Vrai s'il peut, faux sinon
	 */
	bool canMoveToNextLevel() const;

	/**
	 * \brief Indique que le joueur est entré en jeu
	 */
	void setGameEntered();

	/**
	 * \brief Reset le timer
	 */
	void resetTimer();

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
	 * \brief Le temps avant de quiter le jeu
	 */
	unsigned int exit_game_timer{150};

	/**
	 * \brief Le timer
	 */
	unsigned int timer{0};

	/**
	 * \brief Détermine si le joueur a gagné la partie ou non
	 */
	bool has_won_game{false};

	/**
	 * brief Détermine si le joueur est entré en jeu
	 */
	bool game_entered{false};

	/**
	 * \brief Détermine si le timer a déjà été réinitialisé
	 */
	bool timer_already_reseted{false};

};
