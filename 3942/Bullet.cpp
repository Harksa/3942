#include "Bullet.h"

void Bullet::load(const LoadParameters* parameters) {
	 SDLGameObject::load(parameters);
}

void Bullet::draw() {
	SDLGameObject::draw();
}


void Bullet::update() {
	if(isOutsideScreenBondaries())
	   is_available = false;
	else 
		SDLGameObject::update();
}

void Bullet::clean() {
	SDLGameObject::clean();
}
