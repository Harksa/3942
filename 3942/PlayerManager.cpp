#include "PlayerManager.h"
#include "GameParameters.h"

PlayerManager * PlayerManager::instance = nullptr;

PlayerManager* PlayerManager::Instance() {
	if (instance == nullptr)
		instance = new PlayerManager();

	return instance;
}

void PlayerManager::init() {
	if(GameParameters::isTwoPlayer()) {

		Player * player1 = new Player(PLAYER_1), * player2 = new Player(PLAYER_2);

		if(!GameParameters::isPlayerUsingKeyboard(PLAYER_1) && !GameParameters::isPlayerUsingKeyboard(PLAYER_2)) {
			player1->setJoystickID(0);
			player2->setJoystickID(1);
		} else if (!GameParameters::isPlayerUsingKeyboard(PLAYER_1) && GameParameters::isPlayerUsingKeyboard(PLAYER_2)) {
			player1->setJoystickID(0);
		} else if (GameParameters::isPlayerUsingKeyboard(PLAYER_1) && !GameParameters::isPlayerUsingKeyboard(PLAYER_2)) {
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

		players.push_back(player1);
		players.push_back(player2);

		delete p;

	} else {
		Player * player = new Player();
		LoadParameters * p = new LoadParameters(GameParameters::getGameWidth() * 0.5f - TextureManager::Instance()->getTextureInformationsFromID("Player1").width * 0.5f, //Milieu de l'écran
										static_cast<int> (GameParameters::getGameHeight()) * 0.8f,
										"Player1");
		player->load(p);

		players.push_back(player);

		delete p;
	}
}

void PlayerManager::update() {
	for(auto it = players.begin() ; it != players.end() ; ) {
		if((*it)->hasRemainingLives()) {
			(*it)->update();
			++it;
		} else {
			(*it)->clean();
			delete *it;
			it = players.erase(it);
		}
	}

}

void PlayerManager::render() const {
	for (auto player : players) {
		if(player->hasRemainingLives())
			player->draw();
	}
}

void PlayerManager::clear() {
	for (auto player : players) {
		player->clean();
		delete player;
	}

	players.clear();
}

bool PlayerManager::doesAllPlayersDoesntHaveAnyRemainingLives() const {
	for (auto& player : players) {
		if(player->hasRemainingLives())
			return false;
	}

	return true;
}

std::vector<Player*> PlayerManager::getPlayers() const { return players; }
