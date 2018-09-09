#pragma once
#include "Bullet.h"

class EnemyBullet :
	public Bullet {
public:
	EnemyBullet() = default;
	~EnemyBullet() = default;

	void draw() override;
	void update() override;
	void clean() override;
	void load(const LoadParameters* parameters) override;
};

