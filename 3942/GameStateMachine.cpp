#include "GameStateMachine.h"
#include "PlayState.h"
#include "MainMenuState.h"
#include "PauseState.h"
#include "GameOverState.h"
#include "ReconnectJoystickState.h"
#include "ChooseControlState.h"
#include "OptionsState.h"

void GameStateMachine::createState(const StateChoice choice) {
	switch(choice) {
		case MAIN_MENU:
			_gameStates.push_back(std::make_shared<MainMenuState>());
			break;
		case OPTIONS:
			_gameStates.push_back(std::make_shared<OptionsState>());
			break;
		case CHOOSE_CONTROLS:
			_gameStates.push_back(std::make_shared<ChooseControlState>());
			break;
		case PLAY:
			_gameStates.push_back(std::make_shared<PlayState>());
			break;
		case PAUSE:
			_gameStates.push_back(std::make_shared<PauseState>());
			break;
		case GAME_OVER:
			_gameStates.push_back(std::make_shared<GameOverState>());
			break;
		case RECONNECT_JOYSTICK:
			_gameStates.push_back(std::make_shared<ReconnectJoystickState>());
			break;
		default:
			_gameStates.push_back(std::make_shared<MainMenuState>());
			break;
	}

}

void GameStateMachine::pushState(const StateChoice choice) {
	createState(choice);
	_gameStates.back()->onEnter();
}

void GameStateMachine::changeState(const StateChoice choice) {
	if (!_gameStates.empty()) {
		_gameStates.back()->onExit();
		_gameStates.back() = nullptr;
		_gameStates.pop_back();
	}

	createState(choice);
	_gameStates.back()->onEnter();
}

void GameStateMachine::popState() {
	if (!_gameStates.empty()) {
		_gameStates.back()->onExit();
		_gameStates.back() = nullptr;
		_gameStates.pop_back();
	}
}

void GameStateMachine::update() {
	if(!_gameStates.empty())
		_gameStates.back()->update();
}

void GameStateMachine::render() {
	if(!_gameStates.empty())
		_gameStates.back()->render();
}

