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
	virtual ~BaseCreator() = default;
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
	static GameObjectFactory* Instance();

	/**
	 * \brief Enregistre le type de gameObject pouvant être créé.
	 * \param typeID Le type de GameObject que l'on souhaite rajouter à la liste.
	 * \param creator Le creator qui permettra d'instancier le gameboject
	 * \return vrai si le type a bien été enregistré, faux sinon.
	 */
	bool registerType(const std::string& typeID, BaseCreator* creator);

	/**
	 * \brief Créer le GameObject avec le type rentré en paramètre.
	 * \param typeID le type de GameObject que l'on souhaite créer.
	 * \return Le GameObject désiré
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
	 * \brief La map des typeID et des créators qui leurs sont liés
	 */
	std::map<std::string, BaseCreator*> _creator;
};

