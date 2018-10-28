#pragma once
#include <vector>
#include "GameObject.h"
#include <tinyxml2.h>

/**
 * \brief Permet de charger les �tats � partir d'un fichier XML rentr� en param�tre
 */
class StateParser {
public:

	/**
	 * \brief Charge les param�tres d'un �tat
	 * \param pStateFile Le fichier XML o� sont stock�es les informations de l'�tat
	 * \param pStateId L'ID du state que l'on souhaite charger
	 * \param pObjects La liste des gameobjects de l'�tat
	 * \param pTextureIDs La liste des textures de l'�tat
	 * \return Vrai si l'�tat a correctement �t� charg�e, faux sinon.
	 */
	static bool parseState(const char * pStateFile, const std::string& pStateId, std::vector<GameObject*> * pObjects, std::vector<std::string> *pTextureIDs);

private:

	/**
	 * \brief Charge les objets pr�sent dans l'�tat
	 * \param pStateRoot L'endroit o� se trouve les informations des objets, dans le fichier XML
	 * \param pObjects La liste des gameobjects de cet �tat
	 */
	static void parseObject(tinyxml2::XMLElement * pStateRoot, std::vector<GameObject*> *pObjects);

	/**
	 * \brief Charge les textures pr�sent dans l'�tat
	 * \param pStateRoot L'endroit o� se trouve les informations des textures, dans le fichier XML
	 * \param pTextureIDs La liste des textures de cet �tat
	 */
	static void parseTexture(tinyxml2::XMLElement * pStateRoot, std::vector<std::string> *pTextureIDs);
};

