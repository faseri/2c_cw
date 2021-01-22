#pragma once
#include "IGameState.hpp"
#include "../GameManager.hpp"
#include "../../utils/InputHandler.hpp"
#include "../../entity/Button.hpp"

class GameOverState: public GameState {
private:
	std::string playID = "GameOver";
	Uint32 i=0;
	std::vector<Button*> buttons;

	SDL_Rect overlay_offset = {0,0,TILEW,TILEH};
	SDL_Surface* overlay_surface = nullptr;
	SDL_Texture* overlay_texture = nullptr;
	std::string overlay_string;
	bool collides(Button*);

public:
	GameOverState(){ };
	~GameOverState(){ };
	 void update();
	 void render();
	 bool onEnter();
	 bool onExit();
	 std::string getStateID() const;
};

