#include "PlayState.h"
#include "TextureManager.h"
#include "Game.h"
#include "Player.h"
#include "InputHandler.h"
#include "PauseState.h"
#include "GameOverState.h"
#include "StateParser.h"
#include "CollisionManager.h"

const std::string PlayState::playID = "PLAY";

void PlayState::update() {
	if(is_loaded) {
		if(InputHandler::isKeyDown(SDL_SCANCODE_ESCAPE)) {
			Game::Instance()->getStateMachine()->pushState(new PauseState());
			return;
		}

		CollisionManager::checkCollisionEnemyWithPlayerBullets(_gameObjects);
		CollisionManager::checkCollisionPlayerWithEnemyBullets(player);
		CollisionManager::checkCollisionsPlayerAgainstEnemies(player, _gameObjects);

		waveUpdate();

		player->update();

		for (auto game_object : _gameObjects) {
			if(!game_object->isDead())
				game_object->update();
		}

		BulletManager::Instance()->update();

		std::vector<int> toBeDeleted;
		for(unsigned int i = 0 ; i < _gameObjects.size() ; i++) {
			if(_gameObjects[i]->isDead())
				toBeDeleted.push_back(i);
		}

		for (auto to_be_deleted : toBeDeleted) {
			_gameObjects[to_be_deleted]->clean();
			_gameObjects.erase(_gameObjects.begin() + to_be_deleted);
		}

		toBeDeleted.clear();
	}
}

void PlayState::render() {
	if(is_loaded) {
		background->draw();

		BulletManager::Instance()->render();

		player->draw();
		
		for (auto game_object : _gameObjects) {
			if(!game_object->isDead())
				game_object->draw();
		}
	}
}

bool PlayState::onEnter() {

	StateParser::parseState("ressources/test.xml", playID, &_gameObjects, &_textureIDList);
	WaveGenerator::parseWave("ressources/Level1.xml", &enemy_spaw_informations);

	SoundManager::load("Sons/laser01.wav", "PlayerLaser", SOUND_SFX);

	background = new Background();
	background->load("Textures/starBackground.png", "stars", 0.5f);

	player = new Player();
	player->load(new LoadParameters(Game::Instance()->getGameWidth() * 0.5f - TextureManager::Instance()->getTextureInformationsFromID("bob")->width * 0.5f, //Milieu de l'écran
									static_cast<int> (Game::Instance()->getGameHeight()) * 0.8f,
									"bob"));

	is_loaded = true;

	return true;
}

bool PlayState::onExit() {
	background->clean();

	player->clean();

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


