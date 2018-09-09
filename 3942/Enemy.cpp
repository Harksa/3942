#include "Enemy.h"
#include "BulletManager.h"

Enemy::Enemy() {
	velocity.y = 2;
	velocity.x = 0.001f;
}

void Enemy::draw() {
	SDLGameObject::draw();
}

void Enemy::update() {
	if(position.y < 0)
		velocity.y = 2;
	else if (position.y > 400)
		velocity.y = -2;

	if((SDL_GetTicks() / (1000 / 1) % 3) == 1)
	   BulletManager::Instance()->createEnemyBullet( Vector2D(position.x + sprite->getWidth() * 0.5f, position.y + sprite->getHeight()), Vector2D(0,5) );

	SDLGameObject::update();
}

void Enemy::clean() {
	SDLGameObject::clean();
}

void Enemy::load(const LoadParameters * parameters) {
	SDLGameObject::load(parameters);
	velocity.y = 2;
}
