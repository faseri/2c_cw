#include "Exitdoor.hpp"
#include "../utils/GlobalVars.hpp"
#include "../utils/InputHandler.hpp"
#include "../game/Game.hpp"

void Exitdoor::update(){

}

void Exitdoor::onCollide(BaseEntity* other){
	other->setHP(0);
}

