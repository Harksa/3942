#pragma once
#include <vector>
#include "Player.h"


class PlayerManager {
public:

	static PlayerManager * Instance() {
		if(instance == nullptr)
			instance = new PlayerManager();

		return instance;
	}

	void init();

	void update() ;

	void render();

	void clear() const;

	std::vector<Player *> * getPlayers() const { return players; }

private:

	PlayerManager() = default;

	static PlayerManager * instance;

	std::vector<Player *> * players = new std::vector<Player *>();
};

