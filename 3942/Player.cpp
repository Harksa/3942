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
		const Sint16 leftX = SDL_JoystickGetAxis(InputHandler::Instance()->getJoystickByID(0), SDL_CONTROLLER_AXIS_LEFTX);
		const Sint16 leftY = SDL_JoystickGetAxis(InputHandler::Instance()->getJoystickByID(0), SDL_CONTROLLER_AXIS_LEFTY);

		if(leftX > InputHandler::Instance()->getJoystickDeadZone() || leftX < -InputHandler::Instance()->getJoystickDeadZone())
			velocity.x = speed * leftX / InputHandler::Instance()->getDiviser();
		if(leftY > InputHandler::Instance()->getJoystickDeadZone() || leftY < -InputHandler::Instance()->getJoystickDeadZone())
			velocity.y = speed * leftY / InputHandler::Instance()->getDiviser();
	}
}
