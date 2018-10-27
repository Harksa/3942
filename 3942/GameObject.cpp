#include "GameObject.h"
#include "GameParameters.h"

void GameObject::load(const LoadParameters* parameters) {
	position = Vector2D(parameters->getX(), parameters->getY());
	velocity = acceleration = Vector2D(0, 0);

	sprite = new Sprite(parameters->getTextureID());
}

void GameObject::draw() {
	sprite->draw(position, velocity);
}

void GameObject::update() {
	sprite->update();
	velocity += acceleration;
	position += velocity;
}

void GameObject::clean() {
	if(!is_already_cleaned) {
		delete sprite;
		is_already_cleaned = true;
	}
}

bool GameObject::isOutsideScreenBondaries() const {
	return
		(position.x + sprite->getWidth()) < 0 || 
		(position.y + sprite->getHeight()) < 0 ||
		(position.x - sprite->getWidth()) > GameParameters::getGameWidth() ||
		(position.y - sprite->getHeight()) > GameParameters::getGameHeight();
}

Vector2D& GameObject::getPosition() { return position; }

void GameObject::setPosition(Vector2D newPosition) { position = newPosition; }

void GameObject::setPosition(float new_x, float new_y) {
	position.x = new_x;
	position.y = new_y;
}

void GameObject::setVelocity(Vector2D new_velocity) { velocity = new_velocity; }

void GameObject::setVelocity(float new_x, float new_y) {
	velocity.x = new_x;
	velocity.y = new_y;
}

void GameObject::setSpriteAngle(float new_angle) const {
	sprite->setAngle(new_angle);
}

int GameObject::getWidth() const { return sprite->getWidth(); }

int GameObject::getHeight() const { return sprite->getHeight(); }

Sprite* GameObject::getSprite() const { return sprite; }

bool GameObject::isDead() const { return is_dead; }

SDL_Rect GameObject::getRect() const {
	SDL_Rect tmp_rect;

	tmp_rect.x = static_cast<int>(position.x);
	tmp_rect.y = static_cast<int>(position.y);
	tmp_rect.w = static_cast<int>(sprite->getWidth());
	tmp_rect.h = static_cast<int>(sprite->getHeight());

	return tmp_rect;
}

GameObject::~GameObject() {
	if (!is_already_cleaned) {
		delete sprite;
	}
}
