#include <SDL2/SDL.h>

#pragma once

class Texture{
protected:
	SDL_Rect col;
	SDL_Rect rect = {0,0,0,0};
public:
	Texture(int x, int y, int w, int h);
	SDL_Rect* getRekt(Uint8 state);
	int getW();
	int getH();
};
