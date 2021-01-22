#include <SDL2/SDL.h>
#include <limits.h>

#pragma once


class BaseEntity{
protected:
	int hp;
	float posX, posY;
	Uint16 w, h;
	float velX, velY;
	Uint8 texX, texY;
	SDL_Rect offset;
	Uint8 state;
public:
	BaseEntity(Sint16, Sint16, Uint16, Uint16, int, Uint8, Uint8);
	BaseEntity(Sint16, Sint16, Uint16, Uint16, int);
	virtual ~BaseEntity();
	virtual void update() = 0;
	virtual void render();
	virtual void onCollide(BaseEntity*) = 0;
	int getHP();
	Sint16 getPosX();
	Sint16 getPosY();
	Uint16 getW();
	Uint16 getH();
	Uint16 getVelX();
	Uint16 getVelY();
	void setHP(int health);
	void setPosX(Sint16 x);
	void setPosY(Sint16 y);
	void setVelX(Uint16 velX);
	void setVelY(Uint16 velY);
	void setW(Uint16 w);
	void setH(Uint16 h);
	Uint16 getTexX();
	Uint16 getTexY();
	void setTexState(Uint16 x, Uint16 y);
	virtual void setReserve(Uint8);
	Uint8 getState();

};
