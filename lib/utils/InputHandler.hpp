#pragma once
#include <vector>
#include <SDL2/SDL.h>
#include <SDL2/SDL_events.h>

#include "../game/Game.hpp"

enum mouse_buttons
{
    LMB = 0,
    MWB = 1,
    RMB = 2
};

class InputHandler{
public:
	static InputHandler* getInstance(){
		if (!instance) {
			instance = new InputHandler();
		}
	return instance;
	}
	static void update();
	bool isKeyDown(SDL_Scancode key);
	bool isMBDown(int button);
private:
	InputHandler(){
		mouseX = 0;
		mouseY = 0;
		mouseBtn.push_back(false); // для трех кнопок мыши
		mouseBtn.push_back(false);
		mouseBtn.push_back(false);
		keystate = (Uint8*)SDL_GetKeyboardState(0);
	};
	~InputHandler(){
		delete keystate;
	};
	void onKeyDown();
	void onKeyUp();
	void onMouseButtonDown(SDL_Event& event);
	void onMouseMove(SDL_Event& event);
	void onMouseButtonUp(SDL_Event & event);
	static InputHandler* instance;
	std::vector<bool> mouseBtn;
	Uint16 mouseX;
	Uint16 mouseY;
	Uint8* keystate;
};
