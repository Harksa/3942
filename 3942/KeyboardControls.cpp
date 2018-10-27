#include "KeyboardControls.h"
#include <iostream>
#include <tinyxml2.h>

KeyboardControls * KeyboardControls::instance{nullptr};

KeyboardControls* KeyboardControls::Instance() {
	if (instance == nullptr) {
		instance = new KeyboardControls();
	}

	return instance;
}

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

bool KeyboardControls::isScancodeTheSame(SDL_Scancode scancode) {
	return controls[playerChange].at(controlsChange) == scancode;
}

bool KeyboardControls::isScancodeAlreadyUsed(SDL_Scancode scancode) const {
	for (const auto& i : controls) {
		for (const auto control : i) {
			if(control.second == scancode)
				return true;
		}
	}

	return false;
}

void KeyboardControls::changeKey(SDL_Scancode new_key_value) {
	controls[playerChange].at(controlsChange) = new_key_value;

	tinyxml2::XMLDocument controlsDoc;

	if(controlsDoc.LoadFile("ressources/controls.xml") == tinyxml2::XML_SUCCESS) {
		tinyxml2::XMLElement * root = controlsDoc.RootElement();
		if(playerChange == PLAYER_1) {
			for(tinyxml2::XMLElement * e = root->FirstChildElement("PLAYER1")->FirstChildElement() ;  e != nullptr ; e = e->NextSiblingElement()) {
				if(e->IntAttribute("enumValue") == controlsChange) {
					e->SetAttribute("key", new_key_value);
					break;
				}
			}
		} else {
			for(tinyxml2::XMLElement * e = root->FirstChildElement("PLAYER2")->FirstChildElement() ;  e != nullptr ; e = e->NextSiblingElement()) {
				if(e->IntAttribute("enumValue") == controlsChange) {
					e->SetAttribute("key", new_key_value);
					break;
				}	
			}
		}

		controlsDoc.SaveFile("ressources/controls.xml");
	} else {
		std::cout << "KEYBOARDCONTROLS::ERREUR::IMPOSSIBLE D'OUVRIR LE FICHIER XML" << std::endl;
	}
}

SDL_Scancode KeyboardControls::getKeyCode(PLAYER_NUM player, CONTROLS key) const {
	return controls[player].at(key);
}

void KeyboardControls::askToChangeControls(bool value) { askToChange = value; }

void KeyboardControls::setToChange(PLAYER_NUM player, CONTROLS control) {
	playerChange = player;
	controlsChange = control;
}

bool KeyboardControls::isAskingToChangeControls() const { return askToChange; }

PLAYER_NUM KeyboardControls::getPlayerNumToChange() const { return playerChange; }

CONTROLS KeyboardControls::getControlToChange() const { return controlsChange; }
