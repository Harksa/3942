#include "FontManager.h"
#include "Game.h"

FontManager * FontManager::instance{nullptr};

void FontManager::createFont(std::string font_name, const std::string& file_name, const unsigned int size, const SDL_Color color, const int style) {
	if(fonts.find(font_name) == fonts.end()) {
		FC_Font * font = FC_CreateFont();
		FC_LoadFont(font, Game::Instance()->getRenderer(), file_name.c_str(), size, color, style);

		fonts.insert(std::make_pair(font_name, font));
	} else {
		std::cout << "WARNING::FONTMANAGER::CREATEFONT::FONT " << font_name << "ALREADY EXIST" << std::endl;
	}
}

void FontManager::draw(const std::string& font_name, const unsigned int pos_x, const unsigned int pos_y, const std::string& text) const {
	if(fonts.find(font_name) != fonts.end())
		FC_Draw(fonts.at(font_name), Game::Instance()->getRenderer(), static_cast<float> (pos_x), static_cast<float> (pos_y), text.c_str());
	else
		std::cout << "ERROR::FONTMANAGER::DRAW::FONT " << font_name << "DOESN'T EXIST" << std::endl;
}

void FontManager::drawAlign(const std::string& font_name, const unsigned int pos_x, const unsigned int pos_y, const FC_AlignEnum align, const std::string& text) const {
	if(fonts.find(font_name) != fonts.end())
		FC_DrawAlign(fonts.at(font_name), Game::Instance()->getRenderer(), static_cast<float> (pos_x), static_cast<float>(pos_y), align, text.c_str());
	else
		std::cout << "ERROR::FONTMANAGER::DRAWALIGN::FONT " << font_name << "DOESN'T EXIST" << std::endl;
}

void FontManager::drawBoxAlign(const std::string& font_name, const SDL_Rect rect, const FC_AlignEnum align, const std::string& text) const {
	if(fonts.find(font_name) != fonts.end())
		FC_DrawBoxAlign(fonts.at(font_name), Game::Instance()->getRenderer(), rect, align, text.c_str());
	else
		std::cout << "ERROR::FONTMANAGER::DRAWBOXALIGN::FONT " << font_name << "DOESN'T EXIST" << std::endl;
}

void FontManager::clear() {
	for (auto const& font : fonts) {
		FC_ClearFont(font.second);
	}

	fonts.clear();
}