#include "BulletManager.h"
#include <cassert>

BulletManager * BulletManager::instance = nullptr;

BulletManager::BulletManager() {
	firstAvailable = &bullets[0];

	for(int i = 0 ; i < pool_size - 1 ; i++) {
		bullets[i].setNext(&bullets[i+1]);
	}

	bullets[pool_size - 1].setNext(nullptr);
}


BulletManager::~BulletManager() = default;

void BulletManager::create(Vector2D position, Vector2D velocity) {
	assert(firstAvailable != nullptr);

	Bullet * bullet = firstAvailable;
	firstAvailable = bullet->getNext();

	bullet->load(new LoadParameters(position.x, position.y, "bullet"));
	bullet->setVelocity(velocity);
	bullet->setAvailability(true);
}

void BulletManager::update() {
	for (auto& bullet : bullets) {
		if(bullet.isAvailable()) {
			bullet.update();
		} else {
			bullet.setNext(firstAvailable);
			firstAvailable = &bullet;
		}
	}
}


void BulletManager::render() {
	for (auto& bullet : bullets) {
		if(bullet.isAvailable()) {
			bullet.draw();
		}
	}
}

void BulletManager::clear() {
	for (auto& bullet : bullets) {
		bullet.clean();
	}
}
