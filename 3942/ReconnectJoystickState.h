#pragma once
#include "GameState.h"
#include "FontCache/SDL_FontCache.h"

class ReconnectJoystickState :
	public GameState {
public:
	ReconnectJoystickState() = default;
	~ReconnectJoystickState() = default;

	void update() override;
	void render() override;
	bool onEnter() override;
	bool onExit() override;


	std::string getStateID() const override {return RECONNECT_STATE_ID; }

private:
	static const std::string RECONNECT_STATE_ID;

	FC_Font * fc_font;
};

