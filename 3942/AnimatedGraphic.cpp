#include "AnimatedGraphic.h"
#include <SDL2/SDL.h>

void AnimatedGraphic::update() {
	sprite->setCurrentFrame(((SDL_GetTicks() / (1000 / animSpeed)) % sprite->getNumFrames()));
}

void AnimatedGraphic::draw() {
	SDLGameObject::draw();
}

void AnimatedGraphic::load(const LoadParameters * parameters) {
	SDLGameObject::load(parameters);
	animSpeed = parameters->getAnimSpeed();
}

