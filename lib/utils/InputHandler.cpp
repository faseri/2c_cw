#include "InputHandler.hpp"


InputHandler* InputHandler::instance = 0;

void InputHandler::update(){
	SDL_Event event;
	while(SDL_PollEvent(&event) ){
		switch(event.type) {
				case SDL_QUIT:
					Game::getInstance()->stop();
					return;
				case SDL_MOUSEMOTION:
					// без getInstance()-> не позволяет скомпилировать
					getInstance()->onMouseMove(event);
					break;
				case SDL_MOUSEBUTTONDOWN:
					getInstance()->onMouseButtonDown(event);
					break;
				case SDL_MOUSEBUTTONUP:
					getInstance()->onMouseButtonUp(event);
					break;
				case SDL_KEYDOWN:
					getInstance()->onKeyDown();
					break;
				case SDL_KEYUP:
					getInstance()->onKeyUp();
					break;
				default:
					break;
			}
	}
}
bool InputHandler::isKeyDown(SDL_Scancode key) {
    if(keystate){
        return keystate[key];
    }
    return false;
}

void InputHandler::onKeyDown() {
    keystate = (Uint8*)SDL_GetKeyboardState(0);
}
void InputHandler::onKeyUp(){
	keystate = (Uint8*)SDL_GetKeyboardState(0);
}

void InputHandler::onMouseMove(SDL_Event& event) {
	mouseX = event.motion.x;
	mouseY = event.motion.y;
}
Sint32 InputHandler::getMouseX(){
	return mouseX;
}
Sint32 InputHandler::getMouseY(){
	return mouseY;
}
// SDL_BUTTON_LEFT = 1
// SDL_BUTTON_MIDDLE = 2
// SDL_BUTTON_RIGHT	= 3
void InputHandler::onMouseButtonDown(SDL_Event& event) {
	mouseBtn[event.button.button] = true;
}
void InputHandler::onMouseButtonUp(SDL_Event& event) {
	mouseBtn[event.button.button] = false;
}

bool InputHandler::isMBDown(int buttonNumber) {
    return mouseBtn[buttonNumber];
}
