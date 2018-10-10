#include "PlayerManager.h"
#include "GameParameters.h"

PlayerManager * PlayerManager::instance = nullptr;

void PlayerManager::init() const {
	if(GameParameters::isTwoPlayer()) {

		Player * player1 = new Player(PLAYER_1), * player2 = new Player(PLAYER_2);

		if(!GameParameters::isPlayerUsingKeyboard(0) && !GameParameters::isPlayerUsingKeyboard(1)) {
			player1->setJoystickID(0);
			player2->setJoystickID(1);
		} else if (!GameParameters::isPlayerUsingKeyboard(0) && GameParameters::isPlayerUsingKeyboard(1)) {
			player1->setJoystickID(0);
		} else if (GameParameters::isPlayerUsingKeyboard(0) && !GameParameters::isPlayerUsingKeyboard(1)) {
			player2->setJoystickID(0);
		}

		LoadParameters * p = new LoadParameters(GameParameters::getGameWidth() * 0.25f - TextureManager::Instance()->getTextureInformationsFromID("Player1").width * 0.5f, //Milieu de l'écran
										static_cast<int> (GameParameters::getGameHeight()) * 0.8f,
										"Player1");

		player1->load(p);

		p = new LoadParameters(GameParameters::getGameWidth() * 0.75f - TextureManager::Instance()->getTextureInformationsFromID("Player2").width * 0.5f, //Milieu de l'écran
										static_cast<int> (GameParameters::getGameHeight()) * 0.8f,
										"Player2");

		player2->load(p);

		players->push_back(player1);
		players->push_back(player2);

		delete p;


	} else {
		Player * player = new Player();
		LoadParameters * p = new LoadParameters(GameParameters::getGameWidth() * 0.5f - TextureManager::Instance()->getTextureInformationsFromID("Player1").width * 0.5f, //Milieu de l'écran
										static_cast<int> (GameParameters::getGameHeight()) * 0.8f,
										"Player1");
		player->load(p);

		players->push_back(player);

		delete p;
	}
}

void PlayerManager::update() const {
	for (auto& player : *players) {
		player->update();
	}
}

void PlayerManager::render() const {
	for (auto& player : *players) {
		player->draw();
	}
}

void PlayerManager::clear() const {
	for (auto& player : *players) {
		player->clean();
		delete player;
	}

	players->clear();
}
