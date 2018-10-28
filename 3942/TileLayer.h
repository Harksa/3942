#pragma once
#include <vector>
#include "Layer.h"
#include "Level.h"
#include "Vector2D.h"

/**
 * \brief Représente un layer d'arrière plan du jeu.
 */
class TileLayer : public Layer {
public:
	TileLayer(int pTileSize, std::vector<Tileset> pTilesets);

	/**
	 * \brief Affiche les tiles du layer.
	 */
	void render() override;
	
	/**
	 * \brief Mets à jour la position des tiles à afficher du layer.
	 */
	void update() override;

	/***
	 * \brief Initialise l'ID des tiles qui sont utilisés par Tiled.
	 * \param pData Le vecteur d'ID utilisé par Tiled.
	 */
	void setTileIDs(const std::vector<std::vector<int>>& pData);

	/**
	 * \brief Initialise la taille des tiles.
	 * \param pTileSize La taille des tiles désirés.
	 */
	void setTileSize(int pTileSize);

	/**
	 * \brief Donne le Tile en fonction de son ID
	 * \param pTileId l'ID du tile que l'on souhaite trouver.
	 * \return le Tile désiré.
	 */
	Tileset getTilesetByID(int pTileId) const;

private:
	/**
	 * \brief le nombre de colones présent à l'écran.
	 */
	int num_columns;

	/**
	 * \brief Le nombre de lignes présent à l'écran.
	 */
	int num_rows;

	/**
	 * \brief La taille des tiles
	 */
	int tile_size;

	/**
	 * La position de la caméra 
	 */
	Vector2D position;

	/**
	 * \brief La vitesse de la caméra.
	 */
	Vector2D velocity;

	/**
	 * \brief les tiles du niveau.
	 */
	const std::vector<Tileset> tilesets;

	/**
	 * \brief Les IDs des tiles du niveau.
	 */
	std::vector<std::vector<int>> tile_ids;
};

