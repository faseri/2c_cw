#include "Mouse.hpp"
#include "../utils/GlobalVars.hpp"
#include "../utils/InputHandler.hpp"
#include "../game/Game.hpp"

void Mouse::update(){
	posX=((MOUSEX>>6)<<6)+2;
	posY=((MOUSEY>>6)<<6)+2;
}

void Mouse::onCollide(BaseEntity* other){
	other->setReserve(99);
}
