#include "AnimatedGraphic.h"

void AnimatedGraphic::update() {
	sprite->update();
}

void AnimatedGraphic::draw() {
	SDLGameObject::draw();
}

void AnimatedGraphic::load(const LoadParameters * parameters) {
	SDLGameObject::load(parameters);
}

