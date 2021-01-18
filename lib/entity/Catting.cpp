#include "Catting.hpp"
#include "../utils/GlobalVars.hpp"
#include "../utils/InputHandler.hpp"
#include "../game/Game.hpp"


void Catting::update(){
	switch(state){
	// walking
		case 0:{
			posX += velX;
			if(posX>SCR_WIDTH || posX<0){
				velX = -velX;
			}
			break;
		}
		// freefall
		case 1:{
			posY += velY;
			break;
		}
		//slowfall
		case 3:{

			break;
		}
	}
	++texY;
	if(texY / 4 >= 4) {
		texY = 0;
	}

}

void Catting::render(){
	offset = { (Sint16)(posX), (Sint16)(posY), TILEW, TILEH};
	SDL_RenderCopyEx(Game::getInstance()->getRenderer(),
			GameManager::getInstance()->getSheet(),
			GameManager::getInstance()->getRekt(texX, texY/4),
			&offset, 0, 0,
			(SDL_RendererFlip)(SDL_FLIP_HORIZONTAL*(bool)(velX-1)));
}

void Catting::setReserve(Uint8 a){
	switch(a){
	case 0: {
		texX = 9;
		velY = 0;
		break;
		}
	case 1:{
		texX = 14;
		velY = 1.5;
		break;
		}
	case 2:{
		velY = 1;
		texX = 12;
		break;
		}
	}
}

void Catting::onCollide(BaseEntity* other){
	printf("turn\n");
	posX -= velX;
	velX = -velX;
	setReserve(0);
}
