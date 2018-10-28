#include "Bullet.h"

void Bullet::load(const LoadParameters* pParameters) {
	 GameObject::load(pParameters);
}

void Bullet::draw() {
	GameObject::draw();
}

void Bullet::update() {
	if(is_available) {
		if(isOutsideScreenBondaries()) {
			is_available = false;
			need_change_next = true;
		}
		else 
			GameObject::update();
	}
}

void Bullet::clean() {
	if(!is_already_cleaned) {
		GameObject::clean();
		is_already_cleaned = true;
	}
}

void Bullet::onCollision() {
	is_available = false;
	need_change_next = true;
}

Bullet::~Bullet() {
	Bullet::clean();
}

bool Bullet::isAvailable() const { return is_available; }

void Bullet::setAvailability(const bool pValue) { is_available = pValue; }

bool Bullet::needChangeNext() const { return need_change_next; }

void Bullet::setChangeNext(const bool pValue) { need_change_next = pValue; }
