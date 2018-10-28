#include "Game.h"

#include "PlayState.h"
#include "MenuButton.h"
#include "Player.h"
#include "Enemy.h"
#include "AnimatedGraphic.h"
#include "GameParameters.h"
#include "KeyboardControls.h"
#include "InputHandler.h"

Game * Game::instance{nullptr};

Game* Game::Instance() {
	if (instance == nullptr) {
		instance = new Game();
	}

	return instance;
}

bool Game::init(const char * pTitle, const int pXpos, const int pYpos, const int pWidth, const int pHeight, const bool pFullscreen) {
	if(SDL_Init(SDL_INIT_EVERYTHING) >= 0) {
		sdl_window = SDL_CreateWindow(pTitle, pXpos, pYpos, pWidth, pHeight, pFullscreen ? SDL_WINDOW_FULLSCREEN : SDL_WINDOW_SHOWN ); 
		if(sdl_window != nullptr) {
			sdl_renderer = SDL_CreateRenderer(sdl_window, -1, 0);
			if(sdl_renderer != nullptr) {
				SDL_SetRenderDrawColor(sdl_renderer, 0,0,0,255);
			} else
				return false;
		} else
			return false;
	}

	GameParameters::game_width = pWidth;
	GameParameters::game_height = pHeight;
	GameParameters::countNumberOfLevels("Levels");

	GameObjectFactory::Instance()->registerType("MenuButton", new MenuButtonCreator());
	GameObjectFactory::Instance()->registerType("Player", new PlayerCreator());
	GameObjectFactory::Instance()->registerType("Enemy", new EnemyCreator());
	GameObjectFactory::Instance()->registerType("AnimatedGraphic", new AnimatedGraphicCreator());

	SoundManager::openAudio();
	SoundManager::load("Musics/level1.ogg", "music", SOUND_MUSIC);
	SoundManager::playMusic("music");

	game_state_machine = new GameStateMachine();
	game_state_machine->changeState(MAIN_MENU);

	KeyboardControls::Instance()->init();
	InputHandler::initialiseJoysticks();

	running = true;

	return true;
}


void Game::render() const {
	SDL_RenderClear(sdl_renderer);

	game_state_machine->render();

	SDL_RenderPresent(sdl_renderer);
}

void Game::update() const {
	game_state_machine->update();
}

void Game::handleEvents() const {
	InputHandler::update();
}

void Game::clean() const {
	InputHandler::clean();
	SoundManager::clean();

	delete game_state_machine;

	SDL_DestroyRenderer(sdl_renderer);
	SDL_DestroyWindow(sdl_window);
	SDL_Quit();
}


void Game::quit() { running = false; }

SDL_Renderer* Game::getRenderer() const { return sdl_renderer; }

GameStateMachine* Game::getStateMachine() const { return game_state_machine; }

bool Game::isRunning() const { return running; }
