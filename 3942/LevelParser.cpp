#include "LevelParser.h"
#include "TextureManager.h"
#include "Game.h"
#include "TileLayer.h"

#include <zlib.h>
#include <sstream>
#include "ObjectLayer.h"
#include "GameObjectFactory.h"

Level* LevelParser::parseLevel(const char* levelFile) {
	tinyxml2::XMLDocument levelDocument;
	levelDocument.LoadFile(levelFile);

	Level * level = new Level();

	tinyxml2::XMLElement * root = levelDocument.RootElement();

	_width =  root->IntAttribute("width");
	_height =  root->IntAttribute("height");
	_tileSize = root->IntAttribute("tilewidth");

	for(tinyxml2::XMLElement *e = root->FirstChildElement("properties")->FirstChildElement() ; e != nullptr ; e = e->NextSiblingElement()) {
		if(e->Value() == std::string("property"))
			parseTextures(e);	
	}

	for(tinyxml2::XMLElement* e = root->FirstChildElement(); e != nullptr; e = e->NextSiblingElement()) {
		if(e->Value() == std::string("tileset"))
			parseTilesets(e, level->getTilesets());
		else if(e->Value() == std::string("layer"))
			parseTileLayers(e, level->getLayers(), level->getTilesets());
		else if(e->Value() == std::string("objectgroup")) {
			parseObjectLayer(e, level->getLayers());
		}
	}

	return level;
}

void LevelParser::parseTilesets(tinyxml2::XMLElement* tilesetRoot, std::vector<Tileset>* tilesets) {
	std::string filename = "ressources/";
	filename +=  tilesetRoot->Attribute("source");

	tinyxml2::XMLDocument document;
	document.LoadFile(filename.c_str());

	tinyxml2::XMLElement * root = document.RootElement();
	filename = "ressources/";
	filename += root->FirstChildElement()->Attribute("source");

	TextureManager::Instance()->load(filename, root->Attribute("name"), Game::Instance()->getRenderer());

	Tileset tileset;
	tileset.width		= root->FirstChildElement()->IntAttribute("width");
	tileset.height		= root->FirstChildElement()->IntAttribute("height");

	tileset.firstGridID = tilesetRoot->IntAttribute("firstgid");
	tileset.tileHeight	= root->IntAttribute("tileheight");
	tileset.tileWidth	= root->IntAttribute("tilewidth");
	tileset.spacing		= root->IntAttribute("spacing");
	tileset.margin		= root->IntAttribute("margin");
	tileset.name		= root->Attribute("name");

	tileset.numColumns = tileset.width / (tileset.tileWidth + tileset.spacing);

	tilesets->push_back(tileset);
}

void LevelParser::parseTileLayers(tinyxml2::XMLElement* tileElements, std::vector<Layer*>* layers, const std::vector<Tileset>* tilesets) {
	auto tileLayer = new TileLayer(_tileSize, * tilesets);

	std::vector<std::vector<int>> data;
	const std::string csv_data = tileElements->FirstChildElement("data")->GetText();

	std::stringstream str_strm(csv_data);
	std::string tmp;
	std::vector<int> csv_values;

	while(std::getline(str_strm, tmp, ',')) {
		csv_values.push_back(stoi(tmp));
	}

	const std::vector<int> layerRow(_width);

	data.reserve(_height);
	for(int i = 0 ; i < _height ; i++)
		data.push_back(layerRow);

	for(int rows = 0 ; rows < _height ; rows++) {
		for (int cols = 0 ; cols < _width ; cols++) {
			data[rows][cols] = csv_values[rows * _width + cols];
		}
	}

	tileLayer->setTileIDs(data);
	layers->push_back(tileLayer);
}

void LevelParser::parseTextures(tinyxml2::XMLElement* textureRoot) {
	TextureManager::Instance()->load(textureRoot->Attribute("value"), textureRoot->Attribute("name"), Game::Instance()->getRenderer());
}

void LevelParser::parseObjectLayer(tinyxml2::XMLElement* objectElement, std::vector<Layer*>* layer) {
	ObjectLayer * objectLayer = new ObjectLayer();

	for(tinyxml2::XMLElement * objectRoot = objectElement->FirstChildElement() ; objectRoot != nullptr ; objectRoot = objectRoot->NextSiblingElement()) {
		if(objectRoot->Value() == std::string("object")) {

			int x,y, width = 0, height = 0, numFrames = 0, callbackID = 0, animSpeed = 0;
			std::string textureID;

			x = objectRoot->IntAttribute("x");
			y = objectRoot->IntAttribute("y");

			GameObject * gameObject = GameObjectFactory::Instance()->create(objectRoot->Attribute("type"));

			//Properties values
			for(tinyxml2::XMLElement *e = objectRoot->FirstChildElement("properties")->FirstChildElement() ; e != nullptr ; e = e->NextSiblingElement()) {
				if(e->Attribute("name") == std::string("numFrames"))
					numFrames = e->IntAttribute("value");
				else if(e->Attribute("name") == std::string("textureHeight"))
					height = e->IntAttribute("value");
				else if(e->Attribute("name") == std::string("textureID"))
					textureID = e->Attribute("value");
				else if (e->Attribute("name") == std::string("textureWidth"))
					width = e->IntAttribute("value");
				else if (e->Attribute("name") == std::string("callbackID"))
					callbackID = e->IntAttribute("value");
				else if(e->Attribute("name") == std::string("animSpeed"))
					animSpeed = e->IntAttribute("value");
			}

			gameObject->load(new LoadParameters(static_cast<float> (x), static_cast<float>(y), width, height, textureID, numFrames, callbackID, animSpeed));
			objectLayer->getGameObjects()->push_back(gameObject);
		}
	}

	layer->push_back(objectLayer);

}
