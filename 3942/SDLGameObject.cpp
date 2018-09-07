#include "SDLGameObject.h"
#include "TextureManager.h"
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
