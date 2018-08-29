#include "GameStateMachine.h"

void GameStateMachine::pushState(GameState* state) {
	_gameStates.push_back(state);
	_gameStates.back()->onEnter();
}

void GameStateMachine::changeState(GameState* state) {
	if (!_gameStates.empty()) {
		if (_gameStates.back()->getStateID() == state->getStateID()) {
			return;
		}
		_gameStates.back()->onExit();
		_gameStates.pop_back();
	}
		
	state->onEnter();
	_gameStates.push_back(state);
}

void GameStateMachine::popState() {
	if (!_gameStates.empty()) {
		if (_gameStates.back()->onExit()) {
			delete _gameStates.back();
			_gameStates.pop_back();
		}
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

