#include "Spawner.hpp"
#include "../utils/GlobalVars.hpp"
#include "../utils/InputHandler.hpp"
#include "../game/Game.hpp"

void Spawner::update(){
	hp=0;
	timestamp1 = SDL_GetTicks();
	if (timestamp1 > timestamp2 + 500) {
		hp = 1;
		timestamp2 = timestamp1;
	}
}

void Spawner::onCollide(BaseEntity* other){

}

