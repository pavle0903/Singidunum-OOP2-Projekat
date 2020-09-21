#ifndef BOARD_H_
#define BOARD_H_


#include "BishopSprite.h"
#include <iostream>
#include <fstream>

#include <vector>

class Board {
public:
	vector<BishopSprite*> BishopSprites;
	Board(vector<BishopSprite*>);
	void load(istream &inputStream);
	void save(ostream &outputStream);
	virtual ~Board();

};

#endif /* BOARD_H_ */
