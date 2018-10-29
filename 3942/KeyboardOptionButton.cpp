#include "KeyboardOptionButton.h"
#include "InputHandler.h"
#include "FontManager.h"

void KeyboardOptionButton::load(const LoadParameters* pParameters) {
	MenuButton::load(pParameters);

	setCallback(std::bind(&KeyboardOptionButton::callbackFunction, this));

	text_rect = getRect();
	text_rect.y += 10;
}

void KeyboardOptionButton::draw() {
	MenuButton::draw();
	FontManager::Instance()->drawBoxAlign("TexWork", text_rect, FC_ALIGN_CENTER,
		SDL_GetScancodeName(KeyboardControls::Instance()->getKeyCode(associate_player, associated_control)));
}

void KeyboardOptionButton::update() {
	MenuButton::update();
}

void KeyboardOptionButton::clean() {
	MenuButton::clean();
}

void KeyboardOptionButton::callbackFunction() const {
	KeyboardControls::Instance()->setToChange(associate_player, associated_control);
	KeyboardControls::Instance()->askToChangeControls(true);
}

void KeyboardOptionButton::setAssociatedPlayer(const PLAYER_NUM pPlayer) { associate_player = pPlayer; }

PLAYER_NUM KeyboardOptionButton::getPlayerNum() const { return associate_player; }

void KeyboardOptionButton::setAssociatedControl(const CONTROLS pControl) { associated_control = pControl; }

CONTROLS KeyboardOptionButton::getAssociatedControl() const { return associated_control; }
