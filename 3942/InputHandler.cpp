#include "InputHandler.h"
#include <iostream>
#include "Game.h"

bool InputHandler::_joystickInitialised{false};
std::vector<bool> InputHandler::_mouseButtonStates{false, false, false}; //Bouton gauche/milieu/droit
Vector2D * InputHandler::mousePosition = new Vector2D();
std::vector<SDL_Joystick*> InputHandler::_joysticks{};
int InputHandler::currentNumberOfJoysticks{0};
unsigned char const * InputHandler::keyStates = new unsigned char();

void InputHandler::initialiseJoysticks() {
	if(SDL_WasInit(SDL_INIT_JOYSTICK) == 0) {
		SDL_InitSubSystem(SDL_INIT_JOYSTICK);
	}

	if(SDL_NumJoysticks() > 0) {
		for (int i = 0 ; i < SDL_NumJoysticks() ; i++) {
			SDL_Joystick* joy = SDL_JoystickOpen(i);

			currentNumberOfJoysticks++;

			if(joy)
				_joysticks.push_back(joy);
		}

		SDL_JoystickEventState(SDL_ENABLE);

		_joystickInitialised = true;
		std::cout << "Initialised " << _joysticks.size() << " joystick(s)" << std::endl;
	} else {
		_joystickInitialised = false;
	}
}


void InputHandler::update() {
	SDL_Event event;

	while(SDL_PollEvent(&event)) {
		if(event.type == SDL_QUIT) {
			Game::Instance()->quit();
		}
		
		handleJoysticksConnection();
		keyStates = SDL_GetKeyboardState(nullptr);
		handleMouse(event);
	}
}

void InputHandler::handleJoysticksConnection() {
	if(currentNumberOfJoysticks != SDL_NumJoysticks()) {
		if(currentNumberOfJoysticks < SDL_NumJoysticks()) {
			_joysticks.push_back(SDL_JoystickOpen(currentNumberOfJoysticks));
			SDL_JoystickEventState(SDL_ENABLE);
			_joystickInitialised = true;
			currentNumberOfJoysticks++;
		} else {
			unsigned int detachedJoyID = 0;
			for(unsigned int i = 0 ; i < _joysticks.size() ; i++) {
				if(!SDL_JoystickGetAttached(_joysticks[i])) {
					detachedJoyID = i;
					break;
				}
			}
			SDL_JoystickClose(_joysticks[detachedJoyID]);
			_joysticks.pop_back();
			currentNumberOfJoysticks--;

			if(currentNumberOfJoysticks == 0)
				_joystickInitialised = false;
		}
	}

}

void InputHandler::handleMouse(SDL_Event& event) {
	if(event.type == SDL_MOUSEBUTTONDOWN) {
		if(event.button.button == SDL_BUTTON_LEFT)
			_mouseButtonStates[LEFT] = true;
		if (event.button.button == SDL_BUTTON_MIDDLE)
			_mouseButtonStates[MIDDLE] = true;
		if(event.button.button == SDL_BUTTON_RIGHT)
			_mouseButtonStates[RIGHT] = true;
	}

	if(event.type == SDL_MOUSEBUTTONUP) {
		if(event.button.button == SDL_BUTTON_LEFT)
			_mouseButtonStates[LEFT] = false;
		if (event.button.button == SDL_BUTTON_MIDDLE)
			_mouseButtonStates[MIDDLE] = false;
		if(event.button.button == SDL_BUTTON_RIGHT)
			_mouseButtonStates[RIGHT] = false;
	}

	if(event.type == SDL_MOUSEMOTION) {
		mousePosition->x = static_cast<float> (event.motion.x);
		mousePosition->y = static_cast<float> (event.motion.y);
	}
}

bool InputHandler::isKeyDown(SDL_Scancode key) {
	if(keyStates != nullptr) {
		return keyStates[key] == 1;
	}

	return false;
}


void InputHandler::clean() {
	if(_joystickInitialised) {
		unsigned int end = SDL_NumJoysticks();
		for(unsigned int i = 0 ; i < end ; i++) {
			SDL_JoystickClose(_joysticks[i]);
		}
	}
}

void InputHandler::reset()
{

    _mouseButtonStates[LEFT] = false;
    _mouseButtonStates[RIGHT] = false;
    _mouseButtonStates[MIDDLE] = false;
}

