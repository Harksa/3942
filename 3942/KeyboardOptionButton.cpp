#include "KeyboardOptionButton.h"
#include "InputHandler.h"
#include "FontManager.h"

void KeyboardOptionButton::load(const LoadParameters* pParameters) {
	MenuButton::load(pParameters);
	text_rect = getRect();
	text_rect.y += 10;
}

void KeyboardOptionButton::draw() {
	MenuButton::draw();
	FontManager::Instance()->drawBoxAlign("TexWork", text_rect, FC_ALIGN_CENTER,
		SDL_GetScancodeName(KeyboardControls::Instance()->getKeyCode(associate_player, associated_control)));
}

void KeyboardOptionButton::update() {
	Vector2D * mousePosition = InputHandler::getMousePosition();

	if(mousePosition->x < (position.x + sprite->getWidth()) && mousePosition->x > position.x &&
	   mousePosition->y < (position.y + sprite->getHeight()) && mousePosition->y > position.y) {
		sprite->setCurrentFrame(MOUSE_OVER);

		if(InputHandler::getMouseButtonState(LEFT_BUTTON) && released) {
			sprite->setCurrentFrame(CLICKED);
			KeyboardControls::Instance()->setToChange(associate_player, associated_control);
			KeyboardControls::Instance()->askToChangeControls(true);
			released = false;
		} else if(!InputHandler::getMouseButtonState(LEFT_BUTTON)) {
			released = true;
			sprite->setCurrentFrame(MOUSE_OVER);
		}
	} else {
		sprite->setCurrentFrame(MOUSE_OUT);
	}
}

void KeyboardOptionButton::clean() {
	MenuButton::clean();
}

void KeyboardOptionButton::setAssociatedPlayer(const PLAYER_NUM pPlayer) { associate_player = pPlayer; }

PLAYER_NUM KeyboardOptionButton::getPlayerNum() const { return associate_player; }

void KeyboardOptionButton::setAssociatedControl(const CONTROLS pControl) { associated_control = pControl; }

CONTROLS KeyboardOptionButton::getAssociatedControl() const { return associated_control; }
