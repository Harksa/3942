#include "Background.h"
#include "TextureManager.h"
#include "Game.h"

bool Background::load(const std::string& fileName, const std::string& id, const float speed) {
	movingSpeed = speed;
	backgroundID = id;
	offset = 0;
	return TextureManager::Instance()->load(fileName, id, Game::Instance()->getRenderer());
}

void Background::draw() {
	if(movingSpeed == 0)
		drawStatic();
	else
		drawMoving();
}

void Background::drawStatic() const {
	TextureManager::Instance()->draw(backgroundID, 0, 0, Game::Instance()->getGameWidth(), Game::Instance()->getGameHeight(), Game::Instance()->getRenderer());
}

void Background::drawMoving() {
	TextureManager::Instance()->draw(backgroundID, 0, static_cast<int>(offset), Game::Instance()->getGameWidth(), Game::Instance()->getGameHeight(), Game::Instance()->getRenderer());
	TextureManager::Instance()->draw(backgroundID, 0, static_cast<int>(offset) - Game::Instance()->getGameHeight(), Game::Instance()->getGameWidth(), Game::Instance()->getGameHeight(), Game::Instance()->getRenderer());

	offset += movingSpeed;

	if(offset >= Game::Instance()->getGameHeight())
		offset = 0;
}

void Background::clean() const {
	TextureManager::Instance()->clearFromTextureMap(backgroundID);
}