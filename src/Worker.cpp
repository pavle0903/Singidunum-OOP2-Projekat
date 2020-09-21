/*
 * Worker.cpp
 *
 *  Created on: 15.09.2020.
 *      Author: Pavle
 */

#include "Worker.h"

Worker::Worker(int width, int height, string sprite, SDL_Renderer *renderer) {
	dest = new SDL_Rect();
	dest->x = rand() %400 + 100;
	dest->y = rand() %400 + 100;
	dest->w = width;
	dest->h = height;


	src = new SDL_Rect();
	src->x = 0;
	src->y = 0;
	src->w = width;
	src->h = height;

	SDL_Surface *surface = IMG_Load(sprite.c_str());
	text = SDL_CreateTextureFromSurface(renderer, surface);
	SDL_FreeSurface(surface);
}

void Worker::draw(SDL_Renderer *renderer){
	if(!obrisan){
		SDL_RenderCopy(renderer, text, src, dest);
	}
	//SDL_RenderCopy(renderer, text, src, dest);
}

Worker::~Worker() {
	delete src;
	delete dest;
}

