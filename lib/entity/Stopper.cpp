#include "Stopper.hpp"
#include "../utils/GlobalVars.hpp"
#include "../utils/InputHandler.hpp"
#include "../game/Game.hpp"

void Stopper::update(){

}

void Stopper::onCollide(BaseEntity* other){
	if(other==influence) return;
	if(!state){
		texX=5;
		other->setReserve(3);
		other->setPosX(posX);
		influence = other;
		state = 1;
	} else 	{
		other->onCollide(0);
	}
}

void Stopper::setReserve(Uint8 act){
	if(act==99){
		if(influence){
			influence->setReserve(0);
		}
		hp=0;
	}
}
