#pragma once

#define REQ_DELAY 1000/60

#define SCR_WIDTH 900
#define SCR_HEIGHT 666

#define TILEW 64
#define TILEH 64

#define LOG_NEWENTITY printf("add x:%d y:%d hp:%d\n",(int)posX,(int)posY,hp);

#define MOUSEX InputHandler::getInstance()->getMouseX()
#define MOUSEY InputHandler::getInstance()->getMouseY()
#define RENDERER Game::getInstance()->getRenderer()
#define SHEET GameManager::getInstance()->getSheet()
#define CURSORRECT GameManager::getInstance()->getRekt(2,5)

