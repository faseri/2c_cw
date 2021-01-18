#pragma once
#include "BaseEntity.hpp"

class Mouse final: public BaseEntity {
public:
	Mouse(Sint16 collX, Sint16 collY, Uint16 collW, Uint16 collH, int hp, Uint8 texX, Uint8 texY) :
			BaseEntity{collX,collY,collW,collH,hp,texX,texY}{ hp=101;};
			Mouse(Sint16 collX, Sint16 collY, Uint16 collW, Uint16 collH, int hp) :
			BaseEntity{collX,collY,collW,collH,hp}
			{texX = 2; texY = 6; hp=101;};
	~Mouse() override {};
	void update() override;
	void onCollide(BaseEntity*) override;
};

