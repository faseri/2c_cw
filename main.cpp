#include <SDL2/SDL.h>
#include <SDL2/SDL_ttf.h>

#include "lib/utils/GlobalVars.hpp"
#include "lib/game/Game.hpp"


int main(int argc, char* argv[]){

	if ( SDL_Init(SDL_INIT_VIDEO | SDL_INIT_AUDIO | SDL_INIT_TIMER ) ){
		return 1;
	}
	if ( TTF_Init() ){
		return 2;
	}
	SDL_LogSetAllPriority(SDL_LOG_PRIORITY_WARN);
	printf("Trying to start a game... ");
	if( Game::getInstance()->create() ){
		printf("Game started\n");
		while(Game::getInstance()->isRunning()){

			Game::getInstance()->handleEvents();
			Game::getInstance()->update();
			Game::getInstance()->render();

		}
	} else printf("failed\n");

	SDL_Quit();
	TTF_Quit();
	printf("Game Terminated");
	return 0;
}
