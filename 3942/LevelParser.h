#pragma once
#include <tinyxml2.h>
#include "Level.h"

/**
 *\brief Charge un niveau à partir d'un fichier d'un fichier TMX et d'un ou plusieurs fichiers tsx.
 */
class LevelParser {
public:

	/**
	 * \brief Charge le niveau à partir du fichier tsx rentrée en paramètre.
	 * \param pLevelFile Le chemin du fichier tsx.
	 * \return Le niveau chargé.
	 */
	Level * parseLevel(const char* pLevelFile);

private:

	/**
	 * \brief Charge en mémoire les informations des tilesets.
	 * \param pTilesetRoot Le chemin dans le fichier xml des informations des tilesets.
	 * \param pTilesets Le pointeur vers le tilesets du niveau.
	 */
	void parseTilesets(tinyxml2::XMLElement * pTilesetRoot, std::vector<Tileset> * pTilesets);

	/**
	 * \brief Charge en mémoire les informations concernant les Layers du niveau.
	 * \param pTileElements Le chemin dans le fichier xml des informations sur les tiles.
	 * \param pLayers Le pointeur vers les layers de ce niveau.
	 * \param pTilesets Le pointeur vers le tilesets du niveau.
	 */
	void parseTileLayers(tinyxml2::XMLElement  *pTileElements, std::vector<Layer*> *pLayers, const std::vector<Tileset> * pTilesets);


	/**
	 * \brief Charge en mémoire les informations des textures de ce niveau.
	 * \param pTextureRoot Le chemin dans le fichier xml des informations sur les textures.
	 */
	void parseTextures(tinyxml2::XMLElement * pTextureRoot);


	/**
	 * \brief Charge en mémoire le layer d'objet dont le chemin est donné en paramètre.
	 * \param pObjectElement Le chemin de l'objectLayer dans le fichier xml.
	 * \param pLayer Le pointeur vers les layers de ce niveau.
	 */
	void parseObjectLayer(tinyxml2::XMLElement * pObjectElement, std::vector<Layer*> * pLayer);

	/**
	 * \brief La taille des tiles de ce niveau.
	 */
	int tile_size{0};

	/**
	 * \brief La longueur totale du niveau.
	 */
	int width{0};

	/**
	 * \brief La hauteur totale du niveau.
	 */
	int height{0};
};

