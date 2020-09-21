/*
 * Predmet.h
 *
 *  Created on: 17.09.2020.
 *      Author: Pavle
 */

#ifndef PREDMET_H_
#define PREDMET_H_
using namespace std;

#include <string>
#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include "drawable.h"

class Predmet : public Drawable {
public:
	SDL_Rect *src;
	SDL_Rect *dest;
	SDL_Texture *texture;
	int width;
	int height;
	Predmet(int width, int height, string slikaPath, SDL_Renderer *renderer);
	void draw(SDL_Renderer *renderer);
	virtual ~Predmet();
};

#endif /* PREDMET_H_ */
