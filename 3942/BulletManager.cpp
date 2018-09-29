#include "BulletManager.h"
#include <cassert>

BulletManager * BulletManager::instance = nullptr;

void BulletManager::init() {
	is_already_cleared = false;

	firstPlayerBulletAvailable = &player_bullets[0];
	firstEnemyBulletAvailable =  &enemy_bullets[0];

	LoadParameters * pBullet = new LoadParameters(-5, -5, "PlayerBullet");
	LoadParameters * eBullet = new LoadParameters(-5,-5, "EnemyBullet");

	for(int i = 0 ; i < player_bullet_pool_size - 1 ; i++) {
		player_bullets[i].load(pBullet);
		player_bullets[i].setNext(&player_bullets[i+1]);
	}

	for(int i = 0 ; i < enemy_bullet_pool_size - 1 ; i++) {
		enemy_bullets[i].load(eBullet);
		enemy_bullets[i].setNext(&enemy_bullets[i+1]);
	}

	player_bullets[player_bullet_pool_size - 1].setNext(nullptr);
	enemy_bullets[enemy_bullet_pool_size - 1].setNext(nullptr);

	player_bullets[player_bullet_pool_size - 1].load(pBullet);
	enemy_bullets[enemy_bullet_pool_size - 1].load(eBullet);

	delete pBullet;
	delete eBullet;
}


BulletManager::~BulletManager() {
	if(!is_already_cleared)
		clear();
}

void BulletManager::createPlayerBullet(PLAYER_NUM player, const Vector2D position, const Vector2D velocity) {
	assert(firstPlayerBulletAvailable != nullptr);

	PlayerBullet * bullet = firstPlayerBulletAvailable;
	firstPlayerBulletAvailable = bullet->getNext();

	bullet->setPlayerNum(player);
	setupBullet(bullet, position, velocity);
}

void BulletManager::createEnemyBullet(const Vector2D position, const Vector2D velocity) {
	assert(firstEnemyBulletAvailable != nullptr);

	EnemyBullet * bullet = firstEnemyBulletAvailable;
	firstEnemyBulletAvailable = bullet->getNext();

	setupBullet(bullet, position, velocity);
}

void BulletManager::setupBullet(Bullet * bullet, Vector2D position, Vector2D velocity) const {
	bullet->setPosition(position);
	bullet->setVelocity(velocity);
	bullet->setAvailability(true);
	bullet->setChangeNext(false);
}

void BulletManager::update() {
	for (auto& bullet : player_bullets) {
		if(bullet.isAvailable()) {
			bullet.update();
		} else {
			if(bullet.needChangeNext()) {
				bullet.setChangeNext(false);
				bullet.setNext(firstPlayerBulletAvailable);
				firstPlayerBulletAvailable = &bullet;
			}
		}
	}

	for(auto &bullet : enemy_bullets) {
		if(bullet.isAvailable())
			bullet.update();
		else {
			if(bullet.needChangeNext()) {
				bullet.setChangeNext(false);
				bullet.setNext(firstEnemyBulletAvailable);
				firstEnemyBulletAvailable = &bullet;
			}
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
	if(!is_already_cleared) {
		for (auto& bullet : player_bullets) {
			bullet.clean();
			bullet.setNext(nullptr);
		}

		for(auto& bullet : enemy_bullets) {
			bullet.clean();
			bullet.setNext(nullptr);
		}

		is_already_cleared = true;
	}
}
