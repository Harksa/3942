#include "Player.h"
#include "InputHandler.h"
#include "BulletManager.h"

Player::Player() : SDLGameObject() {
	bullet_sprite_width_by2 = TextureManager::Instance()->getTextureInformationsFromID("bullet")->width * 0.5f;
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

	timerFire--;
}

void Player::clean() {}

void Player::handleInput() {

	//Gestion clavier
	if(InputHandler::Instance()->isKeyDown(SDL_SCANCODE_LEFT))
		velocity.x = -speed;
	if(InputHandler::Instance()->isKeyDown(SDL_SCANCODE_RIGHT))
		velocity.x = speed;
	if(InputHandler::Instance()->isKeyDown(SDL_SCANCODE_UP))
		velocity.y = -speed;
	if(InputHandler::Instance()->isKeyDown(SDL_SCANCODE_DOWN))
		velocity.y = speed;

	if(InputHandler::Instance()->isKeyDown(SDL_SCANCODE_SPACE))
		handleBulletSpawner();
		
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

		//Boutons
		if(SDL_JoystickGetButton(InputHandler::Instance()->getJoystickByID(0), SDL_CONTROLLER_BUTTON_A)) {
			handleBulletSpawner();
		}
	}

}

void Player::handleBulletSpawner() {
	if(timerFire <= 0) {
		BulletManager::Instance()->create(Vector2D( position.x + static_cast<int> (sprite->getWidth() * 0.5f) - bullet_sprite_width_by2, position.y), Vector2D(0,-5));
		timerFire = fireDelay;
	}
}
