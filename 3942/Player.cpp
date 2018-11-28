#include "Player.h"
#include "BulletManager.h"
#include "GameParameters.h"
#include "InputHandler.h"
#include "KeyboardControls.h"
#include "SoundManager.h"

Player::Player(const PLAYER_NUM pNum): id{pNum} {}

void Player::load(const LoadParameters* parameters) {
	GameObject::load(parameters);

	bullet_sprite_width_by2 = static_cast<int> (TextureManager::Instance()->getTextureInformationsFromID("PlayerBullet").width * 0.5f);
}

void Player::draw() {
	GameObject::draw();
}

void Player::update() {
	velocity.x = 0; velocity.y = 0;
	handleInput();

	GameObject::update();

	timer_fire--;
}

void Player::clean() {
	GameObject::clean();
}

void Player::onCollision() {
	lives--;

	if(lives <= 0) {
		changeSprite("Explosion");
		SoundManager::playSound("Explosion");
		is_dying = true;
	}
}

void Player::handleInput() {

	//Gestion clavier
	if(InputHandler::isKeyDown(KeyboardControls::Instance()->getKeyCode(id, MOVE_LEFT_KEY)) && position.x > 0)
		velocity.x = -speed;
	if(InputHandler::isKeyDown(KeyboardControls::Instance()->getKeyCode(id, MOVE_RIGHT_KEY)) && position.x < (GameParameters::getGameWidth() - sprite->getWidth()))
		velocity.x = speed;
	if(InputHandler::isKeyDown(KeyboardControls::Instance()->getKeyCode(id, MOVE_UP_KEY))  && position.y > 0)
		velocity.y = -speed;
	if(InputHandler::isKeyDown(KeyboardControls::Instance()->getKeyCode(id, MOVE_DOWN_KEY)) && position.y < (GameParameters::getGameHeight() - sprite->getHeight()))
		velocity.y = speed;

	if(InputHandler::isKeyDown(KeyboardControls::Instance()->getKeyCode(id, FIRE_KEY)))
		handleBulletSpawner();
		
	if(InputHandler::joystickInitialised()) {
		//Sticks analogiques
		const Sint16 leftX = SDL_JoystickGetAxis(InputHandler::getJoystickByID(id), SDL_CONTROLLER_AXIS_LEFTX);
		const Sint16 leftY = SDL_JoystickGetAxis(InputHandler::getJoystickByID(id), SDL_CONTROLLER_AXIS_LEFTY);

		if((leftX > InputHandler::joystick_dead_zone && position.x < (GameParameters::getGameWidth() - sprite->getWidth())) || 
			(leftX < -InputHandler::joystick_dead_zone) && position.x > 0)
			velocity.x = speed * leftX / InputHandler::diviser;
		if((leftY > InputHandler::joystick_dead_zone && position.y < (GameParameters::getGameHeight() - sprite->getHeight())) || 
			(leftY < -InputHandler::joystick_dead_zone && position.y > 0)) 
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
	if(timer_fire <= 0) {
		SoundManager::playSound("PlayerLaser");
		BulletManager::Instance()->createPlayerBullet(id, Vector2D(position.x + static_cast<int> (sprite->getWidth() * 0.5f) - bullet_sprite_width_by2, position.y), Vector2D(0,-7.5f));
		timer_fire = fire_delay;
	}
}

void Player::setJoystickID(const unsigned int pJoyId) { joystick_id = pJoyId; }

unsigned Player::getJoystickID() const { return joystick_id; }

bool Player::isJoyConnected() const { return InputHandler::getJoystickByID(joystick_id) != nullptr; }
