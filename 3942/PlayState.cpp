#include "PlayState.h"
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
	//Check mort joueurs
	if(PlayerManager::Instance()->doesAllPlayersDoesntHaveAnyRemainingLives()) {
		StateChangeAsker::askToChange(GAME_OVER);
		StateChangeAsker::setHasWon(false);
		return;
	}

	if(isLevelFinished()) {
		if(StateChangeAsker::getCurrentLevel() == GameParameters::getTotalNumberOfLevels()) {
			StateChangeAsker::askToChange(GAME_OVER);
			StateChangeAsker::setHasWon(true);
			return;
		} else {
			StateChangeAsker::askToChange(PLAY);
			StateChangeAsker::incrementeLevel();
			return;
		}
	}

	//Check pause
	if(InputHandler::isKeyDown(SDL_SCANCODE_ESCAPE)) {
		StateChangeAsker::askToPush(PAUSE);
		return;
	}

	//Check joysticks
	if(!InputHandler::areNumberOfJoysticksEgalsToNumberOfPlayersUsingJoysticks()) {
		_gameObjects[0]->getSprite()->setVisibility(true);
		return;
	} else {
		_gameObjects[0]->getSprite()->setVisibility(false);
	}

	background->update();

	CollisionManager::checkCollisionEnemyWithPlayerBullets(_gameObjects);

	for (auto& player : *PlayerManager::Instance()->getPlayers()) {
		CollisionManager::checkCollisionPlayerWithEnemyBullets(player);
		CollisionManager::checkCollisionsPlayerAgainstEnemies(player, _gameObjects);
	}

	waveUpdate();

	PlayerManager::Instance()->update();

	if(!_gameObjects.empty()) {
		for(auto game_object = _gameObjects.begin() ; game_object != _gameObjects.end() ; ) {
			if(!(*game_object)->isDead()) {
				(*game_object)->update();
				++game_object;
			} else {
				(*game_object)->clean();
				delete *game_object;
				game_object = _gameObjects.erase(game_object);
			}
		}
	}

	BulletManager::Instance()->update();

}

void PlayState::render() {
	background->draw();

	BulletManager::Instance()->render();

	PlayerManager::Instance()->render();

	if(!_gameObjects.empty()) {
		for (unsigned int i = 1 ; i < _gameObjects.size(); i++){
			if(!_gameObjects[i]->isDead()) {
				_gameObjects[i]->draw();
			}
		}
	}

	_gameObjects[0]->draw(); // Draw uniquement si isVisible = true donc pas besoin de if

	UIManager::Instance()->draw();
}


bool PlayState::onEnter() {

	StateParser::parseState("ressources/states.xml", playID, &_gameObjects, &_textureIDList);

	_gameObjects[0]->getSprite()->setVisibility(false); //Fond gris

	WaveGenerator::parseWave("Levels/Level" + std::to_string(StateChangeAsker::getCurrentLevel()) + ".xml", &enemy_spaw_informations);

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
	is_exiting = true;

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


bool PlayState::isLevelFinished() {
	if(encouter == enemy_spaw_informations.size()) {
		for (auto game_object : _gameObjects) {
			if(dynamic_cast<Enemy*>(game_object) != nullptr) {
				return false;
			}
		}

		return true;
	}

	return false;
}