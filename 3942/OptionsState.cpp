#include "OptionsState.h"
#include "StateParser.h"
#include "GameParameters.h"
#include "InputHandler.h"
#include "FontManager.h"
#include "StateChangeAsker.h"

std::string OptionsState::optionsID{"OPTIONS"};

std::vector<KeyboardOptionButton *> OptionsState::keyboard_options{};

void OptionsState::update() {

	if(KeyboardControls::Instance()->isAskingToChangeControls()) {
		_gameObjects[0]->getSprite()->setVisibility(true);

		const Uint8 * keys = InputHandler::getKeyStates();

		for(unsigned int i = 0 ; i < 255 ; i++) {
			if(keys[i] == 1) {
				const SDL_Scancode scancode = SDL_Scancode(i);
				if(scancode == SDL_SCANCODE_ESCAPE || KeyboardControls::Instance()->isScancodeTheSame(scancode)) {
					KeyboardControls::Instance()->askToChangeControls(false);
					_gameObjects[0]->getSprite()->setVisibility(false);
					scancodeAlreadyUsed = false;
					return;
				} 

				if(!KeyboardControls::Instance()->isScancodeAlreadyUsed(scancode)) {
					KeyboardControls::Instance()->changeKey(scancode);
					KeyboardControls::Instance()->askToChangeControls(false);
					_gameObjects[0]->getSprite()->setVisibility(false);
					scancodeAlreadyUsed = false;
					break;
				} else {
					scancodeAlreadyUsed = true;
					return;
				}

			}
		}
	}

	for (auto keyboard_option : keyboard_options) {
		keyboard_option->update();
	}

	for (auto game_object : _gameObjects) {
		game_object->update();
	}
}

void OptionsState::render() {
	background->draw();

	for (unsigned int i = 1 ; i < _gameObjects.size() ; i++) {
		_gameObjects[i]->draw();	
	}
	
	for (auto keyboard_option : keyboard_options) {
		keyboard_option->draw();
	}
	
	_gameObjects[0]->draw(); //Fond gris

	if(KeyboardControls::Instance()->isAskingToChangeControls()) {
		std::string text = "Select a key for player ";
		text += std::to_string(1 + KeyboardControls::Instance()->getPlayerNumToChange());
		text += " for \n";
		text += ControlsToString[KeyboardControls::Instance()->getControlToChange()];

		if(scancodeAlreadyUsed) {
			text += "\n\nKey already used !";
		}

		FontManager::Instance()->drawBoxAlign("TexWork", text_rect, FC_ALIGN_CENTER, text);
	}
}

bool OptionsState::onEnter() {
	background = new Background();
	background->load("Textures/Backgrounds/Options.png", "options");

	StateParser::parseState("ressources/states.xml", optionsID, &_gameObjects, &_textureIDList);

	//Premier GameObject est le sprite de fond lors de la sélection d'une nouvelle touche
	_gameObjects.at(0)->getSprite()->setVisibility(false);

	FontManager::Instance()->createFont("TexWork", "Fonts/TexWork.ttf", 18, {255,255,255,255});

	for(int i = 0 ; i < 2 ; i++) {
		for(int j = 0 ; j < 5 ; j++) {
			LoadParameters * p = new LoadParameters(static_cast<float> (200 + 200 * i), static_cast<float>(230 + 50 * j), "KeyboardChangeButton");
			keyboard_options.push_back(new KeyboardOptionButton());
			keyboard_options.back()->load(p);
			keyboard_options.back()->setAssociatedPlayer(PLAYER_NUM(i));
			keyboard_options.back()->setAssociatedControl(CONTROLS(j));
			delete p;
		}
	}

	text_rect.x = 0;
	text_rect.w = GameParameters::getGameWidth();

	text_rect.y = static_cast<int> (GameParameters::getGameHeight() * 0.5f);
	text_rect.h = 100;

	_callbacks.push_back(optionsToMenu);

	setCallbacks(_callbacks);

	is_loaded = true;

	return true;
}

bool OptionsState::onExit() {
	clearState();

	for (auto keyboard_option : keyboard_options) {
		keyboard_option->clean();
		delete keyboard_option;
	}

	keyboard_options.clear();

	FontManager::Instance()->clear();

	return true;
}

void OptionsState::optionsToMenu() {
	StateChangeAsker::askToChange(MAIN_MENU);
}