#include "WaveGenerator.h"
#include <tinyxml2.h>

EnemySpawInformations::EnemySpawInformations(std::string pEnemyType, const float pX, const float pY, const int pHealth, const unsigned pPoints, const unsigned pTimer, std::string pTexture) : 
	type{std::move(pEnemyType)}, spawn_x{pX}, spawn_y{pY}, health{pHealth}, points{pPoints}, timer{pTimer}, texture_id{std::move(pTexture)} {}

void WaveGenerator::parseWave(const std::string & pFileName, std::vector<EnemySpawInformations>* pEnemySpawInformations) {
	tinyxml2::XMLDocument xml_document;
	xml_document.LoadFile(pFileName.c_str());
	tinyxml2::XMLElement * root = xml_document.RootElement();
	
	for(tinyxml2::XMLElement *e = root->FirstChildElement() ; e != nullptr ; e = e->NextSiblingElement()) {
		if(e->Value() == std::string("enemy")) {
			pEnemySpawInformations->push_back(EnemySpawInformations(
				e->Attribute("type"), e->FloatAttribute("x"), e->FloatAttribute("y"), e->IntAttribute("health"), e->IntAttribute("points"), e->IntAttribute("time"), e->Attribute("textureID")
			));
		}
	} 
}

