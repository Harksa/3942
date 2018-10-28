#pragma once
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
	 * \param pStateFile Le fichier XML où sont stockées les informations de l'état
	 * \param pStateId L'ID du state que l'on souhaite charger
	 * \param pObjects La liste des gameobjects de l'état
	 * \param pTextureIDs La liste des textures de l'état
	 * \return Vrai si l'état a correctement été chargée, faux sinon.
	 */
	static bool parseState(const char * pStateFile, const std::string& pStateId, std::vector<GameObject*> * pObjects, std::vector<std::string> *pTextureIDs);

private:

	/**
	 * \brief Charge les objets présent dans l'état
	 * \param pStateRoot L'endroit où se trouve les informations des objets, dans le fichier XML
	 * \param pObjects La liste des gameobjects de cet état
	 */
	static void parseObject(tinyxml2::XMLElement * pStateRoot, std::vector<GameObject*> *pObjects);

	/**
	 * \brief Charge les textures présent dans l'état
	 * \param pStateRoot L'endroit où se trouve les informations des textures, dans le fichier XML
	 * \param pTextureIDs La liste des textures de cet état
	 */
	static void parseTexture(tinyxml2::XMLElement * pStateRoot, std::vector<std::string> *pTextureIDs);
};

