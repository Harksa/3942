#include "LevelParser.h"
#include <sstream>
#include "GameObjectFactory.h"
#include "ObjectLayer.h"
#include "TextureManager.h"
#include "TileLayer.h"

Level* LevelParser::parseLevel(const char* pLevelFile) {
	tinyxml2::XMLDocument levelDocument;
	levelDocument.LoadFile(pLevelFile);

	Level * level = new Level();

	tinyxml2::XMLElement * root = levelDocument.RootElement();

	width =  root->IntAttribute("width");
	height =  root->IntAttribute("height");
	tile_size = root->IntAttribute("tilewidth");

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

void LevelParser::parseTilesets(tinyxml2::XMLElement* pTilesetRoot, std::vector<Tileset>* pTilesets) {
	std::string filename = "ressources/";
	filename +=  pTilesetRoot->Attribute("source");

	tinyxml2::XMLDocument document;
	document.LoadFile(filename.c_str());

	tinyxml2::XMLElement * root = document.RootElement();
	filename = "ressources/";
	filename += root->FirstChildElement()->Attribute("source");

	TextureManager::Instance()->load(filename, root->Attribute("name"));

	Tileset tileset;
	tileset.width		= root->FirstChildElement()->IntAttribute("width");
	tileset.height		= root->FirstChildElement()->IntAttribute("height");

	tileset.first_grid_id = pTilesetRoot->IntAttribute("firstgid");
	tileset.tile_height	= root->IntAttribute("tileheight");
	tileset.tile_width	= root->IntAttribute("tilewidth");
	tileset.spacing		= root->IntAttribute("spacing");
	tileset.margin		= root->IntAttribute("margin");
	tileset.name		= root->Attribute("name");

	tileset.num_columns = tileset.width / (tileset.tile_width + tileset.spacing);

	pTilesets->push_back(tileset);
}

void LevelParser::parseTileLayers(tinyxml2::XMLElement* pTileElements, std::vector<Layer*>* pLayers, const std::vector<Tileset>* pTilesets) {
	auto tileLayer = new TileLayer(tile_size, * pTilesets);

	std::vector<std::vector<int>> data;
	const std::string csv_data = pTileElements->FirstChildElement("data")->GetText();

	std::stringstream str_strm(csv_data);
	std::string tmp;
	std::vector<int> csv_values;

	while(std::getline(str_strm, tmp, ',')) {
		csv_values.push_back(stoi(tmp));
	}

	const std::vector<int> layerRow(width);

	data.reserve(height);
	for(int i = 0 ; i < height ; i++)
		data.push_back(layerRow);

	for(int rows = 0 ; rows < height ; rows++) {
		for (int cols = 0 ; cols < width ; cols++) {
			data[rows][cols] = csv_values[rows * width + cols];
		}
	}

	tileLayer->setTileIDs(data);
	pLayers->push_back(tileLayer);
}

void LevelParser::parseTextures(tinyxml2::XMLElement* pTextureRoot) {
	TextureManager::Instance()->load(pTextureRoot->Attribute("value"), pTextureRoot->Attribute("name"));
}

void LevelParser::parseObjectLayer(tinyxml2::XMLElement* pObjectElement, std::vector<Layer*>* pLayer) {
	ObjectLayer * objectLayer = new ObjectLayer();

	for(tinyxml2::XMLElement * objectRoot = pObjectElement->FirstChildElement() ; objectRoot != nullptr ; objectRoot = objectRoot->NextSiblingElement()) {
		if(objectRoot->Value() == std::string("object")) {

			int x,y, width = 0, height = 0, numFrames = 0, callbackID = 0, animSpeed = 0;
			std::string textureID;

			x = objectRoot->IntAttribute("x");
			y = objectRoot->IntAttribute("y");

			GameObject * gameObject = GameObjectFactory::Instance()->create(objectRoot->Attribute("type"));

			//Properties values
			for(tinyxml2::XMLElement *e = objectRoot->FirstChildElement("properties")->FirstChildElement() ; e != nullptr ; e = e->NextSiblingElement()) {
				if(e->Attribute("name") == std::string("textureID"))
					textureID = e->Attribute("value");
				else if (e->Attribute("name") == std::string("callbackID"))
					callbackID = e->IntAttribute("value");
			}

			gameObject->load(new LoadParameters(static_cast<float> (x), static_cast<float>(y), textureID, callbackID));
			objectLayer->getGameObjects()->push_back(gameObject);
		}
	}

	pLayer->push_back(objectLayer);

}
