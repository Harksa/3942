#include "GameObjectFactory.h"

GameObjectFactory * GameObjectFactory::instance {nullptr};

GameObjectFactory* GameObjectFactory::Instance() {
	if (instance == nullptr) {
		instance = new GameObjectFactory();
	}

	return instance;
}

bool GameObjectFactory::registerType(std::string typeID, BaseCreator* creator) {
	std::map<std::string, BaseCreator*>::iterator it = _creator.find(typeID);

	if (it != _creator.end()) {
		delete creator;
		return false;
	}

	_creator[typeID] = creator;
	return true;
}

GameObject* GameObjectFactory::create(std::string typeID) {
	auto it = _creator.find(typeID);

	if (it == _creator.end()) {
		std::cout << "GAMEOBJECTFACTORY::CREATE::COULDNT FIND TYPE : " << typeID << std::endl;
		return nullptr;
	}

	BaseCreator* creator = (*it).second;
	return creator->createGameObject();
}
