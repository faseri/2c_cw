#pragma once

#include "IGameState.hpp"
//#include "PauseState.hpp"
//#include "GameOverState.hpp"
#include "../GameManager.hpp"
#include "../../utils/InputHandler.hpp"
#include "../../entity/BaseEntity.hpp"

class PlayState : public GameState{
protected:
	std::string playID = "PLAY";
	std::vector<BaseEntity*> entities;

	double distance(BaseEntity*, BaseEntity*);
	bool collides(BaseEntity*, BaseEntity*);
	void renderOverlay();
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


