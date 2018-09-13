#pragma once
#include <vector>
#include "GameObject.h"
#include "Player.h"

/**
 * \brief Cette classe g�re les collisions entre les diff�rents GameObjects
 */
class CollisionManager {
public:

	/**
	 * \brief G�re les collisions entre les PlayerBullets et les autres GameObjects
	 * \param objects Les GameObjects de la sc�ne
	 */
	static void checkCollisionEnemyWithPlayerBullets(std::vector<GameObject*> &objects);

	/**
	 * \brief G�re les collisions des EnemyBullets avec le Player
	 * \param Le player dont on va v�rifier les collisions.
	 */
	static void checkCollisionPlayerWithEnemyBullets(Player * player);

};

