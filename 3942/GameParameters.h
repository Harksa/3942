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
	static int getGameWidth() { return game_width; }

	/**
	 * \brief Retourne la hauteur de la fenêtre de jeu
	 * \return La hauteur de la fenêtre de jeu
	 */
	static int getGameHeight() { return game_height; }

	/**
	 * \brief Détermine si le jeu est en mode 2 joueurs ou non
	 * \return Vrai si 2 joueurs, faux sinon
	 */
	static bool isTwoPlayer() { return two_player; }

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

	/**
	 * \brief Booléen déterminant si deux joueurs jouent 
	 */
	static bool two_player;

};

