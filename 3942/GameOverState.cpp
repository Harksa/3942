#include "GameOverState.h"
#include "MenuButton.h"
#include "StateParser.h"
#include "StateChangeAsker.h"

class StateParser;
const std::string GameOverState::gameOverID = "GAMEOVER";

void GameOverState::_gameOverToMain() {
	StateChangeAsker::askToChange(MAIN_MENU);
}

void GameOverState::_restartPlay() {
	StateChangeAsker::askToChange(PLAY);
}

bool GameOverState::onEnter() {
	StateParser::parseState("ressources/states.xml", gameOverID, &_gameObjects, &_textureIDList);

	_callbacks.push_back(_gameOverToMain);
	_callbacks.push_back(_restartPlay);

	setCallbacks(_callbacks);

	return true;
}

bool GameOverState::onExit() {
	clearState();

	return true;
}

void GameOverState::setCallbacks(const std::vector<Callback>& callbacks) {
	for (auto& _gameObject : _gameObjects) {
		if(dynamic_cast<MenuButton*>(_gameObject)) {
			auto button = dynamic_cast<MenuButton*>(_gameObject);
			button->setCallback(callbacks[button->getCallbackID()]);
		}
	}
}

void GameOverState::update() {
		if(!_gameObjects.empty()) {
			for (auto game_object : _gameObjects) {
				if(game_object != nullptr)
					game_object->update();
			}
		}
}

void GameOverState::render() {
	for(auto game_object : _gameObjects) {
		game_object->draw();
	}
}
