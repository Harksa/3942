#pragma once
#include "Sprite.h"
#include "SDLGameObject.h"

class Bullet : public SDLGameObject {
public:
	Bullet() = default;
	~Bullet() = default;

	void draw() override;
	void update() override;
	void clean() override;

	bool isAvailable() const { return is_available;}
	void setAvailability(bool value) {is_available = value;}

	void load(const LoadParameters* parameters) override;

	void setNext(Bullet * new_bullet) {next = new_bullet;}
	Bullet * getNext() const {return next;}

private:
	Bullet * next;

	bool is_available;
};

