#include "Enemy.h"
#include "BulletManager.h"
#include "ScoreManager.h"

Enemy::Enemy() {
	velocity.y = 2;
	velocity.x = 0.001f;
	health = 3;
}

void Enemy::draw() {
	GameObject::draw();
}

void Enemy::update() {
	if(position.y < 0)
		velocity.y = 2;
	else if (position.y > 400)
		velocity.y = -2;

	if((SDL_GetTicks() / (1000 / 1) % 2) == 1) {
		if(!bullet_created) {
			BulletManager::Instance()->createEnemyBullet(Vector2D(position.x + sprite->getWidth() * 0.5f, position.y + sprite->getHeight()), Vector2D(0,5) );
		}
	} else if ((SDL_GetTicks() / (1000 / 1) % 5) == 1) {
		bullet_created = false;
	}

	GameObject::update();
}

void Enemy::clean() {
	GameObject::clean();
}

void Enemy::load(const LoadParameters * pParameters) {
	GameObject::load(pParameters);
	velocity.y = 2;
}


void Enemy::onCollisionWithBullet(PLAYER_NUM pLayerBulletNum) {
	health--;

	if(health <= 0) {
		ScoreManager::Instance()->addPoints(points, pLayerBulletNum);
		changeSprite("Explosion");
		is_dying = true;
	}
}

void Enemy::onCollisionWithPlayer() {
	changeSprite("Explosion");
	is_dying = true;
}

void Enemy::setPoints(const unsigned int pPoints) { points = pPoints; }

void Enemy::setHealth(const int pHealth) { health = pHealth; }
