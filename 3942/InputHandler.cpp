#include "InputHandler.h"
#include "Game.h"

bool InputHandler::_joystickInitialised{false};
std::vector<bool> InputHandler::_mouseButtonStates{false, false, false}; //Bouton gauche/milieu/droit
Vector2D * InputHandler::mousePosition = new Vector2D();
bool InputHandler::is_connected[2]{false, false};
SDL_Joystick * InputHandler::joystick_arrays[2];
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

			if(joy) {
				joystick_arrays[i] = joy;
				is_connected[i] = true;
			}
		}

		SDL_JoystickEventState(SDL_ENABLE);

		_joystickInitialised = true;
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
			for(unsigned int i = 0 ; i < MAX_PLAYER_COUNT ; i++) {
				if(!SDL_JoystickGetAttached(joystick_arrays[i])) {
					joystick_arrays[i] = SDL_JoystickOpen(i);
					is_connected[i] = true;
					break;
				}
			}

			SDL_JoystickEventState(SDL_ENABLE);
			_joystickInitialised = true;
			currentNumberOfJoysticks++;
		} else {

			for(int i = 0 ; i < MAX_PLAYER_COUNT ; i++) {
				if(!is_connected[i]) {
					if(!SDL_JoystickGetAttached(joystick_arrays[i])) {
						SDL_JoystickClose(joystick_arrays[i]);
						is_connected[i] = false;
						break;
					}
				}
			}
			
			currentNumberOfJoysticks--;

			if(currentNumberOfJoysticks == 0)
				_joystickInitialised = false;
		}
	}

}

void InputHandler::handleMouse(SDL_Event& event) {
	if(event.type == SDL_MOUSEBUTTONDOWN) {
		if(event.button.button == SDL_BUTTON_LEFT)
			_mouseButtonStates[LEFT_BUTTON] = true;
		if (event.button.button == SDL_BUTTON_MIDDLE)
			_mouseButtonStates[MIDDLE_BUTTON] = true;
		if(event.button.button == SDL_BUTTON_RIGHT)
			_mouseButtonStates[RIGHT_BUTTON] = true;
	}

	if(event.type == SDL_MOUSEBUTTONUP) {
		if(event.button.button == SDL_BUTTON_LEFT)
			_mouseButtonStates[LEFT_BUTTON] = false;
		if (event.button.button == SDL_BUTTON_MIDDLE)
			_mouseButtonStates[MIDDLE_BUTTON] = false;
		if(event.button.button == SDL_BUTTON_RIGHT)
			_mouseButtonStates[RIGHT_BUTTON] = false;
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
		for(unsigned int i = 0 ; i < MAX_PLAYER_COUNT ; i++) {
			if(is_connected[i]) {
				SDL_JoystickClose(joystick_arrays[i]);
				is_connected[i] = false;
			}
		}
	}
}

void InputHandler::reset() {
    _mouseButtonStates[LEFT_BUTTON] = false;
    _mouseButtonStates[RIGHT_BUTTON] = false;
    _mouseButtonStates[MIDDLE_BUTTON] = false;
}

