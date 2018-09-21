#include "Background.h"
#include "TextureManager.h"
#include "GameParameters.h"

bool Background::load(const std::string& fileName, const std::string& id, const float speed) {
	movingSpeed = speed;
	backgroundID = id;
	offset = 0;
	return TextureManager::Instance()->load(fileName, id);
}

void Background::draw() {
	if(movingSpeed == 0)
		drawStatic();
	else
		drawMoving();
}

void Background::drawStatic() const {
	TextureManager::Instance()->draw(backgroundID, 0, 0, GameParameters::getGameWidth(), GameParameters::getGameHeight());
}

void Background::drawMoving() {
	TextureManager::Instance()->draw(backgroundID, 0, static_cast<int>(offset), GameParameters::getGameWidth(), GameParameters::getGameHeight());
	TextureManager::Instance()->draw(backgroundID, 0, static_cast<int>(offset) - GameParameters::getGameHeight(), GameParameters::getGameWidth(), GameParameters::getGameHeight());

	offset += movingSpeed;

	if(offset >= GameParameters::getGameHeight())
		offset = 0;
}

void Background::clean() const {
	TextureManager::Instance()->clearFromTextureMap(backgroundID);
}