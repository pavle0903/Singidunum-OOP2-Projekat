/*
 * Worker.h
 *
 *  Created on: 15.09.2020.
 *      Author: Pavle
 */

#ifndef WORKER_H_
#define WORKER_H_
using namespace std;
#include <string>
#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>

#include "drawable.h"

class Worker : public Drawable{
public:
	SDL_Rect *src;
	SDL_Rect *dest;
	SDL_Texture *text;
	int width;
	int height;
	bool obrisan = false;
	Worker(int width, int height, string sprite, SDL_Renderer *renderer);
	void draw(SDL_Renderer *renderer);
	virtual ~Worker();
};

#endif /* WORKER_H_ */
