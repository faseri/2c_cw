#include "GameOverState.hpp"

void GameOverState::update(){
	if(InputHandler::getInstance()->isMBDown(1)){
		for(i=1;i<buttons.size();++i){
			if(collides(buttons[i])){
				switch(i){
				case 2:{
					GameManager::getInstance()->popState();
					GameManager::getInstance()->popState();
					SDL_Delay(200);
					break;
				}
				case 1:{
					GameManager::getInstance()->popState();
					GameManager::getInstance()->popState();
					GameManager::getInstance()->pushState(new PlayState());
					SDL_Delay(200);
					break;
				}
				default: break;
				}
			}
		}
	}
}

void GameOverState::render(){

}

bool GameOverState::onEnter(){
	buttons.push_back(new Button(128-48,SCR_HEIGHT/2-128-32,TILEW,TILEH,100));
	buttons.push_back(new Button(128,SCR_HEIGHT/2-64,TILEW,TILEH,100));
	buttons.push_back(new Button(128,SCR_HEIGHT/2+20,TILEW,TILEH,100));
	overlay_string = "Повторить";
	overlay_surface = TTF_RenderUTF8_Solid(
			GameManager::getInstance()->getFont(),
			overlay_string.c_str(),
			GameManager::getInstance()->getFontColor()
			);
	overlay_texture = SDL_CreateTextureFromSurface(Game::getInstance()->getRenderer(),overlay_surface);
	overlay_offset = {128+16,SCR_HEIGHT/2-64+16,overlay_surface->w,overlay_surface->h};

	buttons[1]->setW(overlay_surface->w+32); buttons[1]->setH(overlay_surface->h+32);
	buttons[2]->setW(overlay_surface->w+32); buttons[2]->setH(overlay_surface->h+32);
	buttons[0]->setW(buttons[1]->getW()+64+32); buttons[0]->setH(buttons[1]->getH()+buttons[2]->getH()+128+32);

	for(i=0;i<buttons.size();++i){
		buttons[i]->render();
	}
	SDL_RenderCopy(Game::getInstance()->getRenderer(),overlay_texture,0,&overlay_offset);
	SDL_FreeSurface(overlay_surface);

	overlay_string = "В меню";
	overlay_surface = TTF_RenderUTF8_Solid(
			GameManager::getInstance()->getFont(),
			overlay_string.c_str(),
			GameManager::getInstance()->getFontColor()
			);
	overlay_texture = SDL_CreateTextureFromSurface(Game::getInstance()->getRenderer(),overlay_surface);
	overlay_offset = {128+32,SCR_HEIGHT/2+20+16,overlay_surface->w,overlay_surface->h};
	SDL_RenderCopy(Game::getInstance()->getRenderer(),overlay_texture,0,&overlay_offset);

	SDL_FreeSurface(overlay_surface);

	overlay_string = "Игра окончена";
	overlay_surface = TTF_RenderUTF8_Solid(
			GameManager::getInstance()->getFont(),
			overlay_string.c_str(),
			GameManager::getInstance()->getFontColor()
			);
	overlay_texture = SDL_CreateTextureFromSurface(Game::getInstance()->getRenderer(),overlay_surface);
	overlay_offset = {128-16,SCR_HEIGHT/2-128,overlay_surface->w,overlay_surface->h};
	SDL_RenderCopy(Game::getInstance()->getRenderer(),overlay_texture,0,&overlay_offset);

	SDL_FreeSurface(overlay_surface);

	return true;
}

bool GameOverState::collides(Button* btn){
	if ( MOUSEY < (btn->getPosY()) )	return false;
	// Правая сторона а дальше чем левая b
	if ( MOUSEX < (btn->getPosX()) )	return false;
	// Верх а ниже чем низ b
	if ( MOUSEY > (btn->getPosY() + btn->getH()) )	return false;
	// Лево а ближе чем право b
	if ( MOUSEX > (btn->getPosX() + btn->getW()) )	return false;
	return true;
}

bool GameOverState::onExit(){
	printf("pop state 'gameover'\n");
	return true;
}

std::string GameOverState::getStateID() const{
	return playID;
}
