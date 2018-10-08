#include "PlayState.h"
#include "TextureManager.h"
#include "Player.h"
#include "InputHandler.h"
#include "StateParser.h"
#include "CollisionManager.h"
#include "StateChangeAsker.h"
#include "SoundManager.h"
#include "UIManager.h"
#include "PlayerManager.h"
#include "GameParameters.h"

const std::string PlayState::playID = "PLAY";

void PlayState::update() {
	if(is_loaded) {
		//Check mort joueurs
		if(PlayerManager::Instance()->areAllPlayersDead()) {
			StateChangeAsker::askToChange(GAME_OVER);
			return;
		}

		//Check joysticks
		if(GameParameters::isTwoPlayer()) {
			if(!GameParameters::isPlayerUsingKeyboard(0) && !GameParameters::isPlayerUsingKeyboard(1) && InputHandler::getNumberOfJoysticks() != 2 ||
			   (!GameParameters::isPlayerUsingKeyboard(0) && GameParameters::isPlayerUsingKeyboard(1) ||
			   GameParameters::isPlayerUsingKeyboard(0) && !GameParameters::isPlayerUsingKeyboard(1)) && InputHandler::getNumberOfJoysticks() < 1) {
				StateChangeAsker::askToPush(RECONNECT_JOYSTICK);
				return;
			}
		} else if (!GameParameters::isPlayerUsingKeyboard(0) && InputHandler::getNumberOfJoysticks() < 1) {
			StateChangeAsker::askToPush(RECONNECT_JOYSTICK);
			return;
		}

		//Check pause
		if(InputHandler::isKeyDown(SDL_SCANCODE_ESCAPE)) {
			StateChangeAsker::askToPush(PAUSE);
			return;
		}

		CollisionManager::checkCollisionEnemyWithPlayerBullets(_gameObjects);

		for (auto& player : *PlayerManager::Instance()->getPlayers()) {
			CollisionManager::checkCollisionPlayerWithEnemyBullets(player);
			CollisionManager::checkCollisionsPlayerAgainstEnemies(player, _gameObjects);
		}

		waveUpdate();

		PlayerManager::Instance()->update();

		if(!_gameObjects.empty()) {
			for (auto game_object : _gameObjects) {
				if(!game_object->isDead())
					game_object->update();
			}
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

		PlayerManager::Instance()->render();

		if(!_gameObjects.empty()) {
			for (auto game_object : _gameObjects) {
				if(!game_object->isDead())
					game_object->draw();
			}
		}

		UIManager::Instance()->draw();
	}
}

bool PlayState::onEnter() {

	StateParser::parseState("ressources/states.xml", playID, &_gameObjects, &_textureIDList);
	WaveGenerator::parseWave("Levels/Level1.xml", &enemy_spaw_informations);

	SoundManager::load("Sons/laser01.wav", "PlayerLaser", SOUND_SFX);

	background = new Background();
	background->load("Textures/Backgrounds/starBackground.png", "stars", 0.6f);

	PlayerManager::Instance()->init();
	BulletManager::Instance()->init();
	UIManager::Instance()->init();

	is_loaded = true;

	return true;
}

bool PlayState::onExit() {
	clearState();

	UIManager::Instance()->clear();
	PlayerManager::Instance()->clear();
	BulletManager::Instance()->clear();

	return true;
}

void PlayState::waveUpdate() {
	timer++;

	if(encouter < enemy_spaw_informations.size()) 
		if(enemy_spaw_informations[encouter].timer == timer) {
			GameObject * gameObject = GameObjectFactory::Instance()->create(enemy_spaw_informations[encouter].type);
			LoadParameters * parameters = new LoadParameters(enemy_spaw_informations[encouter].spawn_x, enemy_spaw_informations[encouter].spawn_y, enemy_spaw_informations[encouter].textureID);
			gameObject->load(parameters);
			delete parameters;

			static_cast<Enemy*>(gameObject)->setPoints(enemy_spaw_informations[encouter].points);
			static_cast<Enemy*>(gameObject)->setHealth(enemy_spaw_informations[encouter].health);

			_gameObjects.push_back(gameObject);

			encouter++;
		}
	
}


