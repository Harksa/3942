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
	TileLayer(int tileSize, std::vector<Tileset> tilesets);

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
	 * \param data Le vecteur d'ID utilis� par Tiled.
	 */
	void setTileIDs(const std::vector<std::vector<int>>& data);

	/**
	 * \brief Initialise la taille des tiles.
	 * \param tileSize La taille des tiles d�sir�s.
	 */
	void setTileSize(int tileSize);

	/**
	 * \brief Donne le Tile en fonction de son ID
	 * \param tileID l'ID du tile que l'on souhaite trouver.
	 * \return le Tile d�sir�.
	 */
	Tileset getTilesetByID(int tileID) const;

private:
	/**
	 * \brief le nombre de colones pr�sent � l'�cran.
	 */
	int _numColumns;

	/**
	 * \brief Le nombre de lignes pr�sent � l'�cran.
	 */
	int _numRows;

	/**
	 * \brief La taille des tiles
	 */
	int _tileSize;

	/**
	 * La position de la cam�ra 
	 */
	Vector2D _position;

	/**
	 * \brief La vitesse de la cam�ra.
	 */
	Vector2D _velocity;

	/**
	 * \brief les tiles du niveau.
	 */
	const std::vector<Tileset> _tilesets;

	/**
	 * \brief Les IDs des tiles du niveau.
	 */
	std::vector<std::vector<int>> _tileIDs;
};

