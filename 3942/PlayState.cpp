#include "PlayState.h"

#include "BulletManager.h"
#include "CollisionManager.h"
#include "GameParameters.h"
#include "InputHandler.h"
#include "Player.h"
#include "PlayerManager.h"
#include "StateChangeAsker.h"
#include "StateParser.h"
#include "SoundManager.h"
#include "UIManager.h"

const std::string PlayState::play_id = "PLAY";

void PlayState::update() {

	player_manager.update();

	background.update();

	ui_manager.update();

	BulletManager::Instance()->update();

	//Check pause
	if(InputHandler::isKeyDown(SDL_SCANCODE_ESCAPE)) {
		StateChangeAsker::askToPush(PAUSE);
		return;
	}

	if(!ui_manager.canStartGame()) {
		game_objects[0]->getSprite()->setVisibility(true);
		return;
	} else {
		game_objects[0]->getSprite()->setVisibility(false);
	}

	//Check mort joueurs
	if(player_manager.doesAllPlayersDoesntHaveAnyRemainingLives()) {
		StateChangeAsker::askToChange(GAME_OVER);
		StateChangeAsker::setHasWon(false);
		return;
	}

	//Fin du niveau
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

	//Check joysticks
	if(!InputHandler::areNumberOfJoysticksEgalsToNumberOfPlayersUsingJoysticks()) {
		game_objects[0]->getSprite()->setVisibility(true);
		return;
	} else {
		game_objects[0]->getSprite()->setVisibility(false);
	}

	//Gestion des collisions
	CollisionManager::checkCollisionEnemyWithPlayerBullets(game_objects);

	for (auto player : player_manager.getPlayers()) {
		CollisionManager::checkCollisionPlayerWithEnemyBullets(player);
		CollisionManager::checkCollisionsPlayerAgainstEnemies(player, game_objects);
	}

	waveUpdate();

	//MAJ des gameobjects
	if(!game_objects.empty()) {
		for(auto game_object = game_objects.begin() ; game_object != game_objects.end() ; ) {
			if(!(*game_object)->isDead()) {
				(*game_object)->update();
				++game_object;
			} else {
				(*game_object)->clean();
				delete *game_object;
				game_object = game_objects.erase(game_object);
			}
		}
	}

}

void PlayState::render() {
	background.draw();

	BulletManager::Instance()->render();

	player_manager.render();

	if(!game_objects.empty()) {
		for (unsigned int i = 1 ; i < game_objects.size(); i++){
			if(!game_objects[i]->isDead()) {
				game_objects[i]->draw();
			}
		}
	}

	game_objects[0]->draw(); // Draw uniquement si isVisible = true donc pas besoin de if

	ui_manager.draw();
}


bool PlayState::onEnter() {

	StateParser::parseState("ressources/states.xml", play_id, &game_objects, &texture_id_list);

	game_objects[0]->getSprite()->setVisibility(false); //Fond gris

	WaveGenerator::parseWave("Levels/Level" + std::to_string(StateChangeAsker::getCurrentLevel()) + ".xml", &enemy_spaw_informations);

	SoundManager::load("Sons/laser01.wav", "PlayerLaser", SOUND_SFX);

	background.load("Textures/Backgrounds/starBackground.png", "stars", 0.6f);

	player_manager.init();
	ui_manager.init();
	BulletManager::Instance()->init();

	is_loaded = true;

	return true;
}

bool PlayState::onExit() {
	is_exiting = true;

	clearState();

	ui_manager.clear();
	player_manager.clear();

	BulletManager::Instance()->clear();

	return true;
}

void PlayState::waveUpdate() {
	timer++;

	if(encouter < enemy_spaw_informations.size()) 
		if(enemy_spaw_informations[encouter].timer == timer) {
			GameObject * gameObject = GameObjectFactory::Instance()->create(enemy_spaw_informations[encouter].type);
			LoadParameters * parameters = new LoadParameters(enemy_spaw_informations[encouter].spawn_x, enemy_spaw_informations[encouter].spawn_y, enemy_spaw_informations[encouter].texture_id);
			gameObject->load(parameters);
			delete parameters;

			static_cast<Enemy*>(gameObject)->setPoints(enemy_spaw_informations[encouter].points);
			static_cast<Enemy*>(gameObject)->setHealth(enemy_spaw_informations[encouter].health);

			game_objects.push_back(gameObject);

			encouter++;
		}
	
}

bool PlayState::isLevelFinished() {
	if(encouter == enemy_spaw_informations.size()) {
		for (auto game_object : game_objects) {
			if(dynamic_cast<Enemy*>(game_object) != nullptr) {
				return false;
			}
		}

		return true;
	}

	return false;
}

std::string PlayState::getStateID() const { return play_id; }
