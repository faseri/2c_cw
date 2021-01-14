#include "Game.hpp"

Game* Game::instance = 0;

bool Game::create(){
	SDL_Window *main_window = SDL_CreateWindow("Cattings",
							SDL_WINDOWPOS_CENTERED,	SDL_WINDOWPOS_CENTERED,
							SCR_WIDTH, SCR_HEIGHT,
							SDL_WINDOW_OPENGL);
	if(!main_window){
		printf("Err: main window creation failed\n");
		return false;
	}
	renderer = SDL_CreateRenderer(main_window, -1, 0);
	if(!renderer){
		printf("Err: renderer creation failed\n");
		return false;
	}
	SDL_Surface *ico;
	ico = SDL_LoadBMP("res/ico.bmp");
	if(!ico){
		printf("Err: no icon found\n");
		return false;
	}
	SDL_SetWindowIcon(main_window, ico);

	SDL_SetRenderDrawColor(renderer, 74, 53, 91, 255);
	SDL_RenderClear(renderer);
	SDL_RenderPresent(renderer);

	main_texture = SDL_CreateTexture(renderer, SDL_PIXELFORMAT_RGBA8888, SDL_TEXTUREACCESS_TARGET, SCR_WIDTH, SCR_HEIGHT);
	if(!main_texture){
		printf("Err: main texture creation failed\n");
		return false;
	}
	SDL_RenderCopy(renderer, main_texture, NULL, NULL);
	SDL_RenderPresent(renderer);
	GameManager::getInstance()->loadImg("res/spritesheet.bmp");
	GameManager::getInstance()->createTex("catting_default", 0, 0, TILEW, TILEH);
//	GameManager::getInstance()->createTex("void",    0,       0,      TILEW,  TILEH);
//	GameManager::getInstance()->createTex("floor",   TILEW*2, 0,      TILEW,  TILEH);
	GameManager::getInstance()->loadFont("res/OdibeeSans.ttf");

	GameManager::getInstance()->pushState(new PlayState());

	running = true;

	return true;
}

bool Game::isRunning(){
	return running;
}

void Game::stop(){
	running = false;
	printf("Stopping the game...\n");
}

void Game::handleEvents(){
	InputHandler::getInstance()->update();
}

void Game::update(){
	GameManager::getInstance()->update();
}

void Game::render(){
	GameManager::getInstance()->render();
	SDL_RenderPresent(renderer);
}

SDL_Renderer* Game::getRenderer(){
	return renderer;
}

SDL_Texture* Game::getScreen(){
	return main_texture;
}

void Game::updateCamera(Sint16 x, Sint16 y){
	camX = ( x + 32 ) - SCR_WIDTH / 2;
	camY = ( y + 32 ) - SCR_HEIGHT / 2;
	if(camX<0){
		camX = 0;
	}
	if(camY<0){
		camY = 0;
	}
	if(camX >  SCR_WIDTH ){
		camX = SCR_WIDTH;
	}
	if(camY > SCR_HEIGHT ){
		camY = SCR_HEIGHT;
	}
}

Sint16 Game::getCamX(){
	return camX;
}

Sint16 Game::getCamY(){
	return camY;
}

void Game::startTimer(){
	timer_started = true;
	timer_paused = false;
	time_start = SDL_GetTicks();
}

void Game::stopTimer(){
	timer_started = false;
	timer_paused = false;
}

void Game::pauseTimer(){
	if(timer_started && !timer_paused){
		timer_paused = true;
		time_paused = SDL_GetTicks() - time_start;
	}
}

void Game::unpauseTimer(){
	if(timer_paused){
		timer_paused = false;
		time_start = SDL_GetTicks() - time_paused;
		time_paused = 0;
	}
}


Uint32 Game::getTime(){
	if(timer_started ){
		if(timer_paused){
			return time_paused;
		}
		else {
			return SDL_GetTicks() - time_start;
		}
	}
	return 0;
}

int Game::random(int min,int max){
	return (min + (rand() % (max - min + 1)));
}

Game::Game(){
	time = 0;
	time_start = 0;
	time_paused = 0;
	timer_paused = false;
	timer_started = false;
	camY = 0;
	camX = 0;
	running = false;
	renderer = nullptr;
	main_texture = nullptr;
}

Game::~Game(){

}
