#pragma once
#include <vector>
#include "GameObject.h"

class CollisionManager {
public:

	static void checkCollisionPlayerBullets(std::vector<GameObject*> &objects);
};

