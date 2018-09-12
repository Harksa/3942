#include "AnimatedGraphic.h"

void AnimatedGraphic::update() {
	sprite->update();
}

void AnimatedGraphic::draw() {
	GameObject::draw();
}

void AnimatedGraphic::load(const LoadParameters * parameters) {
	GameObject::load(parameters);
}

