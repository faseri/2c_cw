#include "BaseEntity.hpp"
#include "../utils/GlobalVars.hpp"
#include "../utils/InputHandler.hpp"
#include "../game/Game.hpp"

BaseEntity::BaseEntity(Sint16 collX, Sint16 collY, Uint16 collW, Uint16 collH, int hp, Texture* tex){
		this->hp = hp;
		posX = collX;
		posY = collY;
		w = collW;
		h = collH;
		texstate = 0;
		texture = tex;
		velX = 0;
		velY = 0;
		offset = {(Sint16)posX,(Sint16)posY,0,0};
//		LOG_NEWENTITY
}
BaseEntity::~BaseEntity(){

}

void BaseEntity::update(){
	posX += velX;
	posY += velY;
}

void BaseEntity::render(){
	offset = { (Sint16)(posX), (Sint16)(posY), 0, 0};
	SDL_RenderCopy(Game::getInstance()->getRenderer(), GameManager::getInstance()->getSheet(), texture->getRekt(texstate), &offset);
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
Uint16 BaseEntity::getTexState(){
	return texstate;
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
void BaseEntity::setTexState(Uint16 state){
	texstate = state;
}

void BaseEntity::setTexture(Texture* tex){
	texture = tex;
}

