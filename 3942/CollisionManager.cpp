#include "CollisionManager.h"
#include "GameObject.h"
#include "PlayerBullet.h"
#include "BulletManager.h"
#include "Collision.h"
#include "Enemy.h"

void CollisionManager::checkCollisionEnemyWithPlayerBullets(std::vector<GameObject *> &objects) {
	PlayerBullet * player_bullets = BulletManager::Instance()->getPlayerBullets();

	for (auto &object : objects) {
		if(dynamic_cast<Enemy *> (object) != nullptr) {
			for (int i = 0 ; i < BulletManager::player_bullet_pool_size ; i++) {
				if(player_bullets[i].isAvailable()) {
					if(IntersectRect(object->getRect(), player_bullets[i].getRect())) {
						static_cast<Enemy *>(object)->onCollisionWithBullet(player_bullets[i].getPlayerNum());
						player_bullets[i].onCollision();
					}
				}
			}
		}
	}
}

void CollisionManager::checkCollisionPlayerWithEnemyBullets(Player* player) {
	EnemyBullet * enemy_bullet = BulletManager::Instance()->getEnemyBullets();

	for(unsigned i = 0 ; i < BulletManager::enemy_bullet_pool_size ; i++) {
		if(enemy_bullet[i].isAvailable()) {
			if(IntersectRect(player->getRect(), enemy_bullet[i].getRect())) {
				enemy_bullet[i].onCollision();
				player->onCollision();
			}
		}
	}
}

void CollisionManager::checkCollisionsPlayerAgainstEnemies(Player * player, std::vector<GameObject*> &objects) {
	for (auto &object : objects) {
		if(dynamic_cast<Enemy *> (object) != nullptr) {
			if(IntersectRect(player->getRect(), object->getRect())) {
				player->onCollision();
				static_cast<Enemy*>(object)->onCollisionWithPlayer();

			}
		}
	}
}