#include "GameParameters.h"
#include <filesystem>
#include <iostream>

namespace fs = std::experimental::filesystem;

int GameParameters::game_height{0};

int GameParameters::game_width{0};

bool GameParameters::two_player{false};

bool GameParameters::isUsingKeyboard[2] {true,true};

unsigned int GameParameters::number_of_levels{0};

void GameParameters::countNumberOfLevels(const std::string& folder_path) {
	if(!fs::exists(folder_path)) {
		std::cout << "ERROR::GAMEPARAMETERS::COUNTNUMBEROFLEVELS:: Directory " << folder_path << " doesn't exist." << std::endl;
		return;
	}

	for(auto &it : fs::directory_iterator(folder_path)) {
		number_of_levels++;
	}
}
