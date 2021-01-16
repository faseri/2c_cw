#pragma once

#include <vector>
#include <map>

#include "SDL2/SDL.h"
#include "SDL2/SDL_ttf.h"

#include "Game.hpp"
#include "GameStates/IGameState.hpp"

class GameManager {
private:
	static GameManager* instance;
	std::vector<GameState*> game_states;

	SDL_Texture* sheet = nullptr;
	SDL_Rect rect = {0,0,0,0};

	TTF_Font* font = nullptr;
	SDL_Color font_color;
public:
	static GameManager* getInstance(){
		if (!instance) {
			instance = new GameManager();
		}
		return instance;
	}
	void pushState(GameState* state);
	void changeState(GameState* state);
	void popState();

	bool loadSuperTexture(std::string file);
	SDL_Texture* getSheet();
	SDL_Rect* getRekt(Uint16 num);
	SDL_Rect* getRekt(Uint8 x, Uint8 y);
	SDL_Rect* getRekt(Uint8 x, Uint8 y, Uint8 w, Uint8 h);


	bool loadFont(std::string);
	TTF_Font* getFont();
	SDL_Color getFontColor();
	void setFontColor(Uint8,Uint8,Uint8,Uint8);

	void update();
	void render();
};
