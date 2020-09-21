/*
 * Predmet.cpp
 *
 *  Created on: 17.09.2020.
 *      Author: Pavle
 */

#include "Predmet.h"

Predmet::Predmet(int width, int height, string slikaPath, SDL_Renderer *renderer) {
	dest = new SDL_Rect();
	dest->x = 50;
	dest->y = -880;
	dest->w = width;
	dest->h = height;

	src = new SDL_Rect();
	src->x = 0;
	src->y = 0;
	src->w = width;
	src->h = height;

	SDL_Surface *surface = IMG_Load(slikaPath.c_str());
	texture = SDL_CreateTextureFromSurface(renderer, surface);
	SDL_FreeSurface(surface);
}

void Predmet::draw(SDL_Renderer *renderer){
	SDL_RenderCopy(renderer, texture, src, dest);
}

Predmet::~Predmet() {
	delete src;
	delete dest;
}

