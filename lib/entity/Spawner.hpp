#pragma once
#include "BaseEntity.hpp"

class Spawner final: public BaseEntity {
private:
	Uint16 timestamp1=0,timestamp2=0;
public:
	Spawner(Sint16 collX, Sint16 collY, Uint16 collW, Uint16 collH, int hp, Uint8 texX, Uint8 texY) :
			BaseEntity{collX,collY,collW,collH,hp,texX,texY}{};
	Spawner(Sint16 collX, Sint16 collY, Uint16 collW, Uint16 collH, int hp) :
			BaseEntity{collX,collY,collW,collH,hp}
			{texX = 3; texY = 1;};
	~Spawner() override {};
	void update() override;
	void onCollide(BaseEntity*) override;
};

