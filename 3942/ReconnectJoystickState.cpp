#include "ReconnectJoystickState.h"
#include <SDL2/SDL_ttf.h>
#include "Game.h"
#include "GameParameters.h"

const std::string ReconnectJoystickState::RECONNECT_STATE_ID = "RECONNECTE_STATE";

void ReconnectJoystickState::update() {
		if(GameParameters::isTwoPlayer()) {
			if(!GameParameters::isPlayerUsingKeyboard(0) && !GameParameters::isPlayerUsingKeyboard(1) && InputHandler::getNumberOfJoysticks() == 2 ||
			   (!GameParameters::isPlayerUsingKeyboard(0) && GameParameters::isPlayerUsingKeyboard(1) ||
			   GameParameters::isPlayerUsingKeyboard(0) && !GameParameters::isPlayerUsingKeyboard(1)) && InputHandler::getNumberOfJoysticks() >= 1) {
				StateChangeAsker::askForPopBack();
				return;
			}
		} else if (!GameParameters::isPlayerUsingKeyboard(0) && InputHandler::getNumberOfJoysticks() < 1) {
			StateChangeAsker::askForPopBack();
			return;
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
