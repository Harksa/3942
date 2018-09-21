#include "StateParser.h"
#include "TextureManager.h"
#include "GameObjectFactory.h"

bool StateParser::parseState(const char* stateFile, const std::string& stateID, std::vector<GameObject*> * objects, std::vector<std::string> *textureIDs) {
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

	for(tinyxml2::XMLElement *e = stateRoot->FirstChildElement() ; e != nullptr ; e = e->NextSiblingElement()) {
		int x, y, callbackID;
		std::string textureId;

		x = e->IntAttribute("x");
		y = e->IntAttribute("y");
		textureId = e->Attribute("textureID");
		callbackID = e->IntAttribute("callbackID");

		GameObject * gameObject = GameObjectFactory::Instance()->create(e->Attribute("type"));
		gameObject->load(new LoadParameters(static_cast<float> (x), static_cast<float> (y), textureId, callbackID));
		objects->push_back(gameObject);
	}
}

void StateParser::parseTexture(tinyxml2::XMLElement * stateRoot, std::vector<std::string>* textureIDs) {
	for(tinyxml2::XMLElement *e = stateRoot->FirstChildElement() ; e != nullptr ; e = e->NextSiblingElement()) {
		const std::string fileNameAttribute = e->Attribute("filename");
		const std::string id = e->Attribute("ID");
		const int w = e->IntAttribute("width");
		const int h = e->IntAttribute("height");
		const int numframes = e->IntAttribute("numFrames");
		const int speed = e->IntAttribute("animSpeed");
		textureIDs->push_back(id);
		TextureManager::Instance()->load(fileNameAttribute, id, w, h, numframes, speed);
	}
}
