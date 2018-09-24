#include "UIManager.h"
#include "Game.h"
#include "GameParameters.h"
#include "ScoreManager.h"

UIManager * UIManager::instance = nullptr;

void UIManager::init() {
	fc_font = FC_CreateFont();
	FC_LoadFont(fc_font, Game::Instance()->getRenderer(), "Fonts/TEXWORK.ttf", 20, FC_MakeColor(255,255,255,255), TTF_STYLE_NORMAL);
}

void UIManager::draw() const {
	if(!GameParameters::isTwoPlayer()) {
		FC_Draw(fc_font, Game::Instance()->getRenderer(), 15.0f, static_cast<float> (GameParameters::getGameHeight() - 35), "Score : %d", ScoreManager::Instance()->getScore());
	} else {
		FC_Draw(fc_font, Game::Instance()->getRenderer(), 15.0f, GameParameters::getGameHeight() - 35.0f, "Score : %d", ScoreManager::Instance()->getScore(PLAYER_1));
		FC_DrawAlign(fc_font, Game::Instance()->getRenderer(), GameParameters::getGameWidth() - 15.0f, GameParameters::getGameHeight() - 35.0f, FC_ALIGN_RIGHT, "Score : %d", ScoreManager::Instance()->getScore(PLAYER_2));
	}
}

void UIManager::clear() const {
	FC_FreeFont(fc_font);
}
