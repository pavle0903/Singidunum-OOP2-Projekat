#include "BishopSprite.h"

BishopSprite::BishopSprite(SpriteSheet *sheet, int width, int height) : Sprite(sheet, width, height) {
	// TODO Auto-generated constructor stub

}

void BishopSprite::move(int dx, int dy){
	spriteRect->x += 2*dx; //ovde *64
	spriteRect->y += 2*dy;
}

void BishopSprite::move(){
	if(state != 0){
		if(state & 1) {
			move(-1, 0);
		}
		if(state & 2) {
			move(1, 0);
		}
		if(state & 4) {
			move(0, -1);
		}
		if(state & 8) {
			move(0, 1);
		}
//		if(state & 1 and(state & 4)){
//			move(-1, -1);
//
//		}
//		if(state & 1 and(state & 8)){
//			move(-1, 1);
//
//		}
//		if(state & 2 and(state & 4)){
//			move(1, -1);
//
//		}
//		if(state & 2 and(state & 8)){
//			move(1, 1);
//
//		}
	}
}

BishopSprite::~BishopSprite() {
	// TODO Auto-generated destructor stub
}

