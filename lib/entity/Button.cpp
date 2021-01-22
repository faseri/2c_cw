#include "Button.hpp"
#include "../utils/GlobalVars.hpp"
#include "../utils/InputHandler.hpp"
#include "../game/Game.hpp"

void Button::update(){

}

void Button::onCollide(BaseEntity* other){

}

void Button::render(){
	offset = { (Sint16)(posX), (Sint16)(posY), w, h};
	SDL_RenderCopyEx(Game::getInstance()->getRenderer(),
			GameManager::getInstance()->getSheet(),
			GameManager::getInstance()->getRekt(texX, texY),
			&offset, 0, 0, SDL_FLIP_NONE);
}
