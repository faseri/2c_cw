#include "GameManager.hpp"

GameManager* GameManager::instance = 0;

void GameManager::update() {
	if (!game_states.empty()) {
		game_states.back()->update();
	}
}

void GameManager::render() {
	if (!game_states.empty()) {
		game_states.back()->render();
	}
}

void GameManager::pushState(GameState* state) {
	game_states.push_back(state);
	game_states.back()->onEnter();
}


void GameManager::popState() {
	if (!game_states.empty()) {
		if (game_states.back()->onExit()) {
			delete game_states.back();
			game_states.pop_back();
		}
	}
}

bool GameManager::loadSuperTexture(std::string file){
	SDL_Surface *loaded_img;
	loaded_img = SDL_LoadBMP(file.c_str());
	printf("Trying to load %s result: ",file.c_str());
	if(!loaded_img){
		SDL_LogError(SDL_LOG_CATEGORY_ERROR, "%s\n",SDL_GetError());
		return false;
	} else printf("success\n");

	SDL_SetColorKey(loaded_img, SDL_TRUE, SDL_MapRGB(loaded_img->format, 74, 53, 91));
	sheet = SDL_CreateTextureFromSurface( Game::getInstance()->getRenderer(), loaded_img );
	if(!sheet){
		SDL_LogError(SDL_LOG_CATEGORY_ERROR, "%s\n",SDL_GetError());
		return false;
	}

	SDL_FreeSurface(loaded_img);
	return true;
}

bool GameManager::loadFont(std::string file){
	font = TTF_OpenFont(file.c_str(), 30 );
	if(!font) return false;
	return true;
}

TTF_Font* GameManager::getFont(){
	return font;
}

SDL_Color GameManager::getFontColor(){
	return font_color;
}

void GameManager::setFontColor(Uint8 r,Uint8 g,Uint8 b, Uint8 a){
	font_color = {r,g,b,a};
}

SDL_Texture* GameManager::getSheet(){
	return sheet;
}

SDL_Rect* GameManager::getRekt(Uint16 num){
	rect = { ((Uint8)(num%TILEW)) * TILEW, ((Uint8)(num/TILEW)) * TILEH, TILEW, TILEH};
	return &rect;
}

SDL_Rect* GameManager::getRekt(Uint8 x, Uint8 y){
	rect = { x * TILEW, y * TILEH, TILEW, TILEH};
	return &rect;
}

SDL_Rect* GameManager::getRekt(Uint8 x, Uint8 y, Uint8 w, Uint8 h){
	rect = { x * w, y * h, w, h};
	return &rect;
}

void GameManager::changeState(GameState* state) {
	if (!game_states.empty()) {
		if (game_states.back()->getStateID() == state->getStateID()) {
			return;
		}
		if (game_states.back()->onExit()) {
			delete game_states.back();
			game_states.pop_back();
		}
	}
	game_states.push_back(state);
	game_states.back()->onEnter();
}

