#pragma once
#include "IGameState.hpp"
#include "../GameManager.hpp"
#include "../../utils/InputHandler.hpp"
#include "../../entity/Button.hpp"
#include "PlayState.hpp"

class MenuState: public GameState {
private:
	std::string playID = "Menu";
	Uint32 i=0;
	std::vector<Button*> buttons;

	SDL_Rect overlay_offset = {0,0,TILEW,TILEH};
	SDL_Surface* overlay_surface = nullptr;
	SDL_Texture* overlay_texture = nullptr;
	std::string overlay_string;

	bool collides(Button*);

	SDL_Window* win2 = nullptr;
	SDL_Renderer* ren2 = nullptr;
	Uint8 infoWindow();
public:
	MenuState(){ };
	~MenuState(){ };
	 void update();
	 void render();
	 bool onEnter();
	 bool onExit();
	 std::string getStateID() const;
};

