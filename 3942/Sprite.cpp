#include "Sprite.h"

void Sprite::draw(Vector2D position, Vector2D velocity) const {
	if(velocity.x > 0)
		TextureManager::Instance()->drawFrame(_textureID, int(position.x), int(position.y), _width, _height, _currentRow, _currentFrame, Game::Instance()->getRenderer(), SDL_FLIP_HORIZONTAL);
	else
		TextureManager::Instance()->drawFrame(_textureID, int(position.x), int(position.y), _width, _height, _currentRow, _currentFrame, Game::Instance()->getRenderer());
}

void Sprite::update() {
	if(_animSpeed != 0) {
		_currentFrame = (((SDL_GetTicks() / (1000 / _animSpeed)) % _numFrames));
	}
}