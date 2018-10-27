#include "ScoreManager.h"

ScoreManager * ScoreManager::instance {nullptr};

ScoreManager* ScoreManager::Instance() {
	if (instance == nullptr)
		instance = new ScoreManager();

	return instance;
}

void ScoreManager::addPoints(unsigned int points, PLAYER_NUM player) {
	switch (player) {
		case(PLAYER_1):
			score_player_1 += points;
			break;
		case(PLAYER_2):
			score_player_2 += points;
			break;
	}
}

unsigned int ScoreManager::getScore(PLAYER_NUM player) const {
		switch (player) {
			case PLAYER_1:
				return score_player_1;
			case PLAYER_2:
				return score_player_2;
		}

		return 0;
}
