#include "player.h"
#include "cmath"

Player::Player(SpriteSheet *sheet, int width, int height) : BishopSprite(sheet, width, height){
	this->width = width;
	this->height = height;
	this->x = x;
	this->y = y;
}

void Player::draw(SDL_Renderer *renderer) {
	if(state&LEFT) {
			sheet->drawFrame("walk_left", currentFrame, spriteRect, renderer);
		} else if(state&RIGHT) {
			sheet->drawFrame("walk_right", currentFrame, spriteRect, renderer);
		} else if(state&UP) {
			sheet->drawFrame("walk_up", currentFrame, spriteRect, renderer);
		} else if(state&DOWN) {
			sheet->drawFrame("walk_down", currentFrame, spriteRect, renderer);
		} else if(state == STOP) {
			sheet->drawFrame("walk_down", 0, spriteRect, renderer);
		}

		frameCounter++;
		if(frameCounter%frameSkip == 0) {
			currentFrame++;
			if(currentFrame >= 9) {
				currentFrame = 0;
			}
			frameCounter = 0;
		}
}

void Player::listen(SDL_KeyboardEvent &event) {
    if(event.type == SDL_KEYDOWN) {
        if(event.keysym.sym == SDLK_LEFT or event.keysym.sym == SDLK_a) {
            this->setState(this->getState()|Sprite::LEFT);
        } else if(event.keysym.sym == SDLK_RIGHT or event.keysym.sym == SDLK_d) {
        	this->setState(this->getState()|Sprite::RIGHT);
        } else if(event.keysym.sym == SDLK_UP or event.keysym.sym == SDLK_w) {
        	this->setState(this->getState()|Sprite::UP);
        } else if(event.keysym.sym == SDLK_DOWN or event.keysym.sym == SDLK_s) {
        	this->setState(this->getState()|Sprite::DOWN);
        }

    } else if (event.type == SDL_KEYUP) {
        if(event.keysym.sym == SDLK_LEFT or event.keysym.sym == SDLK_a) {
        	this->setState(this->getState()&~Sprite::LEFT);
        } else if(event.keysym.sym == SDLK_RIGHT or event.keysym.sym == SDLK_d) {
        	this->setState(this->getState()&~Sprite::RIGHT);
        } else if(event.keysym.sym == SDLK_UP or event.keysym.sym == SDLK_w) {
        	this->setState(this->getState()&~Sprite::UP);
        } else if(event.keysym.sym == SDLK_DOWN or event.keysym.sym == SDLK_s) {
        	this->setState(this->getState()&~Sprite::DOWN);
        }
    }

}

void Player::kolizija(Paradajz *par){
	//double velikoR = sqrt((64*64)+(64*64));
	//double r = velikoR/2;
	int currentX = this->spriteRect->x;
	int currentY = this->spriteRect->y;
	//cout << par->dest->x << " " << par->dest->y << endl;
	//cout << currentX << " " << currentY << endl;
	//cout << par->dest->x << " "<< par->dest->y << endl;
	if (sqrt((par->dest->x - currentX)*(par->dest->x - currentX) + (par->dest->y - currentY)*(par->dest->y - currentY)) < 32){
	//if(par->dest->x == currentX and par->dest->y == currentY){
		score ++;
		cout << "kolizija" << endl;
		par->dest->x = rand() % 450 + 100;
		par->dest->y = rand() % 450 + 100;
		//par->~Paradajz();
		//skor->~Score();
//		if (score == 30){
//			poklon = true;
//		}
		par->obrisan = true;

	}
}

void Player::kolizijaPoklon(Worker *work){
	int currentX = this->spriteRect->x;
	int currentY = this->spriteRect->y;

	if (sqrt((work->dest->x - currentX)*(work->dest->x - currentX) + (work->dest->y - currentY)*(work->dest->y - currentY)) < 32){
		pronasao = true;
		work->obrisan = true;

	}
}

void Player::kolizijaPredmet(Predmet *predmet){
	int currentX = this->spriteRect->x;
	int currentY = this->spriteRect->y;

	if (sqrt((predmet->dest->x - currentX)*(predmet->dest->x - currentX) + (predmet->dest->y - currentY)*(predmet->dest->y - currentY)) < 32){
		predmet->dest->y = -50;
		mrtav = true;
	}
}

void Player::move(int dx, int dy){
	if(pronasao == true){
		spriteRect->x += 6*dx;
		spriteRect->y += 6*dy;
	}else {
		spriteRect->x += 4*dx;
		spriteRect->y += 4*dy;
	}
}

Player::~Player(){

}
