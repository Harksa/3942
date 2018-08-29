#include "ObjectLayer.h"

void ObjectLayer::update() {
	for (auto gameobject : _gameobjects) {
		gameobject->update();
	}
}

void ObjectLayer::render() {
	for (auto gameobject : _gameobjects) {
		gameobject->draw();
	}
}

