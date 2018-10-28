#pragma once
#include "FontCache/SDL_FontCache.h"

/**
 * \brief Cette classe gère l'interface utilisateur en jeu.
 */
class UIManager {
public:

	/**
	 * \brief Retourne l'instance de UIManager
	 * \return L'instance de UIManager
	 */
	static UIManager* Instance();

	/**
	 * \brief Initialise l'UIManager
	 */
	void init();

	/**
	 * \brief Dessiner l'UIManager
	 */
	void draw() const;

	/**
	 * \brief Nettoie l'UIManager
	 */
	void clear() const;

	~UIManager() = default;

private:

	/**
	 * \brief L'instance de UIManager
	 */
	static UIManager * instance;

	/**
	 * \brief Le rect où sera affiché le texte de reconnection de manette
	 */
	SDL_Rect text_rect;
	
	UIManager() = default;

};
