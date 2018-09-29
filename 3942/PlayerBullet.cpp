#include "PlayerBullet.h"

void PlayerBullet::update() {
	Bullet::update();
}

void PlayerBullet::draw() {
	Bullet::draw();
}

void PlayerBullet::clean() {
	Bullet::clean();
	next = nullptr;
}

void PlayerBullet::load(const LoadParameters* parameters) {
	Bullet::load(parameters);
}

void PlayerBullet::onCollision() {
	Bullet::onCollision();
}

