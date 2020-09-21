#ifndef PLAYER_H_INCLUDED
#define PLAYER_H_INCLUDED

#include <SDL2/SDL.h>

#include "drawable.h"
#include "movable.h"
#include "keyboardeventlistener.h"
#include "sprite.h"
#include "BishopSprite.h"
#include "spritesheet.h"
#include "Paradajz.h"
#include "Score.h"
#include "Worker.h"
#include "Predmet.h"

//class Worker;

class Player : public BishopSprite, public KeyboardEventListener {
public:
	int score = 20;
	int width;
	int height;
	int x;
	int y;
	bool pronasao = false;
	bool poklon = false;
	bool mrtav = false;
	int zivot = 3;
    Player(SpriteSheet *sheet, int width=64, int height=64);
    virtual void draw(SDL_Renderer *renderer);
    virtual void move(int dx, int dy);
    virtual void listen(SDL_KeyboardEvent &event);
    virtual void kolizija(Paradajz *par);
    virtual void kolizijaPoklon(Worker *work);
    virtual void kolizijaPredmet(Predmet *predmet);
    virtual ~Player();

};

#endif // PLAYER_H_INCLUDED
