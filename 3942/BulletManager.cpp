#include "BulletManager.h"
#include <cassert>

BulletManager * BulletManager::instance {nullptr};

BulletManager* BulletManager::Instance() {
	if (instance == nullptr) {
		instance = new BulletManager();
	}

	return instance;
}

void BulletManager::init() {
	is_already_cleared = false;

	bullet_pool = new BulletPool();

	bullet_pool->firstPlayerBulletAvailable = &bullet_pool->player_bullets[0];
	bullet_pool->firstEnemyBulletAvailable =  &bullet_pool->enemy_bullets[0];

	LoadParameters * pBullet = new LoadParameters(-5, -5, "PlayerBullet");
	LoadParameters * eBullet = new LoadParameters(-5,-5, "EnemyBullet");

	for(int i = 0 ; i < player_bullet_pool_size - 1 ; i++) {
		bullet_pool->player_bullets[i].load(pBullet);
		bullet_pool->player_bullets[i].setNext(&bullet_pool->player_bullets[i+1]);
	}

	for(int i = 0 ; i < enemy_bullet_pool_size - 1 ; i++) {
		bullet_pool->enemy_bullets[i].load(eBullet);
		bullet_pool->enemy_bullets[i].setNext(&bullet_pool->enemy_bullets[i+1]);
	}

	bullet_pool->player_bullets[player_bullet_pool_size - 1].setNext(nullptr);
	bullet_pool->enemy_bullets[enemy_bullet_pool_size - 1].setNext(nullptr);

	bullet_pool->player_bullets[player_bullet_pool_size - 1].load(pBullet);
	bullet_pool->enemy_bullets[enemy_bullet_pool_size - 1].load(eBullet);

	delete pBullet;
	delete eBullet;
}


BulletManager::~BulletManager() {
	if(!is_already_cleared)
		clear();
}

void BulletManager::createPlayerBullet(const PLAYER_NUM pPlayer, const Vector2D pPosition, const Vector2D pVelocity) {
	assert(bullet_pool->firstPlayerBulletAvailable != nullptr);

	PlayerBullet * bullet = bullet_pool->firstPlayerBulletAvailable;
	bullet_pool->firstPlayerBulletAvailable = bullet->getNext();

	bullet->setPlayerNum(pPlayer);
	setupBullet(bullet, pPosition, pVelocity);
}

void BulletManager::createEnemyBullet(const Vector2D pPosition, const Vector2D pVelocity) {
	assert(bullet_pool->firstEnemyBulletAvailable != nullptr);

	EnemyBullet * bullet = bullet_pool->firstEnemyBulletAvailable;
	bullet_pool->firstEnemyBulletAvailable = bullet->getNext();

	setupBullet(bullet, pPosition, pVelocity);
}

void BulletManager::setupBullet(Bullet * pBullet, const Vector2D pPosition, const Vector2D pVelocity) const {
	pBullet->setPosition(pPosition);
	pBullet->setVelocity(pVelocity);
	pBullet->setAvailability(true);
	pBullet->setChangeNext(false);
}

void BulletManager::update() {
	for (auto& bullet : bullet_pool->player_bullets) {
		if(bullet.isAvailable()) {
			bullet.update();
		} else {
			if(bullet.needChangeNext()) {
				bullet.setChangeNext(false);
				bullet.setNext(bullet_pool->firstPlayerBulletAvailable);
				bullet_pool->firstPlayerBulletAvailable = &bullet;
			}
		}
	}

	for(auto &bullet : bullet_pool->enemy_bullets) {
		if(bullet.isAvailable())
			bullet.update();
		else {
			if(bullet.needChangeNext()) {
				bullet.setChangeNext(false);
				bullet.setNext(bullet_pool->firstEnemyBulletAvailable);
				bullet_pool->firstEnemyBulletAvailable = &bullet;
			}
		}
	}
}


void BulletManager::render() const {
	for (auto& bullet : bullet_pool->player_bullets) {
		if(bullet.isAvailable()) {
			bullet.draw();
		}
	}

	for(auto& bullet : bullet_pool->enemy_bullets) {
		if(bullet.isAvailable()) {
			bullet.draw();
		}
	}
}

void BulletManager::clear() {
	if(!is_already_cleared) {
		for (auto& bullet : bullet_pool->player_bullets) {
			bullet.clean();
		}

		for(auto& bullet : bullet_pool->enemy_bullets) {
			bullet.clean();
		}

		delete bullet_pool;

		is_already_cleared = true;
	}
}

PlayerBullet* BulletManager::getPlayerBullets() const { return bullet_pool->player_bullets; }

EnemyBullet* BulletManager::getEnemyBullets() const { return bullet_pool->enemy_bullets; }