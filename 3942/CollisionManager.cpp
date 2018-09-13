#include "CollisionManager.h"
#include "GameObject.h"
#include "PlayerBullet.h"
#include "BulletManager.h"
#include "Collision.h"
#include "Enemy.h"

void CollisionManager::checkCollisionEnemyWithPlayerBullets(std::vector<GameObject *> &objects) {
	PlayerBullet * player_bullets = BulletManager::Instance()->getPlayerBullets();

	for (GameObject * object : objects) {
		if(dynamic_cast<Enemy *> (object)) {
			for (int i = 0 ; i < BulletManager::player_bullet_pool_size ; i++) {
				
				if(player_bullets[i].isAvailable()) {
					if(IntersectRect(object->getRect(), player_bullets[i].getRect())) {
						object->onCollision();
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
