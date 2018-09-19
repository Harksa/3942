#include "GameObject.h"
#include "Game.h"

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
		(position.x - sprite->getWidth()) > Game::Instance()->getGameWidth() ||
		(position.y - sprite->getHeight()) > Game::Instance()->getGameHeight();
}
