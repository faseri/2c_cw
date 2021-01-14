#pragma once

#include <vector>
#include <map>

#include "SDL2/SDL.h"
#include "SDL2/SDL_ttf.h"

#include "Game.hpp"

#include "GameStates/IGameState.hpp"
#include "Texture.hpp"

class GameManager {
private:
	static GameManager* instance;
	std::vector<GameState*> game_states;

	SDL_Texture* sheet = nullptr;
	TTF_Font* font = nullptr;
	SDL_Color font_color;
	std::map<std::string, Texture*> textures;
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
	bool loadImg(std::string file);
	void createTex(std::string tex_name, Uint16 texX, Uint16 texY, Uint16 texW, Uint16 texH);
	Texture* getTex(std::string);
	SDL_Texture* getSheet();
	bool loadFont(std::string);
	TTF_Font* getFont();
	SDL_Color getFontColor();
	void setFontColor(Uint8,Uint8,Uint8,Uint8);
	void update();
	void render();
};
