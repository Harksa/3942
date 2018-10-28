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

void PlayerBullet::load(const LoadParameters* pParameters) {
	Bullet::load(pParameters);
}

void PlayerBullet::onCollision() {
	Bullet::onCollision();
}

void PlayerBullet::setPlayerNum(const PLAYER_NUM pPlayer) { player_num = pPlayer; }

PLAYER_NUM PlayerBullet::getPlayerNum() const { return player_num; }

void PlayerBullet::setNext(PlayerBullet* pNewBullet) { next = pNewBullet; }

PlayerBullet* PlayerBullet::getNext() const { return next; }
