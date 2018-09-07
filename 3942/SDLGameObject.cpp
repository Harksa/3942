#include "SDLGameObject.h"
#include "Game.h"

SDLGameObject::SDLGameObject() : GameObject() {}

void SDLGameObject::draw() {
	sprite->draw(position, velocity);
}

void SDLGameObject::update() {
	sprite->update();
	velocity += acceleration;
	position += velocity;
}

void SDLGameObject::clean() {}

bool SDLGameObject::isOutsideScreenBondaries() const {
	return (
		(position.x + sprite->getWidth()) < 0 || 
		(position.y + sprite->getHeight()) < 0 ||
		(position.x - sprite->getWidth()) > Game::Instance()->getGameWidth() ||
		(position.y - sprite->getHeight()) > Game::Instance()->getGameHeight()
	);
}
