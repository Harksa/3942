#include "KeyboardControls.h"
#include <iostream>

KeyboardControls * KeyboardControls::instance{nullptr};

void KeyboardControls::init() {

	tinyxml2::XMLDocument controlsDoc;

	if(controlsDoc.LoadFile("ressources/controls.xml") != tinyxml2::XML_SUCCESS) {
		std::cout << "KEYBOARDCONTROLS::ERREUR::IMPOSSIBLE D'OUVRIR LE FICHIER XML" << std::endl;

		controls[0].insert(std::make_pair(MOVE_UP_KEY, SDL_SCANCODE_UP));
		controls[0].insert(std::make_pair(MOVE_LEFT_KEY, SDL_SCANCODE_LEFT));
		controls[0].insert(std::make_pair(MOVE_DOWN_KEY, SDL_SCANCODE_DOWN));
		controls[0].insert(std::make_pair(MOVE_RIGHT_KEY, SDL_SCANCODE_RIGHT));
		controls[0].insert(std::make_pair(FIRE_KEY, SDL_SCANCODE_KP_ENTER));

		controls[1].insert(std::make_pair(MOVE_UP_KEY, SDL_SCANCODE_W));
		controls[1].insert(std::make_pair(MOVE_LEFT_KEY, SDL_SCANCODE_A));
		controls[1].insert(std::make_pair(MOVE_DOWN_KEY, SDL_SCANCODE_S));
		controls[1].insert(std::make_pair(MOVE_RIGHT_KEY, SDL_SCANCODE_D));
		controls[1].insert(std::make_pair(FIRE_KEY, SDL_SCANCODE_SPACE));

	} else {
		tinyxml2::XMLElement * root = controlsDoc.RootElement();

		//Player 1
		for(tinyxml2::XMLElement * e = root->FirstChildElement("PLAYER1")->FirstChildElement() ;  e != nullptr ; e = e->NextSiblingElement()) {
			controls[0].insert(std::make_pair(CONTROLS (e->IntAttribute("enumValue")), SDL_Scancode(e->IntAttribute("key")) ));
		}

		//Player 2
		for(tinyxml2::XMLElement * e = root->FirstChildElement("PLAYER2")->FirstChildElement() ;  e != nullptr ; e = e->NextSiblingElement()) {
			controls[1].insert(std::make_pair(CONTROLS (e->IntAttribute("enumValue")), SDL_Scancode(e->IntAttribute("key")) ));
		}
	}
}
