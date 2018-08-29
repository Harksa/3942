#include "Enemy.h"

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

	SDLGameObject::update();
}

void Enemy::clean() {
	SDLGameObject::clean();
}

void Enemy::load(const LoadParameters * parameters) {
	SDLGameObject::load(parameters);
	velocity.y = 2;
}
