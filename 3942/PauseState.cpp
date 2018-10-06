#include "PauseState.h"
#include "MenuButton.h"
#include "InputHandler.h"
#include "StateParser.h"
#include "StateChangeAsker.h"

const std::string PauseState::pauseID = "PAUSE";

void PauseState::update() {
	if(InputHandler::isKeyDown(SDL_SCANCODE_ESCAPE)) {
		StateChangeAsker::askForPopBack();
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
	StateParser::parseState("ressources/states.xml", pauseID, &_gameObjects, &_textureIDList);

	_callbacks.push_back(pauseToMain);
	_callbacks.push_back(resumePlay);

	setCallbacks(_callbacks);

	return true;
}

bool PauseState::onExit() {
	clearState();

	InputHandler::reset();

	return true;
}

std::string PauseState::getStateID() const {
	return std::string();
}

void PauseState::pauseToMain() {
	StateChangeAsker::askToChange(MAIN_MENU);
}

void PauseState::resumePlay() {
	StateChangeAsker::askForPopBack();
}

