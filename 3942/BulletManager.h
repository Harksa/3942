#pragma once
#include "Bullet.h"
	
class BulletManager {
public:
	BulletManager();
	~BulletManager();

	Bullet * firstAvailable;

	void create(Vector2D position, Vector2D velocity);

	void render();
	void update();
	void clear();

private:
	static const int pool_size = 100;
	Bullet bullets[pool_size]; 
};

