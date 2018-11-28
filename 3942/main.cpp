#include "Game.h"
#include "StateChangeAsker.h"
#include "InputHandler.h"

#define _CRTDBG_MAP_ALLOC
#include <cstdlib>
#include <crtdbg.h>

#ifdef _DEBUG
    #define DBG_NEW new ( _NORMAL_BLOCK , __FILE__ , __LINE__ )
    // Replace _NORMAL_BLOCK with _CLIENT_BLOCK if you want the
    // allocations to be of _CLIENT_BLOCK type
#else
    #define DBG_NEW new
#endif

constexpr float FPS = 60.0f;
constexpr int DELAY_TIME = static_cast<int> (1000.0f / FPS);

#define SDL_main main

int main(int argc, char** args) {

	Game::Instance()->init("3942", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, 600, 800, false);

	while(Game::Instance()->isRunning()) {
		if(StateChangeAsker::isAskingForAnyChanges()) {
			if(StateChangeAsker::isAskingToChange()) 
				Game::Instance()->getStateMachine()->changeState(StateChangeAsker::getChoice());
			else if(StateChangeAsker::isAskingToPush())
				Game::Instance()->getStateMachine()->pushState(StateChangeAsker::getChoice());
			else if(StateChangeAsker::isAskingForPopBack())
				Game::Instance()->getStateMachine()->popState();

			StateChangeAsker::reset();
			InputHandler::reset();
		} else {
			const Uint32 frame_start = SDL_GetTicks();
			Game::Instance()->handleEvents();
			Game::Instance()->update();
			Game::Instance()->render();

			const Uint32 frame_time = SDL_GetTicks() - frame_start;

			if(frame_time < DELAY_TIME) {
				SDL_Delay(int(DELAY_TIME - frame_time));
			}
		}

	}

	Game::Instance()->clean();

	_CrtDumpMemoryLeaks();

	return EXIT_SUCCESS;
}