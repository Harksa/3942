#include "UIManager.h"
#include "GameParameters.h"
#include "ScoreManager.h"
#include "FontManager.h"
#include "InputHandler.h"
#include "StateChangeAsker.h"

UIManager * UIManager::instance{nullptr};

UIManager* UIManager::Instance() {
	if (instance == nullptr)
		instance = new UIManager();

	return instance;
}

void UIManager::init() {
	FontManager::Instance()->createFont("TexWork", "Fonts/TEXWORK.ttf", 20, {255,255,255,255});

	text_rect.x = 0;
	text_rect.w = GameParameters::getGameWidth();

	text_rect.y = static_cast<int>(GameParameters::getGameHeight() * 0.45f);
	text_rect.h = 20;

	start_text_rect = text_rect;
	start_text_rect.y += 30;
}

void UIManager::update() {
	timer++;
}

void UIManager::draw() const {
	
	if(timer <= enter_game_timer) {
		FontManager::Instance()->drawBoxAlign("TexWork", text_rect, FC_ALIGN_CENTER, "Level " + std::to_string(StateChangeAsker::getCurrentLevel()));

		if(timer >= enter_game_timer * 0.5f)
			FontManager::Instance()->drawBoxAlign("TexWork", start_text_rect, FC_ALIGN_CENTER, "Start");
	}

	if(!InputHandler::areNumberOfJoysticksEgalsToNumberOfPlayersUsingJoysticks()) {
		FontManager::Instance()->drawBoxAlign("TexWork", text_rect, FC_ALIGN_CENTER, "Reconnectez la manette");
	}

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

bool UIManager::canStartGame() const {
	return timer >= enter_game_timer;
}
