#include "Exitdoor.hpp"
#include "../utils/GlobalVars.hpp"
#include "../utils/InputHandler.hpp"
#include "../game/Game.hpp"

void Exitdoor::update(){
	++texY;
	if(texY / 8 >= 8) {
		texY = 0;
	}
}

void Exitdoor::onCollide(BaseEntity* other){
	other->setHP(0);
}

void Exitdoor::render(){
	offset = { (Sint16)(posX), (Sint16)(posY), TILEW, TILEH};
	SDL_RenderCopyEx(Game::getInstance()->getRenderer(),
			GameManager::getInstance()->getSheet(),
			GameManager::getInstance()->getRekt(texX, texY/8),
			&offset, 0, 0,
			SDL_FLIP_NONE);
}
