#pragma once
#include "BaseEntity.hpp"

class Stopper final: public BaseEntity {
private:
	BaseEntity* influence = nullptr;
public:
	Stopper(Sint16 collX, Sint16 collY, Uint16 collW, Uint16 collH, int hp, Uint8 texX, Uint8 texY) :
			BaseEntity{collX,collY,collW,collH,hp,texX,texY}{};
	Stopper(Sint16 collX, Sint16 collY, Uint16 collW, Uint16 collH, int hp) :
			BaseEntity{collX,collY,collW,collH,hp}
			{texX = 2; texY = 2;};
	~Stopper() override {};
	void update() override;
	void onCollide(BaseEntity*) override;
	void setReserve(Uint8) override;
};

