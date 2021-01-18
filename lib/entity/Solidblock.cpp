#include "Solidblock.hpp"
#include "../utils/GlobalVars.hpp"
#include "../utils/InputHandler.hpp"
#include "../game/Game.hpp"

void Solidblock::update(){

}

void Solidblock::onCollide(BaseEntity* other){
	other->onCollide(0);
}
