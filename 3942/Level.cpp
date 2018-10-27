#include "Level.h"

void Level::render() {
	for (auto layer : _layers) {
		layer->render();
	}
}

void Level::printAllTileSet() {
	for (auto tileset : _tilesets) {
		std::cout << tileset;
	}
}

void Level::update() {
	for (auto layer : _layers) {
		layer->update();
	}
}

std::ostream& operator<<(std::ostream& stream, Tileset& tileset) {
	stream << "Tileset : " << tileset.name << std::endl;
	stream << "FirstGridID : " << tileset.firstGridID << std::endl;
	stream << "tileWidth : " << tileset.tileWidth << std::endl;
	stream << "tileHeight : " << tileset.tileHeight << std::endl;
	stream << "spacing : " << tileset.spacing << std::endl;
	stream << "margin : " << tileset.margin << std::endl;
	stream << "width : " << tileset.width << std::endl;
	stream << "height : " << tileset.height << std::endl;
	stream << "numColumns : " << tileset.numColumns << std::endl;
	return stream;
}

std::vector<Tileset>* Level::getTilesets() { return &_tilesets; }

std::vector<Layer*>* Level::getLayers() { return &_layers; }
