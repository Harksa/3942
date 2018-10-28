#include "InputHandler.h"
#include "Game.h"
#include "GameParameters.h"

bool InputHandler::joystick_initialised{false};
std::vector<bool> InputHandler::mouse_button_states{false, false, false}; //Bouton gauche/milieu/droit
Vector2D * InputHandler::mouse_position = new Vector2D();
bool InputHandler::is_connected[2]{false, false};
SDL_Joystick * InputHandler::joystick_arrays[2];
int InputHandler::current_number_of_joysticks{0};
unsigned char const * InputHandler::key_states = new unsigned char();

void InputHandler::initialiseJoysticks() {
	if(SDL_WasInit(SDL_INIT_JOYSTICK) == 0) {
		SDL_InitSubSystem(SDL_INIT_JOYSTICK);
	}

	if(SDL_NumJoysticks() > 0) {
		for (int i = 0 ; i < SDL_NumJoysticks() ; i++) {
			SDL_Joystick* joy = SDL_JoystickOpen(i);

			current_number_of_joysticks++;

			if(joy) {
				joystick_arrays[i] = joy;
				is_connected[i] = true;
			}
		}

		SDL_JoystickEventState(SDL_ENABLE);

		joystick_initialised = true;
	} else {
		joystick_initialised = false;
	}
}

void InputHandler::update() {
	SDL_Event event;

	while(SDL_PollEvent(&event)) {
		if(event.type == SDL_QUIT) {
			Game::Instance()->quit();
		}

		handleJoysticksConnection();
		key_states = SDL_GetKeyboardState(nullptr);
		handleMouse(event);
	}
}

void InputHandler::handleJoysticksConnection() {
	if(current_number_of_joysticks != SDL_NumJoysticks()) {
		if(current_number_of_joysticks < SDL_NumJoysticks()) {
			for(unsigned int i = 0 ; i < MAX_PLAYER_COUNT ; i++) {
				if(!SDL_JoystickGetAttached(joystick_arrays[i])) {
					joystick_arrays[i] = SDL_JoystickOpen(i);
					is_connected[i] = true;
					break;
				}
			}

			SDL_JoystickEventState(SDL_ENABLE);
			joystick_initialised = true;
			current_number_of_joysticks++;
		} else {

			for(unsigned int i = 0 ; i < MAX_PLAYER_COUNT ; i++) {
				if(!is_connected[i]) {
					if(!SDL_JoystickGetAttached(joystick_arrays[i])) {
						SDL_JoystickClose(joystick_arrays[i]);
						is_connected[i] = false;
						break;
					}
				}
			}
			
			current_number_of_joysticks--;

			if(current_number_of_joysticks == 0)
				joystick_initialised = false;
		}
	}

}

bool InputHandler::areNumberOfJoysticksEgalsToNumberOfPlayersUsingJoysticks() {
	if(GameParameters::isTwoPlayer()) {
		if(!GameParameters::isPlayerUsingKeyboard(PLAYER_1) && !GameParameters::isPlayerUsingKeyboard(PLAYER_2) && current_number_of_joysticks != 2 ||
		   (!GameParameters::isPlayerUsingKeyboard(PLAYER_1) && GameParameters::isPlayerUsingKeyboard(PLAYER_2) ||
		   GameParameters::isPlayerUsingKeyboard(PLAYER_1) && !GameParameters::isPlayerUsingKeyboard(PLAYER_2)) && current_number_of_joysticks < 1) {
			return false;
		}
	} else if (!GameParameters::isPlayerUsingKeyboard(PLAYER_1) && current_number_of_joysticks < 1) {
		return false;
	}

	return true;
}

void InputHandler::handleMouse(SDL_Event& pEvent) {
	if(pEvent.type == SDL_MOUSEBUTTONDOWN) {
		if(pEvent.button.button == SDL_BUTTON_LEFT)
			mouse_button_states[LEFT_BUTTON] = true;
		if (pEvent.button.button == SDL_BUTTON_MIDDLE)
			mouse_button_states[MIDDLE_BUTTON] = true;
		if(pEvent.button.button == SDL_BUTTON_RIGHT)
			mouse_button_states[RIGHT_BUTTON] = true;
	}

	if(pEvent.type == SDL_MOUSEBUTTONUP) {
		if(pEvent.button.button == SDL_BUTTON_LEFT)
			mouse_button_states[LEFT_BUTTON] = false;
		if (pEvent.button.button == SDL_BUTTON_MIDDLE)
			mouse_button_states[MIDDLE_BUTTON] = false;
		if(pEvent.button.button == SDL_BUTTON_RIGHT)
			mouse_button_states[RIGHT_BUTTON] = false;
	}

	if(pEvent.type == SDL_MOUSEMOTION) {
		mouse_position->x = static_cast<float> (pEvent.motion.x);
		mouse_position->y = static_cast<float> (pEvent.motion.y);
	}
}

bool InputHandler::isKeyDown(const SDL_Scancode pKey) {
	if(key_states != nullptr) {
		return key_states[pKey] == 1;
	}

	return false;
}


void InputHandler::clean() {
	if(joystick_initialised) {
		for(unsigned int i = 0 ; i < MAX_PLAYER_COUNT ; i++) {
			if(is_connected[i]) {
				SDL_JoystickClose(joystick_arrays[i]);
				is_connected[i] = false;
			}
		}
	}
}

void InputHandler::reset() {
    mouse_button_states[LEFT_BUTTON] = false;
    mouse_button_states[RIGHT_BUTTON] = false;
    mouse_button_states[MIDDLE_BUTTON] = false;
}

bool InputHandler::joystickInitialised() { return joystick_initialised; }

bool InputHandler::getMouseButtonState(const int pButtonNumber) { return mouse_button_states[pButtonNumber]; }

Vector2D* InputHandler::getMousePosition() { return mouse_position; }

SDL_Joystick* InputHandler::getJoystickByID(const int pId) { return joystick_arrays[pId]; }

unsigned InputHandler::getNumberOfJoysticks() { return SDL_NumJoysticks(); }

const Uint8* InputHandler::getKeyStates() { return key_states; }
