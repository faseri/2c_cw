#include "PlayState.hpp"
#include <cmath>
#include <fstream>
//const std::string PlayState::pauseID = "PAUSE";

void PlayState::update() {
//	if(InputHandler::getInstance()->isKeyDown(SDL_SCANCODE_ESCAPE)){
//		GameManager::getInstance()->pushState(new PauseState());
//		return;
//	}

	for(i = 0; i < entities.size();++i){
		entities[i]->update();
		for(j = 0; j < blocks.size();++j){
			if(collides(entities[i],blocks[j])){
				if(blocks[j]->isSolid())
					blocks[j]->onCollide(entities[i]);
			}
		}
//		if(!level[(Uint8)(entities[i]->getPosY()/64)+1][(Uint8)(entities[i]->getPosX()/64)]){
//			printf("fall?");
//		}

//		if(!level[(entities[i]->getPosX()>>6)<<6][((entities[i]->getPosY()>>6)<<6)-1]){
//			entities[i]->setVelY(1); entities[i]->setVelX(0);
//		} else { entities[i]->setVelY(0); entities[i]->setVelX(1); }
	}

}

void PlayState::render() {
	for(Uint32 i=0; i < entities.size(); ++i){
		entities[i]->render();
	}
	for(Uint32 i=0; i < blocks.size(); ++i){
		blocks[i]->render();
	}
	renderOverlay();
}

bool PlayState::onEnter() {
	entities.push_back(new Catting(64,64,TILEW,TILEH-1,100));
	std::ifstream in{"res/levels.st"};
	int x;
	while((in >> x) && in.ignore()){
		level.push_back(x);
	}
	in.close();

	for(i=0; i<14; ++i){
		printf("\n");
		for(j=0; j<10; ++j){
			printf("[%d,%d]%d-",j,i,level[j+10*i]);
			switch(level[j+10*i]){
				case 1:
				case 20:
				case 21:
				case 33:
				case 66:
				case 82:
				case 83:
				case 98: {
					blocks.push_back(new Solidblock(j*TILEW,i*TILEH,TILEW,TILEH-4,100,(level[j+10*i]-1)%16,(level[j+10*i]-1)/16));
					break;
				}
				default: break;
			}
		}
	}

	SDL_Delay(400);
	return true;
}

bool PlayState::onExit() {

	return true;
}

void PlayState::renderOverlay(){
	overlay_offset = {(MOUSEX>>6)<<6, (MOUSEY>>6)<<6,TILEW,TILEH};
	SDL_RenderCopy(RENDERER,SHEET,CURSORRECT,&overlay_offset);
}

double PlayState::distance(BaseEntity* a, BaseEntity* b){
	return std::sqrt( (double)
						( (a->getPosX() - b->getPosX() )
						 *(a->getPosX() - b->getPosX() )
						 +
						 (a->getPosY() - b->getPosY() )
						*(a->getPosY() - b->getPosY() )
						)
					);
}

bool PlayState::collides(BaseEntity* a, BaseEntity* b) {
	// Низ а выше чем верх b
	if ( (a->getPosY() + a->getH()) < (b->getPosY()) )	return false;
	// Правая сторона а дальше чем левая b
	if ( (a->getPosX() + a->getW()) < (b->getPosX()) )	return false;
	// Верх а ниже чем низ b
	if ( (a->getPosY()) > (b->getPosY() + b->getH()) )	return false;
	// Лево а ближе чем право b
	if ( (a->getPosX()) > (b->getPosX() + b->getW()) )	return false;
	// Если ни одна проверка не прошла, то столкновение есть
	return true;
}



std::string PlayState::getStateID() const{
	return playID;
}
