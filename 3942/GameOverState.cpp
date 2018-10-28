#include "GameOverState.h"
#include "StateParser.h"
#include "StateChangeAsker.h"

class StateParser;
const std::string GameOverState::game_over_id = "GAMEOVER";

void GameOverState::gameOverToMain() {
	StateChangeAsker::askToChange(MAIN_MENU);
}

void GameOverState::restartPlay() {
	StateChangeAsker::askToChange(PLAY);
}

bool GameOverState::onEnter() {
	StateParser::parseState("ressources/states.xml", game_over_id, &game_objects, &texture_id_list);

	_callbacks.push_back(gameOverToMain);
	_callbacks.push_back(restartPlay);

	setCallbacks(_callbacks);

	is_loaded = true;

	return true;
}

bool GameOverState::onExit() {
	is_exiting = true;

	clearState();

	return true;
}

void GameOverState::update() {
		if(!game_objects.empty()) {
			for (auto game_object : game_objects) {
				if(game_object != nullptr)
					game_object->update();
			}
		}
}

void GameOverState::render() {
	for(auto game_object : game_objects) {
		game_object->draw();
	}
}

std::string GameOverState::getStateID() const { return game_over_id; }
