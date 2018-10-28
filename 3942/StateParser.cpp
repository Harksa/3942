#include "StateParser.h"
#include "GameObjectFactory.h"
#include "TextureManager.h"

bool StateParser::parseState(const char* pStateFile, const std::string& pStateId, std::vector<GameObject*> * pObjects, std::vector<std::string> *pTextureIDs) {
	tinyxml2::XMLDocument xmlDoc;

	if (xmlDoc.LoadFile(pStateFile) != tinyxml2::XML_SUCCESS) {
		std::cerr << xmlDoc.ErrorStr() << "\n";
		return false;
	}

	tinyxml2::XMLElement* root = xmlDoc.RootElement(); //<STATES>

	tinyxml2::XMLElement* stateRoot = root->FirstChildElement(pStateId.c_str());

	parseTexture(stateRoot->FirstChildElement("TEXTURES"), pTextureIDs);

	parseObject(stateRoot->FirstChildElement("OBJECTS"), pObjects);

	return true;
}

void StateParser::parseObject(tinyxml2::XMLElement * pStateRoot, std::vector<GameObject*>* pObjects) {

	for(tinyxml2::XMLElement *e = pStateRoot->FirstChildElement() ; e != nullptr ; e = e->NextSiblingElement()) {
		int x, y, callbackID;
		std::string textureId;

		x = e->IntAttribute("x");
		y = e->IntAttribute("y");
		textureId = e->Attribute("textureID");
		callbackID = e->IntAttribute("callbackID");

		GameObject * gameObject = GameObjectFactory::Instance()->create(e->Attribute("type"));
		gameObject->load(new LoadParameters(static_cast<float> (x), static_cast<float> (y), textureId, callbackID));
		pObjects->push_back(gameObject);
	}
}

void StateParser::parseTexture(tinyxml2::XMLElement * pStateRoot, std::vector<std::string>* pTextureIDs) {
	for(tinyxml2::XMLElement *e = pStateRoot->FirstChildElement() ; e != nullptr ; e = e->NextSiblingElement()) {
		const std::string fileNameAttribute = e->Attribute("filename");
		const std::string id = e->Attribute("ID");
		const int w = e->IntAttribute("width");
		const int h = e->IntAttribute("height");
		const int numframes = e->IntAttribute("numFrames");
		const int speed = e->IntAttribute("animSpeed");
		pTextureIDs->push_back(id);
		TextureManager::Instance()->load(fileNameAttribute, id, w, h, numframes, speed);
	}
}
