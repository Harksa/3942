#include "MenuButton.h"
#include "InputHandler.h"

MenuButton::MenuButton() : _callback(nullptr), released(true), _callbackID(0) { }

void MenuButton::load(const LoadParameters *parameters) {
	SDLGameObject::load(parameters);
	_callbackID = parameters->getCallbackID();
	sprite->setCurrentFrame(MOUSE_OUT);
}

void MenuButton::draw() {
	SDLGameObject::draw();
}

void MenuButton::update() {
	Vector2D * mousePosition = InputHandler::Instance()->getMousePosition();

	if(mousePosition->x < (position.x + sprite->getWidth()) && mousePosition->x > position.x &&
	   mousePosition->y < (position.y + sprite->getHeight()) && mousePosition->y > position.y) {
		sprite->setCurrentFrame(MOUSE_OVER);

		if(InputHandler::Instance()->getMouseButtonState(LEFT) && released) {
			sprite->setCurrentFrame(CLICKED);
			_callback();
			released = false;
		} else if(!InputHandler::Instance()->getMouseButtonState(LEFT)) {
			released = true;
			sprite->setCurrentFrame(MOUSE_OVER);
		}
	} else {
		sprite->setCurrentFrame(MOUSE_OUT);
	}
}

void MenuButton::clean() {
	SDLGameObject::clean();
}
