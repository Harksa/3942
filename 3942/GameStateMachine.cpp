#include "GameStateMachine.h"
#include "PlayState.h"
#include "MainMenuState.h"
#include "PauseState.h"
#include "GameOverState.h"
#include "ReconnectJoystickState.h"

void GameStateMachine::createState(StateChoice choice) {
	switch(choice) {
		case MAIN_MENU:
			_gameStates.push_back(std::make_shared<MainMenuState>());
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

void GameStateMachine::pushState(StateChoice choice) {
	createState(choice);
	_gameStates.back()->onEnter();
}

void GameStateMachine::changeState(StateChoice choice) {
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

