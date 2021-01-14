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

bool GameManager::loadImg(std::string file){
	SDL_Surface *loaded_img;
	loaded_img = SDL_LoadBMP(file.c_str());
	printf("Trying to load %s result: ",file.c_str());
	if(!loaded_img){
		printf("%s\n",SDL_GetError());
		return false;
	} else printf("success\n");
	sheet = SDL_CreateTextureFromSurface( Game::getInstance()->getRenderer(), loaded_img );
	if(!sheet){
		printf("%s\n",SDL_GetError());
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
void GameManager::createTex(
		std::string tex_name,
		Uint16 texX, Uint16 texY,
		Uint16 texW, Uint16 texH
		) {
	textures.emplace( std::pair<std::string,Texture*>(tex_name, new Texture(texX, texY, texW, texH)) );
}

Texture* GameManager::getTex(std::string name){
	return textures.at(name);
}

SDL_Texture* GameManager::getSheet(){
	return sheet;
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

