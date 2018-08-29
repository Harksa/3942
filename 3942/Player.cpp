#include "Player.h"
#include "InputHandler.h"

Player::Player() : SDLGameObject() {

}

void Player::load(const LoadParameters* parameters) {
	SDLGameObject::load(parameters);
}


void Player::draw() {
	SDLGameObject::draw();
}

void Player::update() {
	velocity.x = 0; velocity.y = 0;
	handleInput();

	SDLGameObject::update();
}

void Player::clean() {}

void Player::handleInput() {

	if(InputHandler::Instance()->joystickInitialised()) {
		//Sticks analogiques
		const Sint16 leftX = SDL_JoystickGetAxis(InputHandler::Instance()->getJoystickByID(0), SDL_CONTROLLER_AXIS_LEFTX);
		const Sint16 leftY = SDL_JoystickGetAxis(InputHandler::Instance()->getJoystickByID(0), SDL_CONTROLLER_AXIS_LEFTY);

		if(leftX > InputHandler::Instance()->getJoystickDeadZone() || leftX < -InputHandler::Instance()->getJoystickDeadZone())
			velocity.x = speed * leftX / InputHandler::Instance()->getDiviser();
		if(leftY > InputHandler::Instance()->getJoystickDeadZone() || leftY < -InputHandler::Instance()->getJoystickDeadZone())
			velocity.y = speed * leftY / InputHandler::Instance()->getDiviser();


		//DPAD
		if(SDL_JoystickGetHat(InputHandler::Instance()->getJoystickByID(0), 0) == SDL_HAT_LEFT)
			velocity.x = -speed;
		else if(SDL_JoystickGetHat(InputHandler::Instance()->getJoystickByID(0), 0) == SDL_HAT_RIGHT)
			velocity.x = speed;
		else if(SDL_JoystickGetHat(InputHandler::Instance()->getJoystickByID(0), 0) == SDL_HAT_UP)
			velocity.y = -speed;
		else if(SDL_JoystickGetHat(InputHandler::Instance()->getJoystickByID(0), 0) == SDL_HAT_DOWN)
			velocity.y = speed;

		else if(SDL_JoystickGetHat(InputHandler::Instance()->getJoystickByID(0), 0) == SDL_HAT_LEFTUP) {
			velocity.x = -speed;
			velocity.y = -speed;
		} 
		else if(SDL_JoystickGetHat(InputHandler::Instance()->getJoystickByID(0), 0) == SDL_HAT_LEFTDOWN) {
			velocity.x = -speed;
			velocity.y = speed;
		}
		else if(SDL_JoystickGetHat(InputHandler::Instance()->getJoystickByID(0), 0) == SDL_HAT_RIGHTUP) {
			velocity.x = speed;
			velocity.y = -speed;
		}
		else if(SDL_JoystickGetHat(InputHandler::Instance()->getJoystickByID(0), 0) == SDL_HAT_RIGHTDOWN) {
			velocity.x = speed;
			velocity.y = speed;
		}
	}

}
