#include "Level.h"
#include <iostream>

void Level::render() {
	for (auto layer : layers) {
		layer->render();
	}
}

void Level::printAllTileSet() {
	for (auto tileset : tilesets) {
		std::cout << tileset;
	}
}

void Level::update() {
	for (auto layer : layers) {
		layer->update();
	}
}

std::ostream& operator<<(std::ostream& stream, Tileset& tileset) {
	stream << "Tileset : " << tileset.name << std::endl;
	stream << "FirstGridID : " << tileset.first_grid_id << std::endl;
	stream << "tileWidth : " << tileset.tile_width << std::endl;
	stream << "tileHeight : " << tileset.tile_height << std::endl;
	stream << "spacing : " << tileset.spacing << std::endl;
	stream << "margin : " << tileset.margin << std::endl;
	stream << "width : " << tileset.width << std::endl;
	stream << "height : " << tileset.height << std::endl;
	stream << "numColumns : " << tileset.num_columns << std::endl;
	return stream;
}

std::vector<Tileset>* Level::getTilesets() { return &tilesets; }

std::vector<Layer*>* Level::getLayers() { return &layers; }
