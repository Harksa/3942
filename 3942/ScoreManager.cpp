#include "ScoreManager.h"

ScoreManager * ScoreManager::instance {nullptr};

void ScoreManager::addPoints(unsigned int points) {
	score += points;
}
