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
	 * \param objects Les GameObjects de la scène
	 */
	static void checkCollisionEnemyWithPlayerBullets(std::vector<GameObject*> &objects);

	/**
	 * \brief Gère les collisions des EnemyBullets avec le Player
	 * \param Le player dont on va vérifier les collisions.
	 */
	static void checkCollisionPlayerWithEnemyBullets(Player * player);

};

