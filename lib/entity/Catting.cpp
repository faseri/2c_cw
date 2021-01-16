#include "Catting.hpp"

void Catting::update(){
	posX += velX;
	posY += velY;
	if(posX>SCR_WIDTH || posX<0){
		velX = -velX;
	}
}

void Catting::onCollide(BaseEntity* other){

}
