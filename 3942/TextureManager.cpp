#include "TextureManager.h"
#include <SDL2/SDL_image.h>

TextureManager * TextureManager::instance = nullptr;

TextureManager::~TextureManager() {}

bool TextureManager::load(const std::string& fileName, const std::string& id, SDL_Renderer * renderer) {
	SDL_Surface * surface = IMG_Load(fileName.c_str());

	if(surface == nullptr) return false;

	SDL_Texture * texture = SDL_CreateTextureFromSurface(renderer, surface);
	SDL_FreeSurface(surface);

	if(texture != nullptr) {
		_textureMap[id] = texture;
		return true;
	}

	return false;
}

bool TextureManager::load(const std::string &fileName, const std::string& id, const int width, const int height, const int numFrames, const int speed, SDL_Renderer * renderer) {
	SDL_Surface * surface = IMG_Load(fileName.c_str());

	if(surface == nullptr) return false;

	SDL_Texture * texture = SDL_CreateTextureFromSurface(renderer, surface);

	if(texture != nullptr) {
		_textureMap[id] = texture;
		_textureInformations[id] = new texture_informations(width, height, numFrames, speed);
		return true;
	}

	return false;
}

void TextureManager::draw(const std::string& id, const int x, const int y, const int width, const int height, SDL_Renderer * renderer, SDL_RendererFlip flip) {
	SDL_Rect srcRect, destRect;

	srcRect.x = srcRect.y = 0;
	srcRect.w = destRect.w = width;
	srcRect.h = destRect.h = height;

	destRect.x = x;
	destRect.y = y;
	
	SDL_RenderCopyEx(renderer, _textureMap[id], &srcRect, &destRect, 0, nullptr, flip);
}

void TextureManager::drawFrame(const std::string& id, const int x, const int y, const int width, const int height, const int currentRow, const int currentFrame, SDL_Renderer * pRenderer, SDL_RendererFlip flip) {
	SDL_Rect srcRect, destRect;

	srcRect.x = width * currentFrame;
	srcRect.y = height * currentRow;;

	srcRect.w = destRect.w = width;
	srcRect.h = destRect.h = height;

	destRect.x = x;
	destRect.y = y;

	SDL_RenderCopyEx(pRenderer, _textureMap[id], &srcRect, &destRect, 0, nullptr, flip);
}

void TextureManager::clearFromTextureMap(const std::string& id) {
	_textureMap.erase(id);
	_textureInformations.erase(id);
}


void TextureManager::drawTile(const std::string& id, const int margin, const int spacing, const int x, const int y, const int width, const int height, const int currentRow, const int currentFrame, SDL_Renderer * renderer) {
	SDL_Rect srcRect, destRect;

	srcRect.x = margin + (spacing + width) * currentFrame;
	srcRect.y = margin + (spacing + height) * currentRow;

	srcRect.w = destRect.w = width;
	srcRect.h = destRect.h = height;

	destRect.x = x;
	destRect.y = y;

	SDL_RenderCopyEx(renderer, _textureMap[id], &srcRect, &destRect, 0, nullptr, SDL_FLIP_NONE);
}
