#include "MenuState.hpp"

void MenuState::update(){
	if(InputHandler::getInstance()->isMBDown(1)){
		for(i=1;i<buttons.size();++i){
			if(collides(buttons[i])){
				switch(i){
				case 1:{
					GameManager::getInstance()->pushState(new PlayState());
					SDL_Delay(200);
					break;
				}
				case 2:{
					Game::getInstance()->stop();
					break;
				}
				case 3:{
					infoWindow();
					break;
				}
				default: break;
				}
			}
		}
	}
}

void MenuState::render(){
		SDL_RenderClear(Game::getInstance()->getRenderer());

		overlay_string = "Играть";
		overlay_surface = TTF_RenderUTF8_Solid(
				GameManager::getInstance()->getFont(),
				overlay_string.c_str(),
				GameManager::getInstance()->getFontColor()
				);
		overlay_texture = SDL_CreateTextureFromSurface(Game::getInstance()->getRenderer(),overlay_surface);
		overlay_offset = {128+16,SCR_HEIGHT/2-64+16,overlay_surface->w,overlay_surface->h};

		for(i=0;i<buttons.size();++i){
			buttons[i]->render();
		}
		SDL_RenderCopy(Game::getInstance()->getRenderer(),overlay_texture,0,&overlay_offset);
		SDL_FreeSurface(overlay_surface);

		overlay_string = "Выйти";
		overlay_surface = TTF_RenderUTF8_Solid(
				GameManager::getInstance()->getFont(),
				overlay_string.c_str(),
				GameManager::getInstance()->getFontColor()
				);
		overlay_texture = SDL_CreateTextureFromSurface(Game::getInstance()->getRenderer(),overlay_surface);
		overlay_offset = {128+16,SCR_HEIGHT/2+20+16,overlay_surface->w,overlay_surface->h};
		SDL_RenderCopy(Game::getInstance()->getRenderer(),overlay_texture,0,&overlay_offset);

		SDL_FreeSurface(overlay_surface);

		overlay_string = "Меню";
		overlay_surface = TTF_RenderUTF8_Solid(
				GameManager::getInstance()->getFont(),
				overlay_string.c_str(),
				GameManager::getInstance()->getFontColor()
				);
		overlay_texture = SDL_CreateTextureFromSurface(Game::getInstance()->getRenderer(),overlay_surface);
		overlay_offset = {128+16,SCR_HEIGHT/2-116,overlay_surface->w,overlay_surface->h};
		SDL_RenderCopy(Game::getInstance()->getRenderer(),overlay_texture,0,&overlay_offset);

		SDL_FreeSurface(overlay_surface);

		overlay_string = "Инфо";
		overlay_surface = TTF_RenderUTF8_Solid(
				GameManager::getInstance()->getFont(),
				overlay_string.c_str(),
				GameManager::getInstance()->getFontColor()
				);
		overlay_texture = SDL_CreateTextureFromSurface(Game::getInstance()->getRenderer(),overlay_surface);
		overlay_offset = {128+20,SCR_HEIGHT/2+128-16,overlay_surface->w,overlay_surface->h};
		SDL_RenderCopy(Game::getInstance()->getRenderer(),overlay_texture,0,&overlay_offset);

		SDL_FreeSurface(overlay_surface);

}

bool MenuState::onEnter(){
	SDL_RenderClear(Game::getInstance()->getRenderer());
	buttons.push_back(new Button(128-48,SCR_HEIGHT/2-128-32,TILEW,TILEH,100));
	buttons.push_back(new Button(128,SCR_HEIGHT/2-64,TILEW,TILEH,100));
	buttons.push_back(new Button(128,SCR_HEIGHT/2+20,TILEW,TILEH,100));
	buttons.push_back(new Button(128,SCR_HEIGHT/2+100,TILEW,TILEH,100));
	overlay_string = "Играть";
	overlay_surface = TTF_RenderUTF8_Solid(
			GameManager::getInstance()->getFont(),
			overlay_string.c_str(),
			GameManager::getInstance()->getFontColor()
			);
	overlay_texture = SDL_CreateTextureFromSurface(Game::getInstance()->getRenderer(),overlay_surface);
	overlay_offset = {128+16,SCR_HEIGHT/2-64+16,overlay_surface->w,overlay_surface->h};

	buttons[1]->setW(overlay_surface->w+32); buttons[1]->setH(overlay_surface->h+32);
	buttons[2]->setW(overlay_surface->w+32); buttons[2]->setH(overlay_surface->h+32);
	buttons[3]->setW(overlay_surface->w+32); buttons[3]->setH(overlay_surface->h+32);
	buttons[0]->setW(buttons[1]->getW()+64+32); buttons[0]->setH(buttons[1]->getH()+buttons[2]->getH()+220);

	for(i=0;i<buttons.size();++i){
		buttons[i]->render();
	}
	SDL_RenderCopy(Game::getInstance()->getRenderer(),overlay_texture,0,&overlay_offset);
	SDL_FreeSurface(overlay_surface);


	return true;
}

bool MenuState::collides(Button* btn){
	if ( MOUSEY < (btn->getPosY()) )	return false;
	// Правая сторона а дальше чем левая b
	if ( MOUSEX < (btn->getPosX()) )	return false;
	// Верх а ниже чем низ b
	if ( MOUSEY > (btn->getPosY() + btn->getH()) )	return false;
	// Лево а ближе чем право b
	if ( MOUSEX > (btn->getPosX() + btn->getW()) )	return false;
	return true;
}

bool MenuState::onExit(){
	printf("pop state 'menu'\n");

	return true;
}

std::string MenuState::getStateID() const{
	return playID;
}

Uint8 MenuState::infoWindow(){
	if(win2 || ren2) return -1;
	if(SDL_CreateWindowAndRenderer(600, 120, SDL_WINDOW_SHOWN, &win2, &ren2) < 0) {
		printf("Failed at SDL_CreateWindowAndRenderer");
		SDL_Quit();
		return 1;
	}
	SDL_SetWindowTitle(win2, "Info");
	SDL_SetWindowIcon(win2, SDL_LoadBMP("res/ico.bmp"));
	SDL_SetRenderDrawColor( ren2, 74, 53, 91, 255 );
	SDL_RenderClear(ren2);
	overlay_string = "Выполнено студентом БГТУ ВОЕНМЕХ";
	overlay_surface = TTF_RenderUTF8_Solid(
			GameManager::getInstance()->getFont(),
			overlay_string.c_str(),
			GameManager::getInstance()->getFontColor()
			);
	overlay_texture = SDL_CreateTextureFromSurface(ren2,overlay_surface);
	overlay_offset = {20,20,overlay_surface->w,overlay_surface->h};
	SDL_RenderCopy(ren2,overlay_texture,0,&overlay_offset);
	SDL_FreeSurface(overlay_surface);
	overlay_string = "группы И595 Кривых А.С. в 2020-2021г.";
		overlay_surface = TTF_RenderUTF8_Solid(
				GameManager::getInstance()->getFont(),
				overlay_string.c_str(),
				GameManager::getInstance()->getFontColor()
				);
		overlay_texture = SDL_CreateTextureFromSurface(ren2,overlay_surface);
		overlay_offset = {20,60,overlay_surface->w,overlay_surface->h};
		SDL_RenderCopy(ren2,overlay_texture,0,&overlay_offset);
		SDL_FreeSurface(overlay_surface);

	SDL_RenderPresent(ren2);
	return 0;
}
