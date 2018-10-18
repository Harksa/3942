#include "ChooseControlState.h"
#include "StateParser.h"
#include "GameParameters.h"
#include "InputHandler.h"
#include "StateChangeAsker.h"


std::string ChooseControlState::ControlChooseStateID{"CHOOSE_CONTROLS"};

GameObject * ChooseControlState::ag_controls_player1{nullptr};
GameObject * ChooseControlState::ag_controls_player2{nullptr};
Player2Choice ChooseControlState::player2_choice{NO_PLAYER2};

bool ChooseControlState::onEnter() {
	StateParser::parseState("ressources/states.xml", ControlChooseStateID, &_gameObjects, &_textureIDList);

	background = new Background();
	background->load("Textures/Backgrounds/SelectControls.png", "SelectControls");

	FontManager::Instance()->createFont("TexWork", "Fonts/TEXWORK.ttf", 20, {255,255,255,255});

	bool player1spritedone = false;

	for (auto game_object : _gameObjects) {
		if(dynamic_cast<AnimatedGraphic *>(game_object) != nullptr) {
			if(!player1spritedone) {
				ag_controls_player1 = game_object;
				player1spritedone = true;
			} else {
				ag_controls_player2 = game_object;
				break;
			}

		}
	}

	rect1.x = 50; rect1.y = 500;
	rect1.h = 35; rect1.w = 225;

	rect2.x = 350; rect2.y = 500;
	rect2.h = 35; rect2.w = 225;

	_callbacks.push_back(buttonChoicePlayer1);
	_callbacks.push_back(buttonChoiceLeftPlayer2);
	_callbacks.push_back(buttonChoiceRightPlayer2);
	_callbacks.push_back(enterPlayMode);

	setCallbacks(_callbacks);

	is_loaded = true;

	return true;
}


bool ChooseControlState::onExit() {
	clearState();

	FontManager::Instance()->clear();

	return true;
}

void ChooseControlState::render() {

	background->draw();

	if(!GameParameters::isPlayerUsingKeyboard(PLAYER_1) && InputHandler::getNumberOfJoysticks() < 1) {
		FontManager::Instance()->drawBoxAlign("TexWork", rect1, FC_ALIGN_CENTER, "Branchez une manette");
	}

	if(player2_choice == GAMEPAD && InputHandler::getNumberOfJoysticks() < 2) {
		FontManager::Instance()->drawBoxAlign("TexWork", rect2, FC_ALIGN_CENTER, "Branchez une manette");
	}

	if(!_gameObjects.empty()) {
		for (auto game_object : _gameObjects) {
			game_object->draw();
		}
	}
}

void ChooseControlState::update() {
	if(!_gameObjects.empty()) {
		for (auto game_object : _gameObjects) {
			game_object->update();
		}
	}
}

void ChooseControlState::buttonChoicePlayer1() {
	if(GameParameters::isPlayerUsingKeyboard(PLAYER_1))
		ag_controls_player1->getSprite()->changeTextureID("gamepad");
	else
		ag_controls_player1->getSprite()->changeTextureID("keyboard");

	GameParameters::setPlayerUsingKeyboard(0, !GameParameters::isPlayerUsingKeyboard(PLAYER_1));
}

void ChooseControlState::buttonChoiceLeftPlayer2() {
	player2_choice = Player2Choice((player2_choice + 2) % 3);
	handlePlayer2Choice();
}


void ChooseControlState::buttonChoiceRightPlayer2() {
	player2_choice = Player2Choice((player2_choice + 1) % 3);
	handlePlayer2Choice();
}

void ChooseControlState::handlePlayer2Choice() {

	switch(player2_choice) {
		case NO_PLAYER2:
			ag_controls_player2->getSprite()->changeTextureID("cross");
			break;
		case KEYBOARD:
			ag_controls_player2->getSprite()->changeTextureID("keyboard");
			break;
		case GAMEPAD:
			ag_controls_player2->getSprite()->changeTextureID("gamepad");
			break;
	}

	GameParameters::setMulti(player2_choice != NO_PLAYER2);

	GameParameters::setPlayerUsingKeyboard(1, player2_choice == KEYBOARD);
}


void ChooseControlState::enterPlayMode() {
	StateChangeAsker::askToChange(PLAY);
}
