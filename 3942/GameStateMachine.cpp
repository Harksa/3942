#include "GameStateMachine.h"
#include "PlayState.h"
#include "MainMenuState.h"
#include "PauseState.h"
#include "GameOverState.h"
#include "ChooseControlState.h"
#include "OptionsState.h"

void GameStateMachine::createState(const StateChoice pChoice) {
	switch(pChoice) {
		case MAIN_MENU:
			game_states.push_back(std::make_shared<MainMenuState>());
			break;
		case OPTIONS:
			game_states.push_back(std::make_shared<OptionsState>());
			break;
		case CHOOSE_CONTROLS:
			game_states.push_back(std::make_shared<ChooseControlState>());
			break;
		case PLAY:
			game_states.push_back(std::make_shared<PlayState>());
			break;
		case PAUSE:
			game_states.push_back(std::make_shared<PauseState>());
			break;
		case GAME_OVER:
			game_states.push_back(std::make_shared<GameOverState>());
			break;
		default:
			game_states.push_back(std::make_shared<MainMenuState>());
			break;
	}

}

void GameStateMachine::pushState(const StateChoice pChoice) {
	createState(pChoice);
	game_states.back()->onEnter();
}

void GameStateMachine::changeState(const StateChoice pChoice) {
	if (!game_states.empty()) {
		game_states.back()->onExit();
		game_states.back() = nullptr;
		game_states.pop_back();
	}

	createState(pChoice);
	game_states.back()->onEnter();
}

void GameStateMachine::popState() {
	if (!game_states.empty()) {
		game_states.back()->onExit();
		game_states.back() = nullptr;
		game_states.pop_back();
	}
}

void GameStateMachine::update() {
	if(!game_states.empty())
		if(game_states.back()->isLoaded() && !game_states.back()->isExiting())
			game_states.back()->update();
}

void GameStateMachine::render() {
	if(!game_states.empty())
		if(game_states.back()->isLoaded() && !game_states.back()->isExiting())
			game_states.back()->render();
}

GameStateMachine::~GameStateMachine() {
	for (auto game_state : game_states) {
		game_state = nullptr;
	}
}
