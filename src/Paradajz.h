/*
 * Paradajz.h
 *
 *  Created on: 11.09.2020.
 *      Author: Pavle
 */

#ifndef PARADAJZ_H_
#define PARADAJZ_H_
using namespace std;

#include <string>
#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>

#include "drawable.h"

class Paradajz : public Drawable{
public:
	SDL_Rect *src;
	SDL_Rect *dest;
	SDL_Texture *texture;
	int width;
	int height;
	bool obrisan = false;
	Paradajz(int width, int height, string sheetPath, SDL_Renderer *renderer);
	void draw(SDL_Renderer *renderer);
	virtual ~Paradajz();
};

#endif /* PARADAJZ_H_ */
