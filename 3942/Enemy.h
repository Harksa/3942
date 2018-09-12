#pragma once
#include "GameObject.h"
#include "GameObjectFactory.h"

class Enemy : public GameObject {
public:
	Enemy();
	void draw() override;
	void update() override;
	void clean() override;
	void load(const LoadParameters* parameters) override;
	void onCollision() override;

private:
	/**
	 * \brief La vie de l'enemie.
	 */
	int health;
};

class EnemyCreator : public BaseCreator {
	GameObject* createGameObject() const override {
		return new Enemy();
	}
};