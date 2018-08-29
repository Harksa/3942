#include "TileLayer.h"
#include "Game.h"

TileLayer::TileLayer(int tileSize, const std::vector<Tileset>& tilesets) : _tileSize(tileSize), _tilesets(tilesets) {
	_numColumns = Game::Instance()->getGameWidth() / tileSize;
	_numRows = Game::Instance()->getGameHeight() / tileSize;
}

void TileLayer::update() {
	_position += _velocity;
	_velocity.x = 1;
}

Tileset TileLayer::getTilesetByID(int tileID) {

    for(unsigned int i = 0; i < _tilesets.size(); i++) {
        if( i + 1 <= _tilesets.size() - 1)  {
            if(tileID >= _tilesets[i].firstGridID && tileID < _tilesets[i + 1].firstGridID) {
                return _tilesets[i];
            }
        }  else  {
            return _tilesets[i];
        }
    }

    return Tileset();
}

void TileLayer::render() {
	int x, y, x2, y2;

	x = static_cast<int> (_position.x / _tileSize);
	y = static_cast<int> (_position.y / _tileSize);

	x2 = int(_position.x) % _tileSize;
	y2 = int(_position.y) % _tileSize;

	for(int i = 0 ; i < _numRows ; i++) {
		for(int j = 0 ; j < _numColumns ; j++) {
			int id = _tileIDs[i][j + x];
			if(id == 0) continue;

			Tileset tileset = getTilesetByID(id);
			id--;

			TextureManager::Instance()->drawTile(tileset.name, tileset.margin, tileset.spacing, (j * _tileSize) - x2, (i * _tileSize) - y2, _tileSize, _tileSize, (id - (tileset.firstGridID - 1)) /
												 tileset.numColumns, (id - (tileset.firstGridID - 1)) % tileset.numColumns, Game::Instance()->getRenderer());

		}
	}
}
