#include "MainMenuState.h"
#include "Game.h"
#include "StateParser.h"
#include "StateChangeAsker.h"
#include "GameParameters.h"

const std::string MainMenuState::menu_id = "MENU";

void MainMenuState::update() {
	if(!game_objects.empty()) {
		for (auto& _gameObject : game_objects) {
			if(_gameObject != nullptr) {
				_gameObject->update();
			}
		}
	}
}

void MainMenuState::render() {
	background.draw();
	for (auto game_object : game_objects) {
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
	StateParser::parseState("ressources/states.xml", menu_id, &game_objects, &texture_id_list);

	background.load("Textures/Backgrounds/MainMenu.png", "MainMenu");

	_callbacks.push_back(menuToPlay);
	_callbacks.push_back(menuToHighScores);
	_callbacks.push_back(menuToOptions);
	_callbacks.push_back(exitFromMenu);

	setCallbacks(_callbacks);

	SoundManager::load("Musics/Space Cadet.ogg", "Main Menu Music", SOUND_MUSIC);
	SoundManager::playMusic("Main Menu Music");

	is_loaded = true;

	return true;
}

bool MainMenuState::onExit() {
	is_exiting = true;

	clearState();

	return true;
}

std::string MainMenuState::getStateID() const { return menu_id; }

void MainMenuState::menuToHighScores() {}
