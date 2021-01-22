#pragma once
#include "BaseEntity.hpp"

class Button final: public BaseEntity {
private:

public:
	Button(Sint16 collX, Sint16 collY, Uint16 collW, Uint16 collH, int hp, Uint8 texX, Uint8 texY) :
			BaseEntity{collX,collY,collW,collH,hp,texX,texY}{};
	Button(Sint16 collX, Sint16 collY, Uint16 collW, Uint16 collH, int hp) :
			BaseEntity{collX,collY,collW,collH,hp}
			{texX = 3; texY = 1;};
	~Button() override {};
	void update() override;
	void onCollide(BaseEntity*) override;
	void render() override;
};

