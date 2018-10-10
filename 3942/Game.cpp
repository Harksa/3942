#include "Game.h"

#include "PlayState.h"
#include "MenuButton.h"
#include "Player.h"
#include "Enemy.h"
#include "AnimatedGraphic.h"
#include "GameParameters.h"
#include "KeyboardControls.h"

Game * Game::instance{nullptr};

bool Game::init(const char * title, const int xpos, const int ypos, const int width, const int height, const bool fullscreen) {
	if(SDL_Init(SDL_INIT_EVERYTHING) >= 0) {
		sdl_window = SDL_CreateWindow(title, xpos, ypos, width, height, fullscreen ? SDL_WINDOW_FULLSCREEN : SDL_WINDOW_SHOWN ); 
		if(sdl_window != nullptr) {
			sdl_renderer = SDL_CreateRenderer(sdl_window, -1, 0);
			if(sdl_renderer != nullptr) {
				SDL_SetRenderDrawColor(sdl_renderer, 0,0,0,255);
			} else
				return false;
		} else
			return false;
	}

	GameParameters::game_width = width;
	GameParameters::game_height = height;

	GameObjectFactory::Instance()->registerType("MenuButton", new MenuButtonCreator());
	GameObjectFactory::Instance()->registerType("Player", new PlayerCreator());
	GameObjectFactory::Instance()->registerType("Enemy", new EnemyCreator());
	GameObjectFactory::Instance()->registerType("AnimatedGraphic", new AnimatedGraphicCreator());

	SoundManager::openAudio();
	SoundManager::load("Musics/level1.ogg", "music", SOUND_MUSIC);
	SoundManager::playMusic("music");

	_gameStateMachine = new GameStateMachine();
	_gameStateMachine->changeState(MAIN_MENU);

	KeyboardControls::Instance()->init();
	InputHandler::initialiseJoysticks();

	_running = true;

	return true;
}


void Game::render() const {
	SDL_RenderClear(sdl_renderer);

	_gameStateMachine->render();

	SDL_RenderPresent(sdl_renderer);
}

void Game::update() const {
	_gameStateMachine->update();
}

void Game::handleEvents() const {
	InputHandler::update();
}

void Game::clean() const {
	InputHandler::clean();
	SoundManager::clean();

	SDL_DestroyRenderer(sdl_renderer);
	SDL_DestroyWindow(sdl_window);
	SDL_Quit();
}


