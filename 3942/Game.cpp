#include "Game.h"

#include "InputHandler.h"
#include "MainMenuState.h"
#include "PlayState.h"
#include "MenuButton.h"
#include "Player.h"
#include "Enemy.h"
#include "AnimatedGraphic.h"
#include "SoundManager.h"


Game * Game::instance = nullptr;

Game::Game() {}

bool Game::init(const char * title, int xpos, int ypos, int width, int height, bool fullscreen) {
	if(SDL_Init(SDL_INIT_EVERYTHING) >= 0) {
		sdl_window = SDL_CreateWindow(title, xpos, ypos, width, height, fullscreen ? SDL_WINDOW_FULLSCREEN : SDL_WINDOW_SHOWN ); 
		if(sdl_window != nullptr) {
			sdl_renderer = SDL_CreateRenderer(sdl_window, -1, 0);
			if(sdl_renderer != nullptr) {
				SDL_SetRenderDrawColor(sdl_renderer, 255,255,255,255);
			} else
				return false;
		} else
			return false;
	}

	_gameWidth = width;
	_gameHeight = height;

	GameObjectFactory::Instance()->registerType("MenuButton", new MenuButtonCreator());
	GameObjectFactory::Instance()->registerType("Player", new PlayerCreator());
	GameObjectFactory::Instance()->registerType("Enemy", new EnemyCreator());
	GameObjectFactory::Instance()->registerType("AnimatedGraphic", new AnimatedGraphicCreator());

	SoundManager::Instance()->load("Musics/level1.ogg", "lol", SOUND_MUSIC);
	SoundManager::Instance()->playMusic("lol");

	_gameStateMachine = new GameStateMachine();
	_gameStateMachine->changeState(new MainMenuState());

	InputHandler::Instance()->initialiseJoysticks();

	_running = true;

	return true;
}


void Game::render() {
	SDL_RenderClear(sdl_renderer);

	_gameStateMachine->render();

	SDL_RenderPresent(sdl_renderer);
}

void Game::update() {
	_gameStateMachine->update();
}

void Game::handleEvents() {
	InputHandler::Instance()->update();

	if(InputHandler::Instance()->isKeyDown(SDL_SCANCODE_RETURN)) {
		_gameStateMachine->changeState(new PlayState());
	}
}

void Game::clean() {
	InputHandler::Instance()->clean();
	SoundManager::Instance()->clean();

	SDL_DestroyRenderer(sdl_renderer);
	SDL_DestroyWindow(sdl_window);
	SDL_Quit();
}


