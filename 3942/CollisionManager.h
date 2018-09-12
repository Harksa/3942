#pragma once
#include <vector>
#include "GameObject.h"

/**
 * \brief Cette classe g�re les collisions entre les diff�rents GameObjects
 */
class CollisionManager {
public:

	/**
	 * \brief G�re les collisions entre les PlayerBullets et les autres GameObjects
	 * \param objects Les GameObjects de la sc�ne
	 */
	static void checkCollisionPlayerBullets(std::vector<GameObject*> &objects);
};

