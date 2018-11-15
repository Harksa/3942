#include "CollisionManager.h"
#include "GameObject.h"
#include "PlayerBullet.h"
#include "BulletManager.h"
#include "Collision.h"
#include "Enemy.h"

void CollisionManager::checkCollisionEnemyWithPlayerBullets(std::vector<GameObject *> &pObjects) {
	PlayerBullet * player_bullets = BulletManager::Instance()->getPlayerBullets();

	for (auto &object : pObjects) {
		Enemy * casted_enemy = dynamic_cast<Enemy *> (object) ;
		if(casted_enemy != nullptr) {
			if(!casted_enemy->isDying()) {
				for (int i = 0 ; i < BulletManager::player_bullet_pool_size ; i++) {
					if(player_bullets[i].isAvailable()) {
						if(IntersectRect(object->getRect(), player_bullets[i].getRect())) {
							casted_enemy->onCollisionWithBullet(player_bullets[i].getPlayerNum());
							player_bullets[i].onCollision();
						}
					}
				}
			}
		}
	}
}

void CollisionManager::checkCollisionPlayerWithEnemyBullets(Player* pPlayer) {
	if(!pPlayer->isDying()) {
		EnemyBullet * enemy_bullet = BulletManager::Instance()->getEnemyBullets();

		for(unsigned i = 0 ; i < BulletManager::enemy_bullet_pool_size ; i++) {
			if(enemy_bullet[i].isAvailable()) {
				if(IntersectRect(pPlayer->getRect(), enemy_bullet[i].getRect())) {
					enemy_bullet[i].onCollision();
					pPlayer->onCollision();
				}
			}
		}
	}
}

void CollisionManager::checkCollisionsPlayerAgainstEnemies(Player * pPlayer, std::vector<GameObject*> &pObjects) {
	for (auto &object : pObjects) {
		Enemy * casted_enemy = dynamic_cast<Enemy *> (object);
		if(casted_enemy != nullptr) {
			if(!casted_enemy->isDying()) {
				if(IntersectRect(pPlayer->getRect(), object->getRect())) {
					pPlayer->onCollision();
					casted_enemy->onCollisionWithPlayer();
				}
			}
		}
	}
}