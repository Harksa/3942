#pragma once
#include "Level.h"
#include <tinyxml2.h>

/**
 *\brief Charge un niveau � partir d'un fichier d'un fichier TMX et d'un ou plusieurs fichiers tsx.
 */
class LevelParser {
public:

	/**
	 * \brief Charge le niveau � partir du fichier tsx rentr�e en param�tre.
	 * \param levelFile Le chemin du fichier tsx.
	 * \return Le niveau charg�.
	 */
	Level * parseLevel(const char* levelFile);

private:

	/**
	 * \brief Charge en m�moire les informations des tilesets.
	 * \param tilesetRoot Le chemin dans le fichier xml des informations des tilesets.
	 * \param tilesets Le pointeur vers le tilesets du niveau.
	 */
	void parseTilesets(tinyxml2::XMLElement * tilesetRoot, std::vector<Tileset> * tilesets);

	/**
	 * \brief Charge en m�moire les informations concernant les Layers du niveau.
	 * \param tileElements Le chemin dans le fichier xml des informations sur les tiles.
	 * \param layers Le pointeur vers les layers de ce niveau.
	 * \param tilesets Le pointeur vers le tilesets du niveau.
	 */
	void parseTileLayers(tinyxml2::XMLElement  *tileElements, std::vector<Layer*> *layers, const std::vector<Tileset> * tilesets);


	/**
	 * \brief Charge en m�moire les informations des textures de ce niveau.
	 * \param textureRoot Le chemin dans le fichier xml des informations sur les textures.
	 */
	void parseTextures(tinyxml2::XMLElement * textureRoot);


	/**
	 * \brief Charge en m�moire le layer d'objet dont le chemin est donn� en param�tre.
	 * \param objectElement Le chemin de l'objectLayer dans le fichier xml.
	 * \param layer Le pointeur vers les layers de ce niveau.
	 */
	void parseObjectLayer(tinyxml2::XMLElement * objectElement, std::vector<Layer*> * layer);

	/**
	 * \brief La taille des tiles de ce niveau.
	 */
	int _tileSize = 0;

	/**
	 * \brief La longueur totale du niveau.
	 */
	int _width = 0;

	/**
	 * \brief La hauteur totale du niveau.
	 */
	int _height = 0;
};

