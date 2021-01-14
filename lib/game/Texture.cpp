#include "Texture.hpp"

Texture::Texture( int xCoord, int yCoord, int width, int height){
	col.x = xCoord;
	col.y = yCoord;
	col.w = width;
	col.h = height;
}
SDL_Rect* Texture::getRekt(Uint8 state){
	rect = { (col.x + col.w * state), col.y, col.w, col.h};
	return &rect;
}

int Texture::getW(){
	return col.w;
}
int Texture::getH(){
	return col.h;
}
