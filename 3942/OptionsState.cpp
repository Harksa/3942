#include "OptionsState.h"
#include "StateParser.h"
#include "Game.h"
#include "GameParameters.h"
#include "InputHandler.h"

std::string OptionsState::optionsID{"OPTIONS"};

std::vector<KeyboardOptionButton *> OptionsState::keyboard_options{};

void OptionsState::update() {

	if(KeyboardControls::Instance()->isAskingToChangeControls()) {
		_gameObjects[0]->getSprite()->setVisibility(true);

		const Uint8 * keys = InputHandler::getKeyStates();

		for(unsigned int i = 0 ; i < 255 ; i++) {
			if(keys[i] == 1) {
				KeyboardControls::Instance()->changeKey(SDL_Scancode(i));
				KeyboardControls::Instance()->askToChangeControls(false);
				_gameObjects[0]->getSprite()->setVisibility(false);
				break;
			}
		}

		return;
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
		FC_Draw(fc_font, Game::Instance()->getRenderer(), keyboard_option->getTextPosition().x, keyboard_option->getTextPosition().y, 
			SDL_GetScancodeName(KeyboardControls::Instance()->getKeyCode(keyboard_option->getPlayerNum(), keyboard_option->getAssociatedControl())) );
	}
	
	_gameObjects[0]->draw(); //Fond gris

	if(KeyboardControls::Instance()->isAskingToChangeControls()) {
		std::string string = "Select a key for player ";
		string += (1 + KeyboardControls::Instance()->getPlayerNumToChange());
		string += "for controls : ";
		string += KeyboardControls::Instance()->getControlToChange();

		FC_DrawAlign(fc_font, Game::Instance()->getRenderer(), 30, GameParameters::getGameHeight() * 0.5f, FC_ALIGN_LEFT, string.c_str());
	}
}

bool OptionsState::onEnter() {
	background = new Background();
	background->load("Textures/Backgrounds/Options.png", "options");

	StateParser::parseState("ressources/states.xml", optionsID, &_gameObjects, &_textureIDList);

	//Premier GameObject est le sprite de fond lors de la sélection d'une nouvelle touche
	_gameObjects.at(0)->getSprite()->setVisibility(false);

	fc_font = FC_CreateFont();
	FC_LoadFont(fc_font, Game::Instance()->getRenderer(), "Fonts/TEXWORK.ttf", 18, {255,255,255,255}, TTF_STYLE_NORMAL);

	for(int i = 0 ; i < 2 ; i++) {
		for(int j = 0 ; j < 5 ; j++) {
			LoadParameters * p = new LoadParameters(200 + 200 * i, 230 + 50 * j, "KeyboardChangeButton", i * j + j);
			keyboard_options.push_back(new KeyboardOptionButton());
			keyboard_options.back()->load(p);
			keyboard_options.back()->setAssociatedPlayer(PLAYER_NUM(i));
			keyboard_options.back()->setAssociatedControl(CONTROLS(j));
			delete p;
		}
	}

	_callbacks.push_back(optionsToMenu);

	setCallbacks(_callbacks);

	return true;
}

bool OptionsState::onExit() {
	clearState();

	for (auto keyboard_option : keyboard_options) {
		keyboard_option->clean();
		delete keyboard_option;
	}

	keyboard_options.clear();

	return true;
}

void OptionsState::optionsToMenu() {
	StateChangeAsker::askToChange(MAIN_MENU);
}