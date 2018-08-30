#pragma once
#include <string>

enum spritesIDList {
	ENEMY_SPRITE
};

std::string getSpriteName(spritesIDList sprite_ID) {
	switch (sprite_ID) {
		case ENEMY_SPRITE :
			return "Enemy";
		default :
			return "Non existant sprite";
	}
}