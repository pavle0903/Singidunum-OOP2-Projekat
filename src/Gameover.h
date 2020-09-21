/*
 * Gameover.h
 *
 *  Created on: 18.09.2020.
 *      Author: Pavle
 */

#ifndef GAMEOVER_H_
#define GAMEOVER_H_
using namespace std;

#include <string>
#include <SDL2/SDL.h>
#include <SDL2/SDL_ttf.h>

#include "drawable.h"

class Gameover : public Drawable {
public:
	SDL_Rect textRect;
	TTF_Font *font;
	SDL_Renderer *renderer;
	SDL_Texture *text;
	SDL_Surface *textSurface;
	SDL_Color color;
	Gameover(SDL_Renderer *renderer, string tekst, int x, int y, int w, int h);
	void draw(SDL_Renderer *renderer);
	virtual ~Gameover();
};

#endif /* GAMEOVER_H_ */
