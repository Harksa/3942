#pragma once
#include <utility>
#include "Enemy.h"

struct EnemySpawInformations {
	std::string type;
	float spawn_x{};
	float spawn_y{};
	unsigned int timer{};

	EnemySpawInformations(std::string enemy, const float x, const float y, const unsigned int t) : type(std::move(enemy)), spawn_x(x), spawn_y(y), timer(t) {}
};

class WaveGenerator {
public:
	WaveGenerator() = default;
	~WaveGenerator() = default;

	static void parseWave(const std::string& fileName, std::vector<EnemySpawInformations*> * enemy_spaw_informations);

};

