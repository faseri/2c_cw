#include <SDL2/SDL.h>
#include <limits.h>

#pragma once

class BaseEntity{
protected:
	int hp;
	float posX, posY;
	Uint8 w, h;
	float velX, velY;
	Uint8 texX, texY;
	SDL_Rect offset;
public:
	BaseEntity(Sint16, Sint16, Uint16, Uint16, int);
	virtual ~BaseEntity();
	virtual void update() = 0;
	virtual void render();
	virtual void onCollide(BaseEntity*) = 0;
	int getHP();
	Sint16 getPosX();
	Sint16 getPosY();
	Uint8 getW();
	Uint8 getH();
	Uint16 getVelX();
	Uint16 getVelY();
	void setHP(int health);
	void setPosX(Sint16 x);
	void setPosY(Sint16 y);
	void setVelX(Uint16 velX);
	void setVelY(Uint16 velY);
	Uint16 getTexX();
	Uint16 getTexY();
	void setTexState(Uint16 x, Uint16 y);
};
