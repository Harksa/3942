#pragma once
#include <vector>
#include "GameObject.h"

/**
 * \brief Cette classe gère les collisions entre les différents GameObjects
 */
class CollisionManager {
public:

	/**
	 * \brief Gère les collisions entre les PlayerBullets et les autres GameObjects
	 * \param objects Les GameObjects de la scène
	 */
	static void checkCollisionPlayerBullets(std::vector<GameObject*> &objects);
};

