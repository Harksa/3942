#include "GameOverState.h"
#include "Game.h"
#include "MainMenuState.h"
#include "PlayState.h"
#include "MenuButton.h"
#include "StateParser.h"

class StateParser;
const std::string GameOverState::gameOverID = "GAMEOVER";

void GameOverState::_gameOverToMain() {
	Game::Instance()->getStateMachine()->changeState(new MainMenuState());
}

void GameOverState::_restartPlay() {
	Game::Instance()->getStateMachine()->changeState(new PlayState());
}

bool GameOverState::onEnter() {
	StateParser stateParser;
	stateParser.parseState("ressources/test.xml", gameOverID, &_gameObjects, &_textureIDList);

	_callbacks.push_back(_gameOverToMain);
	_callbacks.push_back(_restartPlay);

	setCallbacks(_callbacks);

	return true;
}

bool GameOverState::onExit() {
	for (auto game_object : _gameObjects) {
		game_object->clean();
	}

	_gameObjects.clear();

	for (const auto& i : _textureIDList) {
		TextureManager::Instance()->clearFromTextureMap(i);
	}

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
