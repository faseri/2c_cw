#include <SDL2/SDL.h>
#include <SDL2/SDL_ttf.h>
#include <vector>

#pragma once

#include "../utils/GlobalVars.hpp"
#include "../utils/InputHandler.hpp"
#include "GameStates/PlayState.hpp"

#include "GameManager.hpp"

class Game final{
public:
	static Game* getInstance(){
		if (!instance) {
			instance = new Game();
		}
	return instance;
	}
	bool create();
	void handleEvents();
	void update();
	void render();
	bool isRunning();
	void stop();
	SDL_Renderer* getRenderer();
	SDL_Texture* getScreen();
	Sint16 getCamX();
	Sint16 getCamY();
	void updateCamera(Sint16,Sint16);
	void startTimer();
	void stopTimer();
	void pauseTimer();
	void unpauseTimer();
	Uint32 getTime();
	int random(int,int);
private:
	Game();
	~Game();
	static Game* instance;
	SDL_Renderer* renderer;
	SDL_Texture* main_texture;
	SDL_Rect filler = {0,0,SCR_WIDTH,SCR_HEIGHT};
	SDL_Rect crop = {64,64,0,0};
	bool running;
	bool timer_paused;
	bool timer_started;
	Uint32 time, time_paused, time_start;
	Sint16 camX;
	Sint16 camY;

};
