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

	/**
	 * \brief Indique que le joueur a gagn� la partie
	 */
	void setHasWon();

	/**
	 * \brief Permet de savoir si le joueur a gagn� la partie
	 * \return Vrai s'il a gagn� la partie, faux sinon
	 */
	bool hasWonGame() const;

	/**
	 * \brief Permet de savoir si le joueur peut avancer au niveau suivant
	 * \return Vrai s'il peut, faux sinon
	 */
	bool canMoveToNextLevel() const;

	/**
	 * \brief Indique que le joueur est entr� en jeu
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
	 * \brief Le temps avant de quiter le jeu
	 */
	unsigned int exit_game_timer{150};

	/**
	 * \brief Le timer
	 */
	unsigned int timer{0};

	/**
	 * \brief D�termine si le joueur a gagn� la partie ou non
	 */
	bool has_won_game{false};

	/**
	 * brief D�termine si le joueur est entr� en jeu
	 */
	bool game_entered{false};

	/**
	 * \brief D�termine si le timer a d�j� �t� r�initialis�
	 */
	bool timer_already_reseted{false};

};
