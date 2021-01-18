#pragma once

#include "../../entity/BaseEntity.hpp"
#include "IGameState.hpp"
//#include "PauseState.hpp"
//#include "GameOverState.hpp"
#include "../GameManager.hpp"
#include "../../utils/InputHandler.hpp"

#include "../../entity/Catting.hpp"
#include "../../entity/Solidblock.hpp"


#include "PauseState.hpp"

class PlayState : public GameState{
protected:
	std::string playID = "PLAY";
	std::vector<Uint16> level;
	std::vector<BaseEntity*> entities;
	std::vector<BaseEntity*> blocks;

	SDL_Rect overlay_offset = {0,0,TILEW,TILEH};
	double distance(BaseEntity*, BaseEntity*);
	bool collides(BaseEntity*, BaseEntity*);
	void renderOverlay();
	Uint16 i=0,j=0,k=0;
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


