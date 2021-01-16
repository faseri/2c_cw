#pragma once
#include "BaseEntity.hpp"

class Catting : public BaseEntity{
//protected:

public:
	Catting(Sint16 collX, Sint16 collY, Uint16 collW, Uint16 collH, int hp, Uint8 texX, Uint8 texY) :
		BaseEntity{collX,collY,collW,collH,hp,texX,texY}{ velX = 1;};
	Catting(Sint16 collX, Sint16 collY, Uint16 collW, Uint16 collH, int hp) :
		BaseEntity{collX,collY,collW,collH,hp}
		{texX = 9; texY = 0; velX = 1;};
	~Catting() override {};
	void update() override;
	void onCollide(BaseEntity*) override;
};
