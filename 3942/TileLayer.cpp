#include "TileLayer.h"
#include <utility>
#include "GameParameters.h"
#include "TextureManager.h"

TileLayer::TileLayer(const int pTileSize, std::vector<Tileset> pTilesets) : tile_size{pTileSize}, tilesets{std::move(pTilesets)} {
	num_columns = GameParameters::getGameWidth() / pTileSize;
	num_rows = GameParameters::getGameHeight() / pTileSize;
}

void TileLayer::update() {
	position += velocity;
	velocity.x = 1;
}

Tileset TileLayer::getTilesetByID(const int pTileId) const {

    for(unsigned int i = 0; i < tilesets.size(); i++) {
        if( i + 1 <= tilesets.size() - 1)  {
            if(pTileId >= tilesets[i].first_grid_id && pTileId < tilesets[i + 1].first_grid_id) {
                return tilesets[i];
            }
        }  else  {
            return tilesets[i];
        }
    }

    return Tileset();
}

void TileLayer::render() {
	int x, y, x2, y2;

	x = static_cast<int> (position.x / tile_size);
	y = static_cast<int> (position.y / tile_size);

	x2 = int(position.x) % tile_size;
	y2 = int(position.y) % tile_size;

	for(int i = 0 ; i < num_rows ; i++) {
		for(int j = 0 ; j < num_columns ; j++) {
			int id = tile_ids[i][j + x];
			if(id == 0) continue;

			Tileset tileset = getTilesetByID(id);
			id--;

			TextureManager::Instance()->drawTile(tileset.name, tileset.margin, tileset.spacing, (j * tile_size) - x2, (i * tile_size) - y2, tile_size, tile_size, (id - (tileset.first_grid_id - 1)) /
			                                     tileset.num_columns, (id - (tileset.first_grid_id - 1)) % tileset.num_columns);

		}
	}
}

void TileLayer::setTileIDs(const std::vector<std::vector<int>>& pData) {
	tile_ids = pData;
}

void TileLayer::setTileSize(const int pTileSize) {
	tile_size = pTileSize;
}
