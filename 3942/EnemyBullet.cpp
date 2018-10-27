#include "EnemyBullet.h"

void EnemyBullet::update() {
	Bullet::update();
}

void EnemyBullet::draw() {
	Bullet::draw();
}

void EnemyBullet::clean() {
	Bullet::clean();
	next = nullptr;
}

void EnemyBullet::load(const LoadParameters* parameters) {
	Bullet::load(parameters);
}

void EnemyBullet::onCollision() {
	Bullet::onCollision();
}

void EnemyBullet::setNext(EnemyBullet* new_bullet) { next = new_bullet; }

EnemyBullet* EnemyBullet::getNext() const { return next; }
