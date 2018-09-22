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
	FC_Draw(fc_font, Game::Instance()->getRenderer(), 15.0f, static_cast<float> (GameParameters::getGameHeight() - 35), "Score : %d", ScoreManager::Instance()->getScore());
}

void UIManager::clear() const {
	FC_FreeFont(fc_font);
}
