#pragma once

/**
 * \brief Classe regroupant les paramètres du jeu
 */
class GameParameters {
public:

	/**
	 * \brief Retourne la largeur de la fenêtre de jeu
	 * \return La largeur de la fenêtre de jeu
	 */
	static int getGameWidth() { return game_width;}

	/**
	 * \brief Retourne la hauteur de la fenêtre de jeu
	 * \return La hauteur de la fenêtre de jeu
	 */
	static int getGameHeight() { return game_height;}

private:
	friend class Game;

	/**
	 * \brief La largeur de la fenêtre de jeu
	 */
	static int game_width;

	/**
	 * \brief La hauteur de la fenêtre de jeu
	 */
	static int game_height;

};

