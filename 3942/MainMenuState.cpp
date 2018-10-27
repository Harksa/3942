#include "MainMenuState.h"
#include "TextureManager.h"
#include "Game.h"
#include "StateParser.h"
#include "StateChangeAsker.h"
#include "MenuButton.h"
#include "GameParameters.h"

const std::string MainMenuState::menuID = "MENU";

void MainMenuState::update() {
	if(!_gameObjects.empty()) {
		for (auto& _gameObject : _gameObjects) {
			if(_gameObject != nullptr) {
				_gameObject->update();
			}
		}
	}
}

void MainMenuState::render() {
	background.draw();
	for (auto game_object : _gameObjects) {
		game_object->draw();
	}
}

void MainMenuState::menuToPlay() {
	GameParameters::setMulti(false);
	StateChangeAsker::askToChange(CHOOSE_CONTROLS);
}

void MainMenuState::menuToOptions() {
	StateChangeAsker::askToChange(OPTIONS);
}


void MainMenuState::exitFromMenu() {
	Game::Instance()->quit();
}


bool MainMenuState::onEnter() {
	StateParser::parseState("ressources/states.xml", menuID, &_gameObjects, &_textureIDList);

	background.load("Textures/Backgrounds/MainMenu.png", "MainMenu");

	_callbacks.push_back(menuToPlay);
	_callbacks.push_back(menuToHighScores);
	_callbacks.push_back(menuToOptions);
	_callbacks.push_back(exitFromMenu);

	setCallbacks(_callbacks);

	is_loaded = true;

	return true;
}

bool MainMenuState::onExit() {
	is_exiting = true;

	clearState();

	return true;
}

std::string MainMenuState::getStateID() const { return menuID; }

void MainMenuState::menuToHighScores() {}
