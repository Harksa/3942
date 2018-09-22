#include "UIManager.h"
#include <string>
#include "Game.h"
#include "GameParameters.h"

UIManager * UIManager::instance = nullptr;

void UIManager::init() {
	TTF_Init();

	font = TTF_OpenFont("Fonts/TEXWORK.ttf", 18);

	if(font == nullptr) {
		std::cout << "sale bite !!!!111";
	}

	messagePosition.x = 15;
	messagePosition.y = GameParameters::getGameHeight() - 35;
	messagePosition.h = 20;
	messagePosition.w = 100;

	updateRenderer();
}

void UIManager::increaseScore(unsigned int points) {
	score += points;
	updateRenderer();
}

void UIManager::updateRenderer() {
	std::string scoreString = "Score : " + std::to_string(score);
	surfaceMessage = TTF_RenderText_Solid(font, scoreString.c_str(), {255, 255, 255, 0});
	textureMessage = SDL_CreateTextureFromSurface(Game::Instance()->getRenderer(), surfaceMessage);
}

void UIManager::draw() const {
	SDL_RenderCopy(Game::Instance()->getRenderer(), textureMessage, nullptr, &messagePosition);
}

void UIManager::clean() const {
	SDL_FreeSurface(surfaceMessage);
	SDL_DestroyTexture(textureMessage);
	TTF_CloseFont(font);
	TTF_Quit();
}
