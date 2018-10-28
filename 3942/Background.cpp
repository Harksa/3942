#include "Background.h"
#include "TextureManager.h"
#include "GameParameters.h"
#include <iostream>

bool Background::load(const std::string& pFileName, const std::string& pId, const float pSpeed) {
	moving_speed = pSpeed;
	background_id = pId;
	offset = 0;

	is_loaded = true;

	return TextureManager::Instance()->load(pFileName, pId);
}

void Background::draw() const {
	if(moving_speed == 0)
		drawStatic();
	else
		drawMoving();
}

void Background::update() {
	if(moving_speed != 0) {
		offset += moving_speed;

		if(offset >= GameParameters::getGameHeight())
			offset = 0;
	} else {
		std::cout << "INFORMATIONS::BACKGROUND::UPDATE::UPDATE ISN'T NEEDED IF MOVINGSPEED = 0 " << std::endl;
	}
}

void Background::drawStatic() const {
	TextureManager::Instance()->draw(background_id, 0, 0, GameParameters::getGameWidth(), GameParameters::getGameHeight());
}

void Background::drawMoving() const {
	TextureManager::Instance()->draw(background_id, 0, static_cast<int>(offset), GameParameters::getGameWidth(), GameParameters::getGameHeight());
	TextureManager::Instance()->draw(background_id, 0, static_cast<int>(offset) - GameParameters::getGameHeight(), GameParameters::getGameWidth(), GameParameters::getGameHeight());
}

void Background::clean() const {
	if(is_loaded)
		TextureManager::Instance()->clearFromTextureMap(background_id);
}