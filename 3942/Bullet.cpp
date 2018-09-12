#include "Bullet.h"

void Bullet::load(const LoadParameters* parameters) {
	 GameObject::load(parameters);
}

void Bullet::draw() {
	GameObject::draw();
}

void Bullet::update() {
	if(isOutsideScreenBondaries())
	   is_available = false;
	else 
		GameObject::update();
}

void Bullet::clean() {
	GameObject::clean();
}

void Bullet::onCollision() {
	is_available = false;
}
