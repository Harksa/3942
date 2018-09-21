#include "GameObject.h"
#include "GameParameters.h"

void GameObject::draw() {
	sprite->draw(position, velocity);
}

void GameObject::update() {
	sprite->update();
	velocity += acceleration;
	position += velocity;
}

void GameObject::clean() {
	delete sprite;
	is_already_cleaned = true;
}

bool GameObject::isOutsideScreenBondaries() const {
	return
		(position.x + sprite->getWidth()) < 0 || 
		(position.y + sprite->getHeight()) < 0 ||
		(position.x - sprite->getWidth()) > GameParameters::getGameWidth() ||
		(position.y - sprite->getHeight()) > GameParameters::getGameHeight();
}
