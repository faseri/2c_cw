#pragma once
#include "BaseEntity.hpp"

class Umbrella final: public BaseEntity {
public:
	Umbrella(Sint16 collX, Sint16 collY, Uint16 collW, Uint16 collH, int hp, Uint8 texX, Uint8 texY) :
			BaseEntity{collX,collY,collW,collH,hp,texX,texY}{ state=100; };
	Umbrella(Sint16 collX, Sint16 collY, Uint16 collW, Uint16 collH, int hp) :
			BaseEntity{collX,collY,collW,collH,hp}
			{texX = 2; texY = 1; state=100;};
	~Umbrella() override {};
	void update() override;
	void onCollide(BaseEntity*) override;
	void setReserve(Uint8) override;
};

