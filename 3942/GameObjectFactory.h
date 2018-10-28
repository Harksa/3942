#pragma once
#include "GameObject.h"
#include <string>
#include <map>
#include <iostream>

/**
 * \brief La base du cr�ateur de gameobject.
 */
class BaseCreator {
public:
	virtual GameObject * createGameObject() const = 0;
	virtual ~BaseCreator() = default;
};

/**
 * \brief Le cr�ateur de gameObject
 */
class GameObjectFactory {
public:
	/**
	 * \brief Retourne l'instance du GameObjectFactory
	 * \return L'instance du GameObjectFactory
	 */
	static GameObjectFactory* Instance();

	/**
	 * \brief Enregistre le type de gameObject pouvant �tre cr��.
	 * \param typeID Le type de GameObject que l'on souhaite rajouter � la liste.
	 * \param creator Le creator qui permettra d'instancier le gameboject
	 * \return vrai si le type a bien �t� enregistr�, faux sinon.
	 */
	bool registerType(const std::string& typeID, BaseCreator* creator);

	/**
	 * \brief Cr�er le GameObject avec le type rentr� en param�tre.
	 * \param typeID le type de GameObject que l'on souhaite cr�er.
	 * \return Le GameObject d�sir�
	 */
	GameObject* create(const std::string& typeID);

	~GameObjectFactory() = default;

private:
	 GameObjectFactory() = default;

	/**
	 * \brief L'instance du GameObjectFactory
	 */
	static GameObjectFactory * instance;

	/**
	 * \brief La map des typeID et des cr�ators qui leurs sont li�s
	 */
	std::map<std::string, BaseCreator*> _creator;
};

