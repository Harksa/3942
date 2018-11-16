#include "GameObject.h"
#include "GameParameters.h"

void GameObject::load(const LoadParameters* pParameters) {
	position = Vector2D(pParameters->getX(), pParameters->getY());
	velocity = acceleration = Vector2D(0, 0);

	sprite = new Sprite(pParameters->getTextureID());
}

void GameObject::draw() {
	if(!isOutsideScreenBondaries())
		sprite->draw(position, velocity);
}

void GameObject::update() {
	if(!isOutsideScreenBondaries()) {
		sprite->update();
	}

	if(!isDying()) {
		velocity += acceleration;
		position += velocity;
	} else {
		if(sprite->isPlayingLastFrame()) {
			is_dead = true;
		}
	}
}

void GameObject::clean() {
	if(!is_already_cleaned) {
		delete sprite;
		is_already_cleaned = true;
	}
}

void GameObject::changeSprite(std::string pTextureId) {
	const Texture_Informations texture_informations = TextureManager::Instance()->getTextureInformationsFromID(pTextureId);

	const Vector2D new_position{position.x + sprite->getWidth() * 0.5f - texture_informations.width * 0.5f, position.y + sprite->getHeight() * 0.5f - texture_informations.height * 0.5f};
	sprite->changeTextureID(pTextureId);
	position = new_position;
}

bool GameObject::isOutsideScreenBondaries() const {
	return
		(position.x + sprite->getWidth()) < 0 || 
		(position.y + sprite->getHeight()) < 0 ||
		(position.x - sprite->getWidth()) > GameParameters::getGameWidth() ||
		(position.y - sprite->getHeight()) > GameParameters::getGameHeight();
}

Vector2D& GameObject::getPosition() { return position; }

void GameObject::setPosition(const Vector2D pNewPosition) { position = pNewPosition; }

void GameObject::setPosition(const float pNewX, const float pNewY) {
	position.x = pNewX;
	position.y = pNewY;
}

void GameObject::setVelocity(const Vector2D pNewVelocity) { velocity = pNewVelocity; }

void GameObject::setVelocity(const float pNewX, const float pNewY) {
	velocity.x = pNewX;
	velocity.y = pNewY;
}

void GameObject::setSpriteAngle(const float pNewAngle) const {
	sprite->setAngle(pNewAngle);
}

int GameObject::getWidth() const { return sprite->getWidth(); }

int GameObject::getHeight() const { return sprite->getHeight(); }

Sprite* GameObject::getSprite() const { return sprite; }

bool GameObject::isDead() const { return is_dead; }

bool GameObject::isDying() const {
	return is_dying;
}

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
