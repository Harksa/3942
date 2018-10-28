#pragma once
#include <vector>
#include "Layer.h"
#include "Level.h"
#include "Vector2D.h"

/**
 * \brief Repr�sente un layer d'arri�re plan du jeu.
 */
class TileLayer : public Layer {
public:
	TileLayer(int pTileSize, std::vector<Tileset> pTilesets);

	/**
	 * \brief Affiche les tiles du layer.
	 */
	void render() override;
	
	/**
	 * \brief Mets � jour la position des tiles � afficher du layer.
	 */
	void update() override;

	/***
	 * \brief Initialise l'ID des tiles qui sont utilis�s par Tiled.
	 * \param pData Le vecteur d'ID utilis� par Tiled.
	 */
	void setTileIDs(const std::vector<std::vector<int>>& pData);

	/**
	 * \brief Initialise la taille des tiles.
	 * \param pTileSize La taille des tiles d�sir�s.
	 */
	void setTileSize(int pTileSize);

	/**
	 * \brief Donne le Tile en fonction de son ID
	 * \param pTileId l'ID du tile que l'on souhaite trouver.
	 * \return le Tile d�sir�.
	 */
	Tileset getTilesetByID(int pTileId) const;

private:
	/**
	 * \brief le nombre de colones pr�sent � l'�cran.
	 */
	int num_columns;

	/**
	 * \brief Le nombre de lignes pr�sent � l'�cran.
	 */
	int num_rows;

	/**
	 * \brief La taille des tiles
	 */
	int tile_size;

	/**
	 * La position de la cam�ra 
	 */
	Vector2D position;

	/**
	 * \brief La vitesse de la cam�ra.
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

