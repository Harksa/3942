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

void PlayerBullet::setPlayerNum(PLAYER_NUM player) { player_num = player; }

PLAYER_NUM PlayerBullet::getPlayerNum() const { return player_num; }

void PlayerBullet::setNext(PlayerBullet* new_bullet) { next = new_bullet; }

PlayerBullet* PlayerBullet::getNext() const { return next; }
