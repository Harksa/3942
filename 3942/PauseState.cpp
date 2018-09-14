#include "PauseState.h"
#include "Game.h"
#include "MainMenuState.h"
#include "MenuButton.h"
#include "InputHandler.h"
#include "StateParser.h"

const std::string PauseState::pauseID = "PAUSE";

void PauseState::update() {
	if(InputHandler::isKeyDown(SDL_SCANCODE_ESCAPE)) {
		Game::Instance()->getStateMachine()->popState();
		return;
	}

	if(!_gameObjects.empty())
		for (auto game_object : _gameObjects) {
			game_object->update();
		}
}

void PauseState::render() {
	for (auto game_object : _gameObjects) {
		game_object->draw();
	}
}

bool PauseState::onEnter() {
	StateParser::parseState("ressources/test.xml", pauseID, &_gameObjects, &_textureIDList);

	_callbacks.push_back(pauseToMain);
	_callbacks.push_back(resumePlay);

	setCallbacks(_callbacks);

	return true;
}


void PauseState::setCallbacks(const std::vector<Callback>& callbacks) {
	for (auto& _gameObject : _gameObjects) {
		if(dynamic_cast<MenuButton*>(_gameObject)) {
			auto button = dynamic_cast<MenuButton*>(_gameObject);
			button->setCallback(callbacks[button->getCallbackID()]);
		}
	}
}


bool PauseState::onExit() {
	for (auto game_object : _gameObjects) {
		game_object->clean();
	}

	_gameObjects.clear();
	InputHandler::reset();

	return true;
}

std::string PauseState::getStateID() const {
	return std::string();
}

void PauseState::pauseToMain() {
	Game::Instance()->getStateMachine()->changeState(new MainMenuState());
}

void PauseState::resumePlay() {
	Game::Instance()->getStateMachine()->popState();
}

