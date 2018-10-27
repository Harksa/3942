#include "WaveGenerator.h"
#include <tinyxml2.h>

EnemySpawInformations::EnemySpawInformations(std::string enemy, const float x, const float y, const int h, const unsigned p, const unsigned t, std::string texture) : 
	type{std::move(enemy)}, spawn_x{x}, spawn_y{y}, health{h}, points{p}, timer{t}, textureID{std::move(texture)} {}

void WaveGenerator::parseWave(const std::string & fileName, std::vector<EnemySpawInformations>* enemy_spaw_informations) {
	tinyxml2::XMLDocument xml_document;
	xml_document.LoadFile(fileName.c_str());
	tinyxml2::XMLElement * root = xml_document.RootElement();
	
	for(tinyxml2::XMLElement *e = root->FirstChildElement() ; e != nullptr ; e = e->NextSiblingElement()) {
		if(e->Value() == std::string("enemy")) {
			enemy_spaw_informations->push_back(EnemySpawInformations(
				e->Attribute("type"), e->FloatAttribute("x"), e->FloatAttribute("y"), e->IntAttribute("health"), e->IntAttribute("points"), e->IntAttribute("time"), e->Attribute("textureID")
			));
		}
	} 
}

