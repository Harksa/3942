#include "Sprite.h"

Sprite::Sprite(const std::string& textureID): _textureID(textureID) {
	const texture_informations texture = TextureManager::Instance()->getTextureInformationsFromID(textureID);
	_width = texture.width;
	_height = texture.height;
	_numFrames = texture.numFrames;
	_animSpeed = texture.animSpeed;
	_currentFrame = 0;
	_currentRow = 0;
	_angle = 0;
}

void Sprite::changeTextureID(const std::string& textureID) {
	_textureID = textureID;
	const texture_informations texture = TextureManager::Instance()->getTextureInformationsFromID(_textureID);
	_width = texture.width;
	_height = texture.height;
	_numFrames = texture.numFrames;
	_animSpeed = texture.animSpeed;
	_currentFrame = 0;
	_currentRow = 0;
}

std::string Sprite::getTextureID() const { return _textureID; }

void Sprite::draw(Vector2D position, Vector2D velocity) const {
	if(is_visible) {
		if(velocity.x > 0)
			TextureManager::Instance()->drawFrame(_textureID, int(position.x), int(position.y), _width, _height, _currentRow, _currentFrame, SDL_FLIP_HORIZONTAL);
		else
			TextureManager::Instance()->drawFrame(_textureID, int(position.x), int(position.y), _width, _height, _currentRow, _currentFrame);
	}
}

void Sprite::update() {
	if(_numFrames != 0) {
		_currentFrame = (((SDL_GetTicks() / (1000 / _animSpeed)) % _numFrames));
	}
}

void Sprite::setWidth(int width) { _width = width; }

int Sprite::getWidth() const { return _width; }

void Sprite::setHeight(int height) { _height = height; }

int Sprite::getHeight() const { return _height; }

void Sprite::setAngle(float angle) { _angle = angle; }

float Sprite::getAngle() const { return _angle; }

void Sprite::setNumFrames(int numFrames) { _numFrames = numFrames; }

int Sprite::getNumFrames() const { return _numFrames; }

void Sprite::setCurrentFrame(int frame) { _currentFrame = frame; }

int Sprite::getCurrentFrame() const { return _currentFrame; }

void Sprite::setVisibility(bool isVisible) { is_visible = isVisible; }

bool Sprite::getVisibility() const { return is_visible; }
