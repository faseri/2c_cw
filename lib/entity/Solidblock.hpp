#pragma once
#include "BaseEntity.hpp"

class Solidblock final: public BaseEntity {
public:
	Solidblock(Sint16 collX, Sint16 collY, Uint16 collW, Uint16 collH, int hp, Uint8 texX, Uint8 texY) :
			BaseEntity{collX,collY,collW,collH,hp,texX,texY}{ };
	Solidblock(Sint16 collX, Sint16 collY, Uint16 collW, Uint16 collH, int hp) :
			BaseEntity{collX,collY,collW,collH,hp}
			{texX = 0; texY = 0;};
	~Solidblock() override {};
	void update() override;
	void onCollide(BaseEntity*) override;
};

