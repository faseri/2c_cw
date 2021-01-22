#pragma once
#include "BaseEntity.hpp"

class Exitdoor final: public BaseEntity {

public:
	Exitdoor(Sint16 collX, Sint16 collY, Uint16 collW, Uint16 collH, int hp, Uint8 texX, Uint8 texY) :
			BaseEntity{collX,collY,collW,collH,hp,texX,texY}{};
	Exitdoor(Sint16 collX, Sint16 collY, Uint16 collW, Uint16 collH, int hp) :
			BaseEntity{collX,collY,collW,collH,hp}
			{texX = 7; texY = 0;};
	~Exitdoor() override {};
	void update() override;
	void onCollide(BaseEntity*) override;
	void render() override;
};

