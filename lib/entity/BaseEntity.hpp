#include <SDL2/SDL.h>
#include <limits.h>

#pragma once
#include "../game/Texture.hpp"

class BaseEntity{
protected:
	int hp;
	float posX;
	float posY;
	float velX;
	float velY;
	Uint8 w, h;
	Texture* texture;
	Uint8 texstate;
	SDL_Rect offset;
public:
	BaseEntity(Sint16, Sint16, Uint16, Uint16, int, Texture*);
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
	Uint16 getTexState();
	void setHP(int health);
	void setPosX(Sint16 x);
	void setPosY(Sint16 y);
	void setVelX(Uint16 velX);
	void setVelY(Uint16 velY);
	void setTexState(Uint16 state);
	void setTexture(Texture* tex);
};
