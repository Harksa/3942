#pragma once
#include "GameObject.h"
#include <string>
#include <map>
#include <iostream>

/**
 * \brief La base du créateur de gameobject.
 */
class BaseCreator {
public:
	virtual GameObject * createGameObject() const = 0;
	virtual ~BaseCreator() {};
};

/**
 * \brief Le créateur de gameObject
 */
class GameObjectFactory {
public:
	/**
	 * \brief Retourne l'instance du GameObjectFactory
	 * \return L'instance du GameObjectFactory
	 */
	static GameObjectFactory *  Instance() {
		if(instance == nullptr) {
			instance = new GameObjectFactory();
		}

		return instance;
	}

	/**
	 * \brief Enregistre le type de gameObject pouvant être créé.
	 * \param typeID Le type de GameObject que l'on souhaite rajouter à la liste.
	 * \param creator Le creator qui permettra d'instancier le gameboject
	 * \return vrai si le type a bien été enregistré, faux sinon.
	 */
	bool registerType(std::string typeID, BaseCreator *creator) {
		std::map<std::string, BaseCreator*>::iterator it = _creator.find(typeID);

		if(it != _creator.end()) {
			delete creator;
			return false;
		}

		_creator[typeID] = creator;
		return true;
	}

	/**
	 * \brief Créer le GameObject avec le type rentré en paramètre.
	 * \param typeID le type de GameObject que l'on souhaite créer.
	 * \return Le GameObject désiré
	 */
	GameObject * create(std::string typeID) {
		auto it = _creator.find(typeID);

		if(it == _creator.end()) {
			std::cout << "GAMEOBJECTFACTORY::CREATE::COULDNT FIND TYPE : " << typeID << std::endl;
			return nullptr;
		}

		BaseCreator * creator = (*it).second;
		return creator->createGameObject();
	}

private:
	/**
	 * \brief L'instance du GameObjectFactory
	 */
	static GameObjectFactory * instance;

	/**
	 * \brief La map des typeID et des créators qui leurs sont liés
	 */
	std::map<std::string, BaseCreator*> _creator;
};

