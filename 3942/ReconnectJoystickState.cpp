#include "ReconnectJoystickState.h"
#include <SDL2/SDL_ttf.h>
#include "Game.h"
#include "GameParameters.h"

const std::string ReconnectJoystickState::RECONNECT_STATE_ID = "RECONNECTE_STATE";

void ReconnectJoystickState::update() {
	if(InputHandler::getNumberOfJoysticks() == 2) {
		StateChangeAsker::askForPopBack();
	}
}

void ReconnectJoystickState::render() {
	FC_DrawAlign(fc_font, Game::Instance()->getRenderer(),  GameParameters::getGameWidth() * 0.5f, GameParameters::getGameHeight() * 0.5f, FC_ALIGN_CENTER, "Reconnectez la manette"); 
}

bool ReconnectJoystickState::onEnter() {
	fc_font = FC_CreateFont();
	FC_LoadFont(fc_font, Game::Instance()->getRenderer(), "Fonts/TEXWORK.ttf", 20, FC_MakeColor(255,255,255,255), TTF_STYLE_NORMAL);
	return true;
}

bool ReconnectJoystickState::onExit() {
	FC_FreeFont(fc_font);
	return false;
}
