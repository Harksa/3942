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
		if(!bulletCreated) {
			BulletManager::Instance()->createEnemyBullet(Vector2D(position.x + sprite->getWidth() * 0.5f, position.y + sprite->getHeight()), Vector2D(0,5) );
		}
	} else if ((SDL_GetTicks() / (1000 / 1) % 5) == 1) {
		bulletCreated = false;
	}

	GameObject::update();
}

void Enemy::clean() {
	GameObject::clean();
}

void Enemy::load(const LoadParameters * parameters) {
	GameObject::load(parameters);
	velocity.y = 2;
}

void Enemy::onCollision() {
	health--;

	if(health <= 0) {
		ScoreManager::Instance()->addPoints(score);
		is_dead = true;
	}
}
