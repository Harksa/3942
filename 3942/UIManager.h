#pragma once
#include <SDL2/SDL_ttf.h>
#include "FontCache/SDL_FontCache.h"
#include <string>

/**
 * \brief Cette classe gère l'interface utilisateur en jeu.
 */
class UIManager {
public:

	/**
	 * \brief Retourne l'instance de UIManager
	 * \return L'instance de UIManager
	 */
	static UIManager * Instance() {
		if(instance == nullptr)
			instance = new UIManager();

		return instance;
	}

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

	UIManager() = default;

	/**
	 * \brief L'instance de UIManager
	 */
	static UIManager * instance;

};
