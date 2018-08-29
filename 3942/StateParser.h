#pragma once
#include <iostream>
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
	 * \param stateFile Le fichier XML o� sont stock�es les informations de l'�tat
	 * \param stateID L'ID du state que l'on souhaite charger
	 * \param objects La liste des gameobjects de l'�tat
	 * \param textureIDs La liste des textures de l'�tat
	 * \return Vrai si l'�tat a correctement �t� charg�e, faux sinon.
	 */
	bool parseState(const char * stateFile, const std::string& stateID, std::vector<GameObject*> * objects, std::vector<std::string> *textureIDs);

private:

	/**
	 * \brief Charge les objets pr�sent dans l'�tat
	 * \param stateRoot L'endroit o� se trouve les informations des objets, dans le fichier XML
	 * \param objects La liste des gameobjects de cet �tat
	 */
	void parseObject(tinyxml2::XMLElement * stateRoot, std::vector<GameObject*> *objects);

	/**
	 * \brief Charge les textures pr�sent dans l'�tat
	 * \param stateRoot L'endroit o� se trouve les informations des textures, dans le fichier XML
	 * \param textureIDs La liste des textures de cet �tat
	 */
	void parseTexture(tinyxml2::XMLElement * stateRoot, std::vector<std::string> *textureIDs);
};

