#include "BulletManager.h"
#include <cassert>

BulletManager * BulletManager::instance = nullptr;

BulletManager::BulletManager() {
	firstPlayerBulletAvailable = &player_bullets[0];
	firstEnemyBulletAvailable =  &enemy_bullets[0];

	for(int i = 0 ; i < player_bullet_pool_size - 1 ; i++) {
		player_bullets[i].setNext(&player_bullets[i+1]);
	}

	for(int i = 0 ; i < enemy_bullet_pool_size - 1 ; i++) {
		enemy_bullets[i].setNext(&enemy_bullets[i+1]);
	}

	player_bullets[player_bullet_pool_size - 1].setNext(nullptr);
	enemy_bullets[enemy_bullet_pool_size - 1].setNext(nullptr);
}


BulletManager::~BulletManager() = default;

void BulletManager::createPlayerBullet(const Vector2D position, const Vector2D velocity) {
	assert(firstPlayerBulletAvailable != nullptr);

	PlayerBullet * bullet = firstPlayerBulletAvailable;
	firstPlayerBulletAvailable = bullet->getNext();

	bullet->load(new LoadParameters(position.x, position.y, "PlayerBullet"));
	bullet->setVelocity(velocity);
	bullet->setAvailability(true);
}

void BulletManager::createEnemyBullet(const Vector2D position, const Vector2D velocity) {
	assert(firstEnemyBulletAvailable != nullptr);

	EnemyBullet * bullet = firstEnemyBulletAvailable;
	firstEnemyBulletAvailable = bullet->getNext();

	bullet->load(new LoadParameters(position.x, position.y, "EnemyBullet"));
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

	for(auto &bullet : enemy_bullets) {
		if(bullet.isAvailable())
			bullet.update();
		else {
			bullet.setNext(firstEnemyBulletAvailable);
			firstEnemyBulletAvailable = &bullet;
		}
	}
}


void BulletManager::render() {
	for (auto& bullet : player_bullets) {
		if(bullet.isAvailable()) {
			bullet.draw();
		}
	}

	for(auto& bullet : enemy_bullets) {
		if(bullet.isAvailable()) {
			bullet.draw();
		}
	}
}

void BulletManager::clear() {
	for (auto& bullet : player_bullets) {
		bullet.clean();
	}

	for(auto& bullet : enemy_bullets) {
		bullet.clean();
	}
}
