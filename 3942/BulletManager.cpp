#include "BulletManager.h"
#include <cassert>

BulletManager * BulletManager::instance = nullptr;

BulletManager::BulletManager() {
	firstPlayerBulletAvailable = &player_bullets[0];

	for(int i = 0 ; i < player_bullet_pool_size - 1 ; i++) {
		player_bullets[i].setNext(&player_bullets[i+1]);
	}

	player_bullets[player_bullet_pool_size - 1].setNext(nullptr);
}


BulletManager::~BulletManager() = default;

void BulletManager::createPlayerBullet(Vector2D position, Vector2D velocity) {
	assert(firstPlayerBulletAvailable != nullptr);

	PlayerBullet * bullet = firstPlayerBulletAvailable;
	firstPlayerBulletAvailable = dynamic_cast<PlayerBullet*> (bullet->getNext());

	bullet->load(new LoadParameters(position.x, position.y, "bullet"));
	bullet->setVelocity(velocity);
	bullet->setAvailability(true);
}

void BulletManager::update() {
	for (auto& bullet : player_bullets) {
		if(bullet.isAvailable()) {
			bullet.update();
		} else {
			bullet.setNext(firstPlayerBulletAvailable);
			firstPlayerBulletAvailable = &bullet;
		}
	}
}


void BulletManager::render() {
	for (auto& bullet : player_bullets) {
		if(bullet.isAvailable()) {
			bullet.draw();
		}
	}
}

void BulletManager::clear() {
	for (auto& bullet : player_bullets) {
		bullet.clean();
	}
}
