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
			posY += 2*velY;
			break;
		}
		//slowfall
		case 2:{
			posY += velY;
			break;
		}
		default: break;
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
		posY-=2;
		texX = 9;
		break;
		}
	case 1:{
		if(!state) posX+=velX;
		texX = 14;
		break;
		}
	case 2:{
		texX = 12;
		break;
		}
	}
	state = a;
}

void Catting::onCollide(BaseEntity* other){
	printf("turn\n");
	switch(state){
	case 0:{
		posX -= velX;
		velX = -velX;
		break;
	}
	case 1:
	case 2:{
		setReserve(0);
		break;
	}
	default: break;
	}
}
