#include "BaseEntity.hpp"
#include "../utils/GlobalVars.hpp"
#include "../utils/InputHandler.hpp"
#include "../game/Game.hpp"

BaseEntity::BaseEntity(Sint16 collX, Sint16 collY, Uint16 collW, Uint16 collH, int hp, Uint8 texX, Uint8 texY){
		this->hp = hp;
		posX = collX;
		posY = collY;
		w = collW;
		h = collH;
		this->texX = texX;
		this->texY = texY;
		velX = 0;
		velY = 0;
		offset = {(Sint16)posX,(Sint16)posY,0,0};
//		LOG_NEWENTITY
}
BaseEntity::BaseEntity(Sint16 collX, Sint16 collY, Uint16 collW, Uint16 collH, int hp){
		this->hp = hp;
		posX = collX;
		posY = collY;
		w = collW;
		h = collH;
		this->texX = 0;
		this->texY = 0;
		velX = 0;
		velY = 0;
		offset = {(Sint16)posX,(Sint16)posY,0,0};
//		LOG_NEWENTITY
}
BaseEntity::~BaseEntity(){

}

void BaseEntity::render(){
	offset = { (Sint16)(posX), (Sint16)(posY), TILEW, TILEH};
	SDL_RenderCopy(Game::getInstance()->getRenderer(),
					GameManager::getInstance()->getSheet(),
					GameManager::getInstance()->getRekt(texX, texY),
					&offset);
}
void BaseEntity::onCollide(BaseEntity* another){

}

int BaseEntity::getHP(){
	return hp;
}
Sint16 BaseEntity::getPosX(){
	return posX;
}
Sint16 BaseEntity::getPosY(){
	return posY;
}
Uint8 BaseEntity::getW(){
	return w;
}
Uint8 BaseEntity::getH(){
	return h;
}
Uint16 BaseEntity::getVelX(){
	return velX;
}
Uint16 BaseEntity::getVelY(){
	return velY;
}

void BaseEntity::setHP(int health){
	hp = health;
}
void BaseEntity::setPosX(Sint16 x){
	posX = x;
}
void BaseEntity::setPosY(Sint16 y){
	posY = y;
}
void BaseEntity::setVelX(Uint16 velX){
	this->velX = velX;
}
void BaseEntity::setVelY(Uint16 velY){
	this->velY = velX;
}
Uint16 BaseEntity::getTexX(){
	return texX;
}
Uint16 BaseEntity::getTexY(){
	return texY;
}
void BaseEntity::setTexState(Uint16 x,Uint16 y){
	texX = x;
	texY = y;
}



