#include "ObjectLayer.h"

void ObjectLayer::update() {
	for (auto gameobject : game_objects) {
		gameobject->update();
	}
}

void ObjectLayer::render() {
	for (auto gameobject : game_objects) {
		gameobject->draw();
	}
}

std::vector<GameObject*>* ObjectLayer::getGameObjects() { return &game_objects; }

