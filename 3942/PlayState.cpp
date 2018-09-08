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

	waveUpdate();

	BulletManager::Instance()->update();
}

void PlayState::render() {
	background->draw();
	BulletManager::Instance()->render();
	
	for (auto game_object : _gameObjects) {
		game_object->draw();
	}

}

bool PlayState::onEnter() {

	StateParser::parseState("ressources/test.xml", playID, &_gameObjects, &_textureIDList);
	WaveGenerator::parseWave("ressources/Level1.xml", &enemy_spaw_informations);

	background = new Background();
	background->load("Textures/starBackground.png", "stars", 0.5f);

	return true;
}

bool PlayState::onExit() {
	background->clean();

	for (auto game_object : _gameObjects) {
		game_object->clean();
	}

	_gameObjects.clear();

	for (const auto& i : _textureIDList) {
		TextureManager::Instance()->clearFromTextureMap(i);
	}

	return true;
}

void PlayState::waveUpdate() {
	timer++;

	if(encouter < enemy_spaw_informations.size()) 
		if(enemy_spaw_informations[encouter]->timer == timer) {
			GameObject * gameObject = GameObjectFactory::Instance()->create(enemy_spaw_informations[encouter]->type);
			gameObject->load(new LoadParameters((enemy_spaw_informations[encouter]->spawn_x), (enemy_spaw_informations[encouter]->spawn_y), enemy_spaw_informations[encouter]->textureID));
			_gameObjects.push_back(gameObject);
			encouter++;
		}
	
}


