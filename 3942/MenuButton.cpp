#include "MenuButton.h"
#include "InputHandler.h"

void MenuButton::load(const LoadParameters *pParameters) {
	GameObject::load(pParameters);
	callback_id = pParameters->getCallbackID();
	sprite->setCurrentFrame(MOUSE_OUT);
}

void MenuButton::draw() {
	GameObject::draw();
}

void MenuButton::update() {
	Vector2D * mousePosition = InputHandler::getMousePosition();

	if(mousePosition->x < (position.x + sprite->getWidth()) && mousePosition->x > position.x &&
	   mousePosition->y < (position.y + sprite->getHeight()) && mousePosition->y > position.y) {
		sprite->setCurrentFrame(MOUSE_OVER);

		if(InputHandler::getMouseButtonState(LEFT_BUTTON) && released) {
			sprite->setCurrentFrame(CLICKED);
			callback();
			released = false;
		} else if(!InputHandler::getMouseButtonState(LEFT_BUTTON)) {
			released = true;
			sprite->setCurrentFrame(MOUSE_OVER);
		}
	} else {
		sprite->setCurrentFrame(MOUSE_OUT);
	}
}

void MenuButton::clean() {
	GameObject::clean();
}

void MenuButton::setCallback(void (* pCallback)()) { callback = pCallback; }

int MenuButton::getCallbackId() const { return callback_id; }
