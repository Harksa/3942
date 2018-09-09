#pragma once
#include "Bullet.h"

class PlayerBullet :
	public Bullet {
public:
	PlayerBullet() = default;
	~PlayerBullet() = default;

	void draw() override;
	void update() override;
	void clean() override;
	void load(const LoadParameters* parameters) override;
};

