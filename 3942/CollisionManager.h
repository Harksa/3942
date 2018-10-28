#pragma once
#include <vector>
#include "GameObject.h"
#include "Player.h"

/**
 * \brief Cette classe gère les collisions entre les différents GameObjects
 */
class CollisionManager {
public:

	/**
	 * \brief Gère les collisions entre les PlayerBullets et les autres GameObjects
	 * \param pObjects Les GameObjects de la scène
	 */
	static void checkCollisionEnemyWithPlayerBullets(std::vector<GameObject*> &pObjects);

	/**
	 * \brief Gère les collisions des EnemyBullets avec le Player
	 * \param pPlayer Le player dont on va vérifier les collisions.
	 */
	static void checkCollisionPlayerWithEnemyBullets(Player * pPlayer);
	
	/**
	 * \brief Gère la collision entre joueurs et ennemis
	 * \param pPlayer Le joueur
	 * \param pObjects La liste des objets du jeu
	 */
	static void checkCollisionsPlayerAgainstEnemies(Player* pPlayer, std::vector<GameObject*>& pObjects);

};

