#include "StateParser.h"
#include "TextureManager.h"
#include "Game.h"
#include "GameObjectFactory.h"


bool StateParser::parseState(const char* stateFile, std::string stateID, std::vector<GameObject*> * objects, std::vector<std::string> *textureIDs) {
	tinyxml2::XMLDocument xmlDoc;

	if (xmlDoc.LoadFile(stateFile) != tinyxml2::XML_SUCCESS) {
		std::cerr << xmlDoc.ErrorStr() << "\n";
		return false;
	}

	tinyxml2::XMLElement* root = xmlDoc.RootElement(); //<STATES>

	tinyxml2::XMLElement* stateRoot = root->FirstChildElement(stateID.c_str());

	parseTexture(stateRoot->FirstChildElement("TEXTURES"), textureIDs);

	parseObject(stateRoot->FirstChildElement("OBJECTS"), objects);

	return true;
}

void StateParser::parseObject(tinyxml2::XMLElement * stateRoot, std::vector<GameObject*>* objects) {
	//objects = new std::vector<GameObject*>();

	for(tinyxml2::XMLElement *e = stateRoot->FirstChildElement() ; e != nullptr ; e = e->NextSiblingElement()) {
		int x, y, width, height, numFrames, callbackID, animSpeed;
		std::string textureId;

		x = e->IntAttribute("x");
		y = e->IntAttribute("y");
		width = e->IntAttribute("width");
		height = e->IntAttribute("height");
		textureId = e->Attribute("textureID");
		numFrames = e->IntAttribute("numFrames");
		animSpeed = e->IntAttribute("animSpeed");
		callbackID = e->IntAttribute("callbackID");

		GameObject * gameObject = GameObjectFactory::Instance()->create(e->Attribute("type"));
		gameObject->load(new LoadParameters(static_cast<float> (x), static_cast<float> (y),width, height, textureId, numFrames, callbackID, animSpeed));
		objects->push_back(gameObject);
	}
}

void StateParser::parseTexture(tinyxml2::XMLElement * stateRoot, std::vector<std::string>* textureIDs) {
	for(tinyxml2::XMLElement *e = stateRoot->FirstChildElement() ; e != nullptr ; e = e->NextSiblingElement()) {
		const std::string fileNameAttribute = e->Attribute("filename");
		const std::string id = e->Attribute("ID");
		textureIDs->push_back(id);
		TextureManager::Instance()->load(fileNameAttribute, id, Game::Instance()->getRenderer());
	}
}
