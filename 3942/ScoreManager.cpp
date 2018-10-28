#include "ScoreManager.h"

ScoreManager * ScoreManager::instance {nullptr};

ScoreManager* ScoreManager::Instance() {
	if (instance == nullptr)
		instance = new ScoreManager();

	return instance;
}

void ScoreManager::addPoints(const unsigned int pPoints, const PLAYER_NUM pPlayer) {
	switch (pPlayer) {
		case(PLAYER_1):
			score_player_1 += pPoints;
			break;
		case(PLAYER_2):
			score_player_2 += pPoints;
			break;
	}
}

unsigned int ScoreManager::getScore(const PLAYER_NUM pPlayer) const {
		switch (pPlayer) {
			case PLAYER_1:
				return score_player_1;
			case PLAYER_2:
				return score_player_2;
		}

		return 0;
}
