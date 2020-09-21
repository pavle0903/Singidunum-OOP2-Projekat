#include "Board.h"

Board::Board(vector<BishopSprite*> BishopSprites) {
	this->BishopSprites = BishopSprites;

}

void Board::save(ostream &outputStream){
	for(BishopSprite* bs : BishopSprites){
		outputStream << bs->spriteRect->x << " " << bs->spriteRect->y << " ";
	}
}

void Board::load(istream &inputStream){
	while(!inputStream.eof()){
		for(BishopSprite *bs : BishopSprites){
			inputStream >> bs->spriteRect->x >> bs->spriteRect->y;
		}
	}
}

Board::~Board() {
	// TODO Auto-generated destructor stub
}

