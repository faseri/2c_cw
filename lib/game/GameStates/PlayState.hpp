#pragma once

#include "../../entity/BaseEntity.hpp"
#include "IGameState.hpp"
//#include "PauseState.hpp"
//#include "GameOverState.hpp"
#include "../GameManager.hpp"
#include "../../utils/InputHandler.hpp"

#include "../../entity/Catting.hpp"
#include "../../entity/Solidblock.hpp"
#include "../../entity/Umbrella.hpp"
#include "../../entity/Mouse.hpp"
#include "../../entity/Spawner.hpp"
#include "../../entity/Exitdoor.hpp"




#include "PauseState.hpp"

class PlayState : public GameState{
protected:
	std::string playID = "PLAY";
	std::vector<Uint16> level;
	std::vector<BaseEntity*> entities;
	std::vector<BaseEntity*> blocks;
	std::map<Uint8,BaseEntity*> umbrellas;
	BaseEntity* mouse = new Mouse(1,1,16,32,32,2,6);
	Spawner* spawner = nullptr;
	Exitdoor* exitdoor = nullptr;
	SDL_Rect overlay_offset = {0,0,TILEW,TILEH};
	double distance(BaseEntity*, BaseEntity*);
	bool collides(BaseEntity*, BaseEntity*);
	void renderOverlay();
	Uint16 i=0,j=0,k=0;
	Uint16 lastclick=0;
	Uint8 cats_max=12,cats_spawned=0,cats_finished=0;

public:
	PlayState(){ };
	~PlayState(){ };
	void update();
	void render();
	bool onEnter();
	bool onExit();
	Sint16 getCamX();
	Sint16 getCamY();
	std::string getStateID() const;
};


