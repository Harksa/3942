#include "PlayState.h"
#include "TextureManager.h"
#include "Game.h"
#include "Player.h"
#include "InputHandler.h"
#include "PauseState.h"
#include "Enemy.h"
#include "GameOverState.h"
#include "StateParser.h"
#include "LevelParser.h"

const std::string PlayState::playID = "PLAY";

void PlayState::update() {
	if(InputHandler::Instance()->isKeyDown(SDL_SCANCODE_ESCAPE)) {
		Game::Instance()->getStateMachine()->pushState(new PauseState());
		return;
	}

	for (auto game_object : _gameObjects) {
		game_object->update();
	}

}

void PlayState::render() {
	for (auto game_object : _gameObjects) {
		game_object->draw();
	}
}

bool PlayState::onEnter() {

	StateParser stateParser;
	stateParser.parseState("ressources/test.xml", playID, &_gameObjects, &_textureIDList);

	return true;
}

bool PlayState::onExit() {

	for (auto game_object : _gameObjects) {
		game_object->clean();
	}

	_gameObjects.clear();

	for (const auto& i : _textureIDList) {
		TextureManager::Instance()->clearFromTextureMap(i);
	}

	return true;
}
