#include "GameObjectFactory.h"

GameObjectFactory * GameObjectFactory::instance {nullptr};

GameObjectFactory* GameObjectFactory::Instance() {
	if (instance == nullptr) {
		instance = new GameObjectFactory();
	}

	return instance;
}

bool GameObjectFactory::registerType(const std::string& pTypeId, BaseCreator* pCreator) {
	std::map<std::string, BaseCreator*>::iterator it = _creator.find(pTypeId);

	if (it != _creator.end()) {
		delete pCreator;
		return false;
	}

	_creator[pTypeId] = pCreator;
	return true;
}

GameObject* GameObjectFactory::create(const std::string& pTypeId) {
	auto it = _creator.find(pTypeId);

	if (it == _creator.end()) {
		std::cout << "GAMEOBJECTFACTORY::CREATE::COULDNT FIND TYPE : " << pTypeId << std::endl;
		return nullptr;
	}

	BaseCreator* creator = (*it).second;
	return creator->createGameObject();
}
