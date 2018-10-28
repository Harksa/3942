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

void EnemyBullet::load(const LoadParameters* pParameters) {
	Bullet::load(pParameters);
}

void EnemyBullet::onCollision() {
	Bullet::onCollision();
}

void EnemyBullet::setNext(EnemyBullet* pNewBullet) { next = pNewBullet; }

EnemyBullet* EnemyBullet::getNext() const { return next; }
