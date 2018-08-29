#pragma once
#include <iostream>
#include <vector>
#include "GameObject.h"
#include <tinyxml2.h>

/**
 * \brief Permet de charger les états à partir d'un fichier XML rentré en paramètre
 */
class StateParser {
public:

	/**
	 * \brief Charge les paramètres d'un état
	 * \param stateFile Le fichier XML où sont stockées les informations de l'état
	 * \param stateID L'ID du state que l'on souhaite charger
	 * \param objects La liste des gameobjects de l'état
	 * \param textureIDs La liste des textures de l'état
	 * \return Vrai si l'état a correctement été chargée, faux sinon.
	 */
	bool parseState(const char * stateFile, const std::string& stateID, std::vector<GameObject*> * objects, std::vector<std::string> *textureIDs);

private:

	/**
	 * \brief Charge les objets présent dans l'état
	 * \param stateRoot L'endroit où se trouve les informations des objets, dans le fichier XML
	 * \param objects La liste des gameobjects de cet état
	 */
	void parseObject(tinyxml2::XMLElement * stateRoot, std::vector<GameObject*> *objects);

	/**
	 * \brief Charge les textures présent dans l'état
	 * \param stateRoot L'endroit où se trouve les informations des textures, dans le fichier XML
	 * \param textureIDs La liste des textures de cet état
	 */
	void parseTexture(tinyxml2::XMLElement * stateRoot, std::vector<std::string> *textureIDs);
};

