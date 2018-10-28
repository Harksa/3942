#include "FontManager.h"
#include "Game.h"
#include <iostream>

FontManager * FontManager::instance{nullptr};

FontManager* FontManager::Instance() {
	if (instance == nullptr)
		instance = new FontManager();

	return instance;
}

void FontManager::createFont(std::string pFontName, const std::string& pFileName, const unsigned int pSize, const SDL_Color pColor, const int pStyle) {
	if(fonts.find(pFontName) == fonts.end()) {
		FC_Font * font = FC_CreateFont();
		FC_LoadFont(font, Game::Instance()->getRenderer(), pFileName.c_str(), pSize, pColor, pStyle);

		fonts.insert(std::make_pair(pFontName, font));
	} else {
		std::cout << "WARNING::FONTMANAGER::CREATEFONT::FONT " << pFontName << "ALREADY EXIST" << std::endl;
	}
}

void FontManager::draw(const std::string& pFontName, const unsigned int pPosX, const unsigned int pPosY, const std::string& pText) const {
	if(fonts.find(pFontName) != fonts.end())
		FC_Draw(fonts.at(pFontName), Game::Instance()->getRenderer(), static_cast<float> (pPosX), static_cast<float> (pPosY), pText.c_str());
	else
		std::cout << "ERROR::FONTMANAGER::DRAW::FONT " << pFontName << "DOESN'T EXIST" << std::endl;
}

void FontManager::drawAlign(const std::string& pFontName, const unsigned int pPosX, const unsigned int pPosY, const FC_AlignEnum pAlign, const std::string& pText) const {
	if(fonts.find(pFontName) != fonts.end())
		FC_DrawAlign(fonts.at(pFontName), Game::Instance()->getRenderer(), static_cast<float> (pPosX), static_cast<float>(pPosY), pAlign, pText.c_str());
	else
		std::cout << "ERROR::FONTMANAGER::DRAWALIGN::FONT " << pFontName << "DOESN'T EXIST" << std::endl;
}

void FontManager::drawBoxAlign(const std::string& pFontName, const SDL_Rect pRect, const FC_AlignEnum pAlign, const std::string& pText) const {
	if(fonts.find(pFontName) != fonts.end())
		FC_DrawBoxAlign(fonts.at(pFontName), Game::Instance()->getRenderer(), pRect, pAlign, pText.c_str());
	else
		std::cout << "ERROR::FONTMANAGER::DRAWBOXALIGN::FONT " << pFontName << "DOESN'T EXIST" << std::endl;
}

void FontManager::clear() {
	for (auto const& font : fonts) {
		FC_ClearFont(font.second);
	}

	fonts.clear();
}