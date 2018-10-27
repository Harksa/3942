#pragma once
#include "PlayerManager.h"

/**
 * \brief gère le score du joueur
 */
class ScoreManager {
public:

	/**
	 * \brief Retourne l'instance du ScoreManager
	 */
	static ScoreManager* Instance();

	/**
	 * \brief Ajoute des points au score du joueur
	 * \param points Les points à ajouter
	 * \param player Le joueur dont on souhaite ajouter des points
	 */
	void addPoints(unsigned int points, PLAYER_NUM player);

	/**
	 * \brief Retourne le score actuel du joueur
	 * \param player Le joueur dont on souhaite obtenir le score
	 */
	unsigned int getScore(PLAYER_NUM player = PLAYER_1) const;

	~ScoreManager() = default;
private:

	ScoreManager() = default;

	/**
	 * \brief L'instance du ScoreManager
	 */
	static ScoreManager * instance;

	/**
	 * \brief Le score actuel du joueur 1
	 */
	unsigned int score_player_1{0};

	/**
	 * \brief Le score actuel du joueur 2
	 */
	unsigned int score_player_2{0};

};
