#pragma once
#include "PlayerEnum.h"
#include <string>

/**
 * \brief Classe regroupant les param�tres du jeu
 */
class GameParameters {
public:

	/**
	 * \brief Retourne la largeur de la fen�tre de jeu
	 * \return La largeur de la fen�tre de jeu
	 */
	static int getGameWidth();

	/**
	 * \brief Retourne la hauteur de la fen�tre de jeu
	 * \return La hauteur de la fen�tre de jeu
	 */
	static int getGameHeight();

	/**
	 * \brief D�termine si le jeu se joue � deux joueurs ou non
	 * \param pNewValue Vrai si deux joueurs, faux sinon
	 */
	static void setMulti(bool pNewValue);

	/**
	 * \brief D�termine si le jeu est en mode 2 joueurs ou non
	 * \return Vrai si 2 joueurs, faux sinon
	 */
	static bool isTwoPlayer();

	/**
	 * \brief Permet de savoir si un joueur joue avec le clavier ou non
	 * \param pLayerId l'ID du joueur
	 * \return vrai si le joueur joue avec le clavier, faux sinon
	 */
	static bool isPlayerUsingKeyboard(PLAYER_NUM pLayerId);

	/**
	 * \brief Permet de d�terminer si un joueur joue au clavier ou non
	 * \param pPlayer l'ID du player
	 * \param pValue Le bool�en d�terminant si le joueur joue au clavier ou non
	 */
	static void setPlayerUsingKeyboard(int pPlayer, bool pValue);

	/**
	 * \brief Compte le nombre de niveaux total en fonction du nombre de fichier compris dans le dossier rentr� en param�tre
	 * 1 fichier = 1 niveau
	 * \param pFolderPath Le chemin du dossier contenant les niveaux
	 */
	static void countNumberOfLevels(const std::string& pFolderPath);

	/**
	 * \brief Retourne le nombre total de niveaux
	 * \return Le nombre total de niveaux
	 */
	static unsigned int getTotalNumberOfLevels();

private:
	friend class Game;

	/**
	 * \brief La largeur de la fen�tre de jeu
	 */
	static int game_width;

	/**
	 * \brief La hauteur de la fen�tre de jeu
	 */
	static int game_height;

	/**
	 * \brief Bool�en d�terminant si deux joueurs jouent 
	 */
	static bool two_player;

	/**
	 * \brief Tableau permettant de d�terminer quelles joueurs jouent au clavier
	 */
	static bool isUsingKeyboard[2];

	/**
	 * \brief Le nombre de niveaux total
	 */
	static unsigned int number_of_levels;

};

