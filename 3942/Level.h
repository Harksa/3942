#pragma once
#include <string>
#include <vector>
#include <zlib.h>
#include <sstream>
#include <iostream>
#include "Layer.h"

/**
 *\brief Les informations d'un set de tile enregistré dans Tiled.
 */
struct Tileset {
	int firstGridID;
	int tileWidth;
	int tileHeight;
	int spacing;
	int margin;
	int width;
	int height;
	int numColumns;

	std::string name;
};

std::ostream& operator<<(std::ostream& stream, Tileset& tileset);

/**
 * \brief Un niveau de jeu.
 */
class Level {
public:

	/**
	 * \brief Mets à jour le niveau.
	 */
	void update();

	/**
	 * \brief Affiche le niveau.
	 */
	void render();

	/**
	 * \brief Retourne la liste des tilesets de ce niveau.
	 * \return La liste des tilesets de ce niveau.
	 */
	std::vector<Tileset>* getTilesets();

	/**
	 * \brief Retourne la liste des layers de ce niveau.
	 * \return La liste des Layers de ce niveau.
	 */
	std::vector<Layer*>* getLayers();

	/**
	 * \brief Imprime les informations de chaque tilesets.
	 */
	void printAllTileSet();

	~Level() = default;

private:
	friend class LevelParser;
	Level() = default;

	/**
	 * \brief les tilesets disponibles dans ce niveau.
	 */
	std::vector<Tileset> _tilesets;

	/**
	 * \brief Les layers disponibles dans ce niveau.
	 */
	std::vector<Layer*> _layers;
};

