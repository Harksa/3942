#include "KeyboardOptionButton.h"
#include "InputHandler.h"

void KeyboardOptionButton::load(const LoadParameters* parameters) {
	MenuButton::load(parameters);
}

void KeyboardOptionButton::draw() {
	MenuButton::draw();
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
