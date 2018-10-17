#include "UIManager.h"
#include "GameParameters.h"
#include "ScoreManager.h"
#include "FontManager.h"

UIManager * UIManager::instance{nullptr};

void UIManager::init() {
	FontManager::Instance()->createFont("TexWork", "Fonts/TEXWORK.ttf", 20, {255,255,255,255});
}

void UIManager::draw() const {
	if(!GameParameters::isTwoPlayer()) {
		FontManager::Instance()->draw("TexWork", 15, GameParameters::getGameHeight() - 35, "Score : " + std::to_string(ScoreManager::Instance()->getScore()));
	} else {
		FontManager::Instance()->draw("TexWork", 15, GameParameters::getGameHeight() - 35, "Score : " + std::to_string(ScoreManager::Instance()->getScore(PLAYER_1)));
		FontManager::Instance()->drawAlign("TexWork", GameParameters::getGameWidth() - 15, GameParameters::getGameHeight() - 35, FC_ALIGN_RIGHT, "Score : " + std::to_string(ScoreManager::Instance()->getScore(PLAYER_2)));
	}
}

void UIManager::clear() const {
	FontManager::Instance()->clear();
}
