#include "Umbrella.hpp"
#include "../utils/GlobalVars.hpp"
#include "../utils/InputHandler.hpp"
#include "../game/Game.hpp"

void Umbrella::update(){

}

void Umbrella::onCollide(BaseEntity* other){
	other->setReserve(2);
}

void Umbrella::setReserve(Uint8 act){
	if(act==99){
		hp=0;
	}
}
