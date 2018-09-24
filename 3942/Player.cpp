#include "Player.h"
#include "InputHandler.h"
#include "BulletManager.h"
#include "SoundManager.h"
#include "GameParameters.h"

void Player::load(const LoadParameters* parameters) {
	GameObject::load(parameters);

	bullet_sprite_width_by2 = static_cast<int> (TextureManager::Instance()->getTextureInformationsFromID("PlayerBullet").width * 0.5f);
	is_dead = false;
}

void Player::draw() {
	GameObject::draw();
}

void Player::update() {
	velocity.x = 0; velocity.y = 0;
	handleInput();

	GameObject::update();

	timerFire--;
}

void Player::clean() {
	GameObject::clean();
}

void Player::onCollision() {
	lives--;

	if(lives >= 0)
		is_dead = true;
}

void Player::handleInput() {

	//Gestion clavier
	if(InputHandler::isKeyDown(SDL_SCANCODE_LEFT) && position.x > 0)
		velocity.x = -speed;
	if(InputHandler::isKeyDown(SDL_SCANCODE_RIGHT) && position.x < (GameParameters::getGameWidth() - sprite->getWidth()))
		velocity.x = speed;
	if(InputHandler::isKeyDown(SDL_SCANCODE_UP)  && position.y > 0)
		velocity.y = -speed;
	if(InputHandler::isKeyDown(SDL_SCANCODE_DOWN) && position.y < (GameParameters::getGameHeight() - sprite->getHeight()))
		velocity.y = speed;

	if(InputHandler::isKeyDown(SDL_SCANCODE_SPACE))
		handleBulletSpawner();
		
	if(InputHandler::joystickInitialised()) {
		//Sticks analogiques
		const Sint16 leftX = SDL_JoystickGetAxis(InputHandler::getJoystickByID(id), SDL_CONTROLLER_AXIS_LEFTX);
		const Sint16 leftY = SDL_JoystickGetAxis(InputHandler::getJoystickByID(id), SDL_CONTROLLER_AXIS_LEFTY);

		if((leftX > InputHandler::_joystickDeadZone && position.x < (GameParameters::getGameWidth() - sprite->getWidth())) || 
			(leftX < -InputHandler::_joystickDeadZone) && position.x > 0)
			velocity.x = speed * leftX / InputHandler::diviser;
		if((leftY > InputHandler::_joystickDeadZone && position.y < (GameParameters::getGameHeight() - sprite->getHeight())) || 
			(leftY < -InputHandler::_joystickDeadZone && position.y > 0)) 
			velocity.y = speed * leftY / InputHandler::diviser;

		//DPAD
		if(SDL_JoystickGetHat(InputHandler::getJoystickByID(id), 0) == SDL_HAT_LEFT  && position.x > 0)
			velocity.x = -speed;
		else if(SDL_JoystickGetHat(InputHandler::getJoystickByID(id), 0) == SDL_HAT_RIGHT && position.x < (GameParameters::getGameWidth() - sprite->getWidth()))
			velocity.x = speed;
		else if(SDL_JoystickGetHat(InputHandler::getJoystickByID(id), 0) == SDL_HAT_UP && position.y > 0)
			velocity.y = -speed;
		else if(SDL_JoystickGetHat(InputHandler::getJoystickByID(id), 0) == SDL_HAT_DOWN  && position.y < (GameParameters::getGameHeight() - sprite->getHeight()))
			velocity.y = speed;

		else if(SDL_JoystickGetHat(InputHandler::getJoystickByID(id), 0) == SDL_HAT_LEFTUP) {
			if(position.x > 0)
				velocity.x = -speed;
			if(position.y > 0)
				velocity.y = - speed;
		} else if(SDL_JoystickGetHat(InputHandler::getJoystickByID(id), 0) == SDL_HAT_LEFTDOWN) {
			if(position.x > 0)
				velocity.x = -speed;
			if(position.y < (GameParameters::getGameHeight() - sprite->getHeight()))
				velocity.y = speed;
		}
		else if(SDL_JoystickGetHat(InputHandler::getJoystickByID(id), 0) == SDL_HAT_RIGHTUP) {
			if(position.x < (GameParameters::getGameWidth()  - sprite->getWidth()))
				velocity.x = speed;
			if(position.y > 0)
				velocity.y = -speed;
		}
		else if(SDL_JoystickGetHat(InputHandler::getJoystickByID(id), 0) == SDL_HAT_RIGHTDOWN) {
			if(position.x < (GameParameters::getGameWidth() - sprite->getWidth()))
				velocity.x = speed;
			if(position.y < (GameParameters::getGameHeight() - sprite->getHeight()))
				velocity.y = speed;
		}

		//Boutons
		if(SDL_JoystickGetButton(InputHandler::getJoystickByID(id), SDL_CONTROLLER_BUTTON_A)) {
			handleBulletSpawner();
		}
	}

}

void Player::handleBulletSpawner() {
	if(timerFire <= 0) {
		SoundManager::playSound("PlayerLaser");
		BulletManager::Instance()->createPlayerBullet(id, Vector2D(position.x + static_cast<int> (sprite->getWidth() * 0.5f) - bullet_sprite_width_by2, position.y), Vector2D(0,-7.5f));
		timerFire = fireDelay;
	}
}
