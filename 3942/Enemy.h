#pragma once
#include "SDLGameObject.h"
#include "GameObjectFactory.h"

class Enemy : public SDLGameObject {
public:
	Enemy();
	void draw() override;
	void update() override;
	void clean() override;
	void load(const LoadParameters* parameters) override;
};

class EnemyCreator : public BaseCreator {
	GameObject* createGameObject() const override {
		return new Enemy();
	}
};