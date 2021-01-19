#include "PlayState.hpp"
#include <cmath>
#include <fstream>
//const std::string PlayState::pauseID = "PAUSE";

void PlayState::update() {
//	if(InputHandler::getInstance()->isKeyDown(SDL_SCANCODE_ESCAPE)){
//		GameManager::getInstance()->pushState(new PauseState());
//		return;
//	}
	mouse->update();
	if(cats_spawned <= cats_max){
		spawner->update();
		if(spawner->getHP()){
			cats_spawned++;
			entities.push_back(new Catting(spawner->getPosX(),spawner->getPosY(),TILEW-4,TILEH-2,8));
			entities.back()->setReserve(2);
		}
	}
	for(i = 0; i < entities.size();++i){
		entities[i]->update();
		for(j = 0; j < blocks.size();++j){
			if(collides(entities[i],blocks[j])){
				blocks[j]->onCollide(entities[i]);
			}
			if(blocks[j]->getHP()<1){
				printf("died %d\n",j);
				blocks.erase(blocks.begin()+j);
			}
		}
		if(collides(entities[i],exitdoor)){
			exitdoor->onCollide(entities[i]);
			cats_finished++;
		}
		if(!(entities[i]->getVelX()-1)){
			if(!level[(Uint8)((entities[i]->getPosY()/64+1)*10)+(Uint8)(entities[i]->getPosX()/64)]){
				if(!entities[i]->getState())
					entities[i]->setReserve(1);
			}
		} else {
			if(!level[(Uint8)((entities[i]->getPosY()/64+1)*10)+(Uint8)(entities[i]->getPosX()/64+1)]){
				if(!entities[i]->getState())
					entities[i]->setReserve(1);
			}
		}

		if(entities[i]->getHP()<1){
			printf("cat %d died or exited\n",i);
			entities.erase(entities.begin()+i);
		}
	}
	if(InputHandler::getInstance()->isMBDown(1)){
		printf("%d\n",SDL_GetTicks()-lastclick);
		k=0;
		if(SDL_GetTicks()-lastclick>500){
			for(Uint32 j = 0; j < blocks.size();++j){
				if(collides(mouse, blocks[j])){
					k++;
					mouse->onCollide(blocks[j]);
					lastclick = SDL_GetTicks();
				}
			}
		}
		if(SDL_GetTicks()-lastclick>500){
			if(!k) {
				blocks.push_back(new Umbrella( mouse->getPosX()+2,mouse->getPosY(),TILEW-4,TILEH/2,100,2,1));
				lastclick = SDL_GetTicks();
			}
		}
	}
	if(InputHandler::getInstance()->isMBDown(3)){
		printf("%d\n",SDL_GetTicks()-lastclick);
		k=0;
		if(SDL_GetTicks()-lastclick>500){
			for(Uint32 j = 0; j < blocks.size();++j){
				if(collides(mouse, blocks[j])){
					k++;
					mouse->onCollide(blocks[j]);
					lastclick = SDL_GetTicks();
				}
			}
		}
		if(SDL_GetTicks()-lastclick>500){
			if(!k) {
				blocks.push_back(new Stopper( mouse->getPosX()+2,mouse->getPosY(),TILEW-4,TILEH/2,100,2,2));
				lastclick = SDL_GetTicks();
			}
		}
	}

}

void PlayState::render() {
	for(Uint32 i=0; i < entities.size(); ++i){
		entities[i]->render();
	}
	for(Uint32 i=0; i < blocks.size(); ++i){
		blocks[i]->render();
	}
	spawner->render();
	exitdoor->render();
	renderOverlay();
}

bool PlayState::onEnter() {
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
				case 21:
				case 33:
				case 66:
				case 82:
				case 83:
				case 98: {
					blocks.push_back(new Solidblock(j*TILEW,i*TILEH,TILEW,TILEH-4,100,(level[j+10*i]-1)%16,(level[j+10*i]-1)/16));
					break;
				}
				case 7: exitdoor = new Exitdoor(j*TILEW,i*TILEH,TILEW,TILEH,100); break;
				case 20: spawner = new Spawner(j*TILEW,i*TILEH,8,TILEH,100); break;
				default: break;
			}
		}
	}
	printf("\n");
	return true;
}

bool PlayState::onExit() {

	return true;
}

void PlayState::renderOverlay(){
	mouse->render();
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
