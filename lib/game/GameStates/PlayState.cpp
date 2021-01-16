#include "PlayState.hpp"
#include <cmath>
//const std::string PlayState::pauseID = "PAUSE";

void PlayState::update() {
//	if(InputHandler::getInstance()->isKeyDown(SDL_SCANCODE_ESCAPE)){
//		GameManager::getInstance()->pushState(new PauseState());
//		return;
//	}
	for(Uint16 i = 0; i < entities.size();++i){
		entities[i]->update();
	}

}

void PlayState::render() {
	for(Uint32 i=0; i < entities.size(); ++i){
		entities[i]->render();
	}
}

bool PlayState::onEnter() {
	entities.push_back(new Catting(1,100,TILEW,TILEH,100));
	entities.push_back(new Catting(20,120,TILEW,TILEH,100));
	SDL_Delay(400);
	return true;
}

bool PlayState::onExit() {

	return true;
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
	if ( (a->getPosY() + a->getH()) > (b->getPosY() + b->getH()) )	return false;
	// Лево а ближе чем право b
	if ( (a->getPosX() + a->getW()) > (b->getPosX() + b->getW()) )	return false;
	// Если ни одна проверка не прошла, то столкновение есть
	return true;
}
void PlayState::renderOverlay(){

}

std::string PlayState::getStateID() const{
	return playID;
}
