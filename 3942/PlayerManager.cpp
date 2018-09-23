#include "PlayerManager.h"
#include "GameParameters.h"

PlayerManager * PlayerManager::instance = nullptr;

void PlayerManager::init() {
	if(GameParameters::isTwoPlayer()) {
		Player * player1 = new Player(0), * player2 = new Player(1);

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

void PlayerManager::update() {
	for (auto& player : *players) {
		player->update();
	}
}

void PlayerManager::render() {
	for (auto& player : *players) {
		player->draw();
	}
}

void PlayerManager::clear() const {
	for (auto& player : *players) {
		player->clean();
	}

	players->clear();
}
