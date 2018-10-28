#include "PauseState.h"

#include "InputHandler.h"
#include "StateChangeAsker.h"
#include "StateParser.h"

const std::string PauseState::pause_id = "PAUSE";

void PauseState::update() {
	if(InputHandler::isKeyDown(SDL_SCANCODE_ESCAPE)) {
		StateChangeAsker::askForPopBack();
		return;
	}

	if(!game_objects.empty())
		for (auto game_object : game_objects) {
			game_object->update();
		}
}

void PauseState::render() {
	for (auto game_object : game_objects) {
		game_object->draw();
	}
}

bool PauseState::onEnter() {
	StateParser::parseState("ressources/states.xml", pause_id, &game_objects, &texture_id_list);

	_callbacks.push_back(pauseToMain);
	_callbacks.push_back(resumePlay);

	setCallbacks(_callbacks);

	is_loaded = true;

	return true;
}

bool PauseState::onExit() {
	is_exiting = true;

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

