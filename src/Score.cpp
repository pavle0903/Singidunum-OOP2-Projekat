/*
 * Score.cpp
 *
 *  Created on: 12.09.2020.
 *      Author: Pavle
 */

#include "Score.h"

Score::Score(SDL_Renderer* renderer, int skor, int x, int y, int w, int h) : Drawable() {
		this->renderer = renderer;

		this->font=TTF_OpenFont("lazy.ttf", 48);
		if(font == NULL) {
		    printf("TTF_OpenFont: %s\n", TTF_GetError());
		    // handle error
		}
		this->color = {170, 225, 120, 152};
		this->textSurface = TTF_RenderText_Solid(font, to_string(skor).c_str(), color);
		this->text = SDL_CreateTextureFromSurface(renderer, textSurface);
		SDL_FreeSurface(textSurface);
		this->textRect.x = x;
		this->textRect.y = y;
		this->textRect.w = w;
		this->textRect.h = h;

		SDL_QueryTexture(text, NULL, NULL, &textRect.w, &textRect.h);

}

void Score::draw(SDL_Renderer *renderer){

	SDL_RenderCopy(renderer, text, NULL, &textRect);

}

Score::~Score() {
	SDL_DestroyTexture(text);
}

