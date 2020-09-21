/*
 * Paradajz.cpp
 *
 *  Created on: 11.09.2020.
 *      Author: Pavle
 */

#include "Paradajz.h"

Paradajz::Paradajz(int width, int height, string sheetPath, SDL_Renderer *renderer) {
	dest = new SDL_Rect();
	dest->x = rand() % 400 + 100;
	dest->y = rand() % 400 + 100;
	dest->w = width;
	dest->h = height;
	this->width = width;
	this->height = height;

	src = new SDL_Rect();
	src->x = 0;
	src->y = 0;
	src->w = width;
	src->h = height;

	SDL_Surface *surface = IMG_Load(sheetPath.c_str());
	texture = SDL_CreateTextureFromSurface(renderer, surface);
	SDL_FreeSurface(surface);
}

void Paradajz::draw(SDL_Renderer *renderer){
	SDL_RenderCopy(renderer, texture, src, dest);
}

Paradajz::~Paradajz() {
	delete src;
	delete dest;
}

