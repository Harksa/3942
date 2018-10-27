#include "Background.h"
#include "TextureManager.h"
#include "GameParameters.h"

bool Background::load(const std::string& fileName, const std::string& id, const float speed) {
	movingSpeed = speed;
	backgroundID = id;
	offset = 0;

	is_loaded = true;

	return TextureManager::Instance()->load(fileName, id);
}

void Background::draw() {
	if(movingSpeed == 0)
		drawStatic();
	else
		drawMoving();
}

void Background::update() {
	if(movingSpeed != 0) {
		offset += movingSpeed;

	if(offset >= GameParameters::getGameHeight())
		offset = 0;
	} else {
		std::cout << "INFORMATIONS::BACKGROUND::UPDATE::UPDATE ISN'T NEEDED IF MOVINGSPEED = 0 " << std::endl;
	}
}

void Background::drawStatic() const {
	TextureManager::Instance()->draw(backgroundID, 0, 0, GameParameters::getGameWidth(), GameParameters::getGameHeight());
}

void Background::drawMoving() {
	TextureManager::Instance()->draw(backgroundID, 0, static_cast<int>(offset), GameParameters::getGameWidth(), GameParameters::getGameHeight());
	TextureManager::Instance()->draw(backgroundID, 0, static_cast<int>(offset) - GameParameters::getGameHeight(), GameParameters::getGameWidth(), GameParameters::getGameHeight());
}

void Background::clean() const {
	if(is_loaded)
		TextureManager::Instance()->clearFromTextureMap(backgroundID);
}