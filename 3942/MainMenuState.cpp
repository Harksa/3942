#include "TextureManager.h"
#include "Game.h"
#include "MenuButton.h"
#include "PlayState.h"
#include "MainMenuState.h"
#include "StateParser.h"
#include "Background.h"

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
	Game::Instance()->getStateMachine()->changeState(new PlayState());
}

void MainMenuState::exitFromMenu() {
	Game::Instance()->quit();
}


bool MainMenuState::onEnter() {
	StateParser::parseState("ressources/test.xml", menuID, &_gameObjects, &_textureIDList);

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
	background->clean();

	for (auto game_object : _gameObjects) {
		game_object->clean();
	}

	_gameObjects.clear();

	for (const auto& i : _textureIDList) {
		TextureManager::Instance()->clearFromTextureMap(i);
	}

	return true;
}
