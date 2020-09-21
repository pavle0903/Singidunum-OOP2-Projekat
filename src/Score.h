/*
 * Score.h
 *
 *  Created on: 12.09.2020.
 *      Author: Pavle
 */

#ifndef SCORE_H_
#define SCORE_H_
using namespace std;

#include <string>
#include <SDL2/SDL.h>
#include <SDL2/SDL_ttf.h>


#include "drawable.h"
#include "player.h"

class Score : public Drawable {
public:
	SDL_Rect textRect;
	int TTF_Init();
	TTF_Font *font;
	SDL_Renderer *renderer;
	SDL_Texture *text;
	SDL_Surface *textSurface;
	SDL_Color color;
	bool obrisan = false;
	Score(SDL_Renderer* renderer, int skor, int x, int y, int w, int h);
	void draw(SDL_Renderer *renderer);
	virtual ~Score();
};

#endif /* SCORE_H_ */
