#include "MainMenuState.h"
#include "TextureManager.h"
#include "Game.h"
#include "StateParser.h"
#include "StateChangeAsker.h"
#include "MenuButton.h"

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
	background->draw();
	for (auto game_object : _gameObjects) {
		game_object->draw();
	}
}

void MainMenuState::menuToPlay() {
	StateChangeAsker::askToChange(PLAY);
}

void MainMenuState::exitFromMenu() {
	Game::Instance()->quit();
}


bool MainMenuState::onEnter() {
	StateParser::parseState("ressources/states.xml", menuID, &_gameObjects, &_textureIDList);

	background = new Background();
	background->load("Textures/starBackground.png", "Star", 0.5f);

	_callbacks.push_back(menuToPlay);
	_callbacks.push_back(exitFromMenu);

	setCallbacks(_callbacks);

	return true;
}

void MainMenuState::setCallbacks(const std::vector<Callback>& callbacks) {
	for (auto& _gameObject : _gameObjects) {
		if(dynamic_cast<MenuButton*>(_gameObject)) {
			auto button = dynamic_cast<MenuButton*>(_gameObject);
			button->setCallback(callbacks[button->getCallbackID()]);
		}
	}
}


bool MainMenuState::onExit() {
	clearState();

	return true;
}