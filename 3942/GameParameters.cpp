#include "GameParameters.h"
#include <filesystem>
#include <iostream>

namespace fs = std::experimental::filesystem;

int GameParameters::game_height{0};

int GameParameters::game_width{0};

bool GameParameters::two_player{false};

bool GameParameters::isUsingKeyboard[2] {true,true};

unsigned int GameParameters::number_of_levels{0};

void GameParameters::countNumberOfLevels(const std::string& pFolderPath) {
	if(!fs::exists(pFolderPath)) {
		std::cout << "ERROR::GAMEPARAMETERS::COUNTNUMBEROFLEVELS:: Directory " << pFolderPath << " doesn't exist." << std::endl;
		return;
	}

	for(auto &it : fs::directory_iterator(pFolderPath)) {
		number_of_levels++;
	}
}

int GameParameters::getGameWidth() { return game_width; }

int GameParameters::getGameHeight() { return game_height; }

void GameParameters::setMulti(bool newValue) { two_player = newValue; }

bool GameParameters::isTwoPlayer() { return two_player; }

bool GameParameters::isPlayerUsingKeyboard(PLAYER_NUM playerID) { return isUsingKeyboard[playerID]; }

void GameParameters::setPlayerUsingKeyboard(const int pPlayer, bool pValue) { isUsingKeyboard[pPlayer] = pValue; }

unsigned GameParameters::getTotalNumberOfLevels() { return number_of_levels; }
