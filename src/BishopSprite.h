#ifndef BISHOPSPRITE_H_
#define BISHOPSPRITE_H_

#include "sprite.h"
#include "spritesheet.h"

class BishopSprite : public Sprite {
public:
	char color;
	BishopSprite(SpriteSheet *sheet, int width = 64, int height = 64);
	virtual void move();
	virtual void move(int dx, int dy);
	virtual ~BishopSprite();
};

#endif /* BISHOPSPRITE_H_ */
