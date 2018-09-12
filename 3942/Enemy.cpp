#include "Enemy.h"
#include "BulletManager.h"

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

	if((SDL_GetTicks() / (1000 / 1) % 3) == 1)
	   BulletManager::Instance()->createEnemyBullet( Vector2D(position.x + sprite->getWidth() * 0.5f, position.y + sprite->getHeight()), Vector2D(0,5) );

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
		is_dead = true;
	}
}
