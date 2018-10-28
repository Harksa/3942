#include "TextureManager.h"
#include <SDL2/SDL_image.h>
#include "Game.h"

TextureManager * TextureManager::instance{nullptr};

TextureManager* TextureManager::Instance() {
	if (instance == nullptr) {
		instance = new TextureManager();
	}

	return instance;
}

TextureManager::~TextureManager() {
	for (const auto& texture_map : texture_map) {
		clearFromTextureMapAndInformations(texture_map.first);
	}

	texture_map.clear();
	texture_informations.clear();
}

bool TextureManager::load(const std::string& pFileName, const std::string& pId) {
	SDL_Surface * surface = IMG_Load(pFileName.c_str());

	if(surface == nullptr) return false;

	SDL_Texture * texture = SDL_CreateTextureFromSurface(Game::Instance()->getRenderer(), surface);
	SDL_FreeSurface(surface);

	if(texture != nullptr) {
		texture_map[pId] = texture;
		return true;
	}

	return false;
}

bool TextureManager::load(const std::string &pFileName, const std::string& pId, const int pWidth, const int pHeight, const int pNumFrames, const int pSpeed) {
	SDL_Surface * surface = IMG_Load(pFileName.c_str());

	if(surface == nullptr) return false;

	SDL_Texture * texture = SDL_CreateTextureFromSurface(Game::Instance()->getRenderer(), surface);

	if(texture != nullptr) {
		texture_map[pId] = texture;
		texture_informations[pId] = Texture_Informations(pWidth, pHeight, pNumFrames, pSpeed);
		return true;
	}

	return false;
}

void TextureManager::draw(const std::string& pId, const int pX, const int pY, const int pWidth, const int pHeight, const SDL_RendererFlip pFlip) {
	SDL_Rect srcRect, destRect;

	srcRect.x = srcRect.y = 0;
	srcRect.w = destRect.w = pWidth;
	srcRect.h = destRect.h = pHeight;

	destRect.x = pX;
	destRect.y = pY;
	
	SDL_RenderCopyEx(Game::Instance()->getRenderer(), texture_map[pId], &srcRect, &destRect, 0, nullptr, pFlip);
}

void TextureManager::drawFrame(const std::string& pId, const int pX, const int pY, const int pWidth, const int pHeight, const int pCurrentRow, const int pCurrentFrame, const SDL_RendererFlip pFlip) {
	SDL_Rect srcRect, destRect;

    srcRect.x = pWidth * pCurrentFrame;
	srcRect.y = pHeight * pCurrentRow;

	srcRect.w = destRect.w = pWidth;
	srcRect.h = destRect.h = pHeight;

	destRect.x = pX;
	destRect.y = pY;

	SDL_RenderCopyEx(Game::Instance()->getRenderer(), texture_map[pId], &srcRect, &destRect, 0, nullptr, pFlip);
}

void TextureManager::clearFromTextureMapAndInformations(const std::string& pId) {
	clearFromTextureMap(pId);
	texture_informations.erase(pId);
}

void TextureManager::clearFromTextureMap(const std::string& pId) {
	SDL_DestroyTexture(texture_map.at(pId));
	texture_map.erase(pId);
}


void TextureManager::drawTile(const std::string& pId, const int pMargin, const int pSpacing, const int pX, const int pY, const int pWidth, const int pHeight, const int pCurrentRow, const int pCurrentFrame) {
	SDL_Rect srcRect, destRect;

	srcRect.x = pMargin + (pSpacing + pWidth) * pCurrentFrame;
	srcRect.y = pMargin + (pSpacing + pHeight) * pCurrentRow;

	srcRect.w = destRect.w = pWidth;
	srcRect.h = destRect.h = pHeight;

	destRect.x = pX;
	destRect.y = pY;

	SDL_RenderCopyEx(Game::Instance()->getRenderer(), texture_map[pId], &srcRect, &destRect, 0, nullptr, SDL_FLIP_NONE);
}

Texture_Informations TextureManager::getTextureInformationsFromID(const std::string& pId) {
	return texture_informations[pId];
}
