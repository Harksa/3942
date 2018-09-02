#include "WaveGenerator.h"
#include <tinyxml2.h>

void WaveGenerator::parseWave(const std::string & fileName, std::vector<EnemySpawInformations*>* enemy_spaw_informations) {
	tinyxml2::XMLDocument xml_document;
	xml_document.LoadFile(fileName.c_str());
	tinyxml2::XMLElement * root = xml_document.RootElement();
	
	for(tinyxml2::XMLElement *e = root->FirstChildElement() ; e != nullptr ; e = e->NextSiblingElement()) {
		if(e->Value() == std::string("enemy")) {
			enemy_spaw_informations->push_back(new EnemySpawInformations(
				e->Attribute("type"), e->FloatAttribute("x"), e->FloatAttribute("y"), e->IntAttribute("time")
			));
		}
	} 
}

