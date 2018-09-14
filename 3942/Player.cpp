#include "Player.h"
#include "InputHandler.h"
#include "BulletManager.h"
#include "SoundManager.h"
#include "Game.h"

Player::Player() : GameObject() {
	bullet_sprite_width_by2 = static_cast<int> (TextureManager::Instance()->getTextureInformationsFromID("PlayerBullet")->width * 0.5f);
}

void Player::load(const LoadParameters* parameters) {
	GameObject::load(parameters);
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
	if(InputHandler::isKeyDown(SDL_SCANCODE_RIGHT) && position.x < (Game::Instance()->getGameWidth() - sprite->getWidth()))
		velocity.x = speed;
	if(InputHandler::isKeyDown(SDL_SCANCODE_UP)  && position.y > 0)
		velocity.y = -speed;
	if(InputHandler::isKeyDown(SDL_SCANCODE_DOWN) && position.y < (Game::Instance()->getGameHeight() - sprite->getHeight()))
		velocity.y = speed;

	if(InputHandler::isKeyDown(SDL_SCANCODE_SPACE))
		handleBulletSpawner();
		
	if(InputHandler::joystickInitialised()) {
		//Sticks analogiques
		const Sint16 leftX = SDL_JoystickGetAxis(InputHandler::getJoystickByID(0), SDL_CONTROLLER_AXIS_LEFTX);
		const Sint16 leftY = SDL_JoystickGetAxis(InputHandler::getJoystickByID(0), SDL_CONTROLLER_AXIS_LEFTY);

		if((leftX > InputHandler::_joystickDeadZone && position.x < (Game::Instance()->getGameWidth() - sprite->getWidth())) || 
			(leftX < -InputHandler::_joystickDeadZone) && position.x > 0)
			velocity.x = speed * leftX / InputHandler::diviser;
		if((leftY > InputHandler::_joystickDeadZone && position.y < (Game::Instance()->getGameHeight() - sprite->getHeight())) || 
			(leftY < -InputHandler::_joystickDeadZone && position.y > 0)) 
			velocity.y = speed * leftY / InputHandler::diviser;

		//DPAD
		if(SDL_JoystickGetHat(InputHandler::getJoystickByID(0), 0) == SDL_HAT_LEFT  && position.x > 0)
			velocity.x = -speed;
		else if(SDL_JoystickGetHat(InputHandler::getJoystickByID(0), 0) == SDL_HAT_RIGHT && position.x < (Game::Instance()->getGameWidth() - sprite->getWidth()))
			velocity.x = speed;
		else if(SDL_JoystickGetHat(InputHandler::getJoystickByID(0), 0) == SDL_HAT_UP && position.y > 0)
			velocity.y = -speed;
		else if(SDL_JoystickGetHat(InputHandler::getJoystickByID(0), 0) == SDL_HAT_DOWN  && position.y < (Game::Instance()->getGameHeight() - sprite->getHeight()))
			velocity.y = speed;

		else if(SDL_JoystickGetHat(InputHandler::getJoystickByID(0), 0) == SDL_HAT_LEFTUP) {
			if(position.x > 0)
				velocity.x = -speed;
			if(position.y > 0)
				velocity.y = - speed;
		} else if(SDL_JoystickGetHat(InputHandler::getJoystickByID(0), 0) == SDL_HAT_LEFTDOWN) {
			if(position.x > 0)
				velocity.x = -speed;
			if(position.y < (Game::Instance()->getGameHeight() - sprite->getHeight()))
				velocity.y = speed;
		}
		else if(SDL_JoystickGetHat(InputHandler::getJoystickByID(0), 0) == SDL_HAT_RIGHTUP) {
			if(position.x < (Game::Instance()->getGameWidth() - sprite->getWidth()))
				velocity.x = speed;
			if(position.y > 0)
				velocity.y = -speed;
		}
		else if(SDL_JoystickGetHat(InputHandler::getJoystickByID(0), 0) == SDL_HAT_RIGHTDOWN) {
			if(position.x < (Game::Instance()->getGameWidth() - sprite->getWidth()))
				velocity.x = speed;
			if(position.y < (Game::Instance()->getGameHeight() - sprite->getHeight()))
				velocity.y = speed;
		}

		//Boutons
		if(SDL_JoystickGetButton(InputHandler::getJoystickByID(0), SDL_CONTROLLER_BUTTON_A)) {
			handleBulletSpawner();
		}
	}


}

void Player::handleBulletSpawner() {
	if(timerFire <= 0) {
		SoundManager::playSound("PlayerLaser");
		BulletManager::Instance()->createPlayerBullet(Vector2D(position.x + static_cast<int> (sprite->getWidth() * 0.5f) - bullet_sprite_width_by2, position.y), Vector2D(0,-7.5f));
		timerFire = fireDelay;
	}
}
