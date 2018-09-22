#pragma once
#include <SDL2/SDL_ttf.h>

/**
 * \brief Cette classe g�re l'interface utilisateur en jeu.
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
	 * \brief Augmente le score et mets � jour les informations � l'�cran
	 * \param points Le nombre de points � incr�menter
	 */
	void increaseScore(unsigned int points);

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
	void clean() const;

	~UIManager() = default;

private:

	UIManager() = default;

	/**
	 * \brief Mets � jour les informations des surface et texture
	 */
	void updateRenderer();

	/**
	 * \brief L'instance de UIManager
	 */
	static UIManager * instance;

	/**
	 * \brief La police de caract�re utilis�
	 */
	TTF_Font * font{nullptr};

	/**
	 *\brief Le SDL_Surface du score
	 */
	SDL_Surface * surfaceMessage{nullptr};

	/**
	 * \brief Le SDL_Texture du score
	 */
	SDL_Texture * textureMessage{nullptr};

	/**
	 * \brief La position du score, sur l'�cran
	 */
	SDL_Rect messagePosition{};

	/**
	 * \brief Le score repr�sentant les points gagn�s par le joueur.
	 */
	unsigned int score{0};
};

