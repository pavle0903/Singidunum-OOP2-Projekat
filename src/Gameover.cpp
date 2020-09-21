/*
 * Gameover.cpp
 *
 *  Created on: 18.09.2020.
 *      Author: Pavle
 */

#include "Gameover.h"

Gameover::Gameover(SDL_Renderer *renderer, string tekst, int x, int y, int w, int h) : Drawable() {
	this->renderer =renderer;
	this->font = TTF_OpenFont("lazy.ttf", 72);
	this->color = {255, 255, 255, 255};
	this->textSurface = TTF_RenderText_Solid(font, tekst.c_str(), color);
	this->text = SDL_CreateTextureFromSurface(renderer, textSurface);
	SDL_FreeSurface(textSurface);
	this->textRect.x = x;
	this->textRect.y = y;
	this->textRect.w = w;
	this->textRect.h = h;

	SDL_QueryTexture(text, NULL, NULL, &textRect.w, &textRect.h);
}

void Gameover::draw(SDL_Renderer *renderer){
	SDL_RenderCopy(renderer, text, NULL, &textRect);
}

Gameover::~Gameover() {
	SDL_DestroyTexture(text);
}

