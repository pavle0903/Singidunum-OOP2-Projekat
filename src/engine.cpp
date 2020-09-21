#include "engine.h"
#include "cmath"
ostream& operator<<(ostream& out, const Level& l) {
    int rows = l.getLevelMatrix().size();
    int cols = 0;
    if(rows > 0) {
        cols = l.getLevelMatrix()[0].size();
    }
    out << rows << " " << cols << endl;

    for(int i = 0; i < rows; i++){
        for(int j = 0; j < cols; j++) {
            out << l.getLevelMatrix()[i][j] << " ";
        }
        out << endl;
    }

    return out;
}

Engine::Engine(string title) {
    SDL_Init(SDL_INIT_VIDEO);
    IMG_Init(IMG_INIT_PNG);
    window = SDL_CreateWindow(title.c_str(), SDL_WINDOWPOS_UNDEFINED,
                              SDL_WINDOWPOS_UNDEFINED, 640, 600, SDL_WINDOW_RESIZABLE);
    renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED);
}

void Engine::addTileset(Tileset *tileset, const string &name) {
    tilesets[name] = tileset;
}

void Engine::addTileset(istream &inputStream, const string &name) {
    addTileset(new Tileset(inputStream, renderer), name);
}

void Engine::addTileset(const string &path, const string &name) {
    ifstream tilesetStream(path);
    addTileset(tilesetStream, name);
}

Tileset* Engine::getTileset(const string &name) {
    return tilesets[name];
}

void Engine::addDrawable(Drawable *drawable) {
    drawables.push_back(drawable);
}

void Engine::run() {
    int maxDelay = 1000/frameCap;
    int frameStart = 0;
    int frameEnd = 0;

    bool running = true;
    SDL_Event event;

    cout << (*dynamic_cast<Level*>(drawables[0])) << endl;

    ifstream savegame("resources/creatures/savegame.txt");
    ifstream spriteSheetStream("resources/creatures/sprite_sheet.txt");
    SpriteSheet *sheet = new SpriteSheet(spriteSheetStream, renderer);

    //ifstream spriteSheetStream2("resources/creatures/human_walk.txt");
    //SpriteSheet *sheet2 = new SpriteSheet(spriteSheetStream2, renderer);

//    Sprite *sp = new Sprite(sheet2);
//    sp->setFrameSkip(4);
//    drawables.push_back(sp);
//    movables.push_back(sp);

    BishopSprite *bs = new BishopSprite(sheet);
    bs->setFrameSkip(4);

    Player *player = new Player(sheet);

    Player *player1 = new Player(sheet);


    Bishops.push_back(player);
    Bishops.push_back(player1);

    Board *board = new Board(Bishops);
    board->load(savegame);

    //iscrtavanje paradajza glupavog, srediti sliku i pojavljivanje
    Paradajz *par = new Paradajz(64, 64, "resources/tilesets/paradajz.png", renderer);
    Paradajz *par1 = new Paradajz(64, 64, "resources/tilesets/paradajz.png", renderer);
    Paradajz *par2 = new Paradajz(64, 64, "resources/tilesets/paradajz.png", renderer);
    //Paradajz *par3 = new Paradajz(64, 64, "resources/tilesets/paradajz.png", renderer);


    drawables.push_back(par);
    paradajzi.push_back(par);
    drawables.push_back(par1);
    paradajzi.push_back(par1);
    drawables.push_back(par2);
	paradajzi.push_back(par2);
	//drawables.push_back(par3);
	//paradajzi.push_back(par3);

    Worker *wo = new Worker(64, 64, "resources/tilesets/poklon.png", renderer);
    drawables.push_back(wo);
    workers.push_back(wo);

    Predmet *p = new Predmet(64, 64, "resources/tilesets/metak.png", renderer);
    drawables.push_back(p);

    Predmet *p1 = new Predmet(64, 64, "resources/tilesets/metak.png", renderer);
	drawables.push_back(p1);

	Predmet *p2 = new Predmet(64, 64, "resources/tilesets/metak.png", renderer);
	drawables.push_back(p2);

	Predmet *p3 = new Predmet(64, 64, "resources/tilesets/metak.png", renderer);
	drawables.push_back(p3);

	Predmet *p4 = new Predmet(64, 64, "resources/tilesets/metak.png", renderer);
	drawables.push_back(p4);

	Predmet *p5 = new Predmet(64, 64, "resources/tilesets/metak.png", renderer);
	drawables.push_back(p5);

	//zivoti
	Predmet *p6 = new Predmet(64, 64, "resources/tilesets/zivot.png", renderer);
	drawables.push_back(p6);
	Predmet *p7 = new Predmet(64, 64, "resources/tilesets/zivot.png", renderer);
	drawables.push_back(p7);
	Predmet *p8 = new Predmet(64, 64, "resources/tilesets/zivot.png", renderer);
	drawables.push_back(p8);
	zivoti.push_back(p6);
	zivoti.push_back(p7);
	zivoti.push_back(p8);

	//zivoti
	p6->dest->x = 480;
	p6->dest->y = 540;
	p7->dest->x = 530;
	p7->dest->y = 540;
	p8->dest->x = 580;
	p8->dest->y = 540;

	//vatrice
	p1->dest->x = 150;
	p2->dest->x = 250;
	p3->dest->x = 350;
	p4->dest->x = 450;
	p5->dest->x = 550;

	predmeti.push_back(p);
	predmeti.push_back(p1);
	predmeti.push_back(p2);
	predmeti.push_back(p3);
	predmeti.push_back(p4);
	predmeti.push_back(p5);

	p->dest->y = - 1000;
	p1->dest->y = - 2000;
	p3->dest->y = - 3000;
	p4->dest->y = - 4000;
	p5->dest->y = - 5000;

    if (TTF_Init() < 0){
		cout << "Error" << TTF_GetError() << endl;
	}


    Score *sc = new Score(renderer, player->score, 292, 58, 192, 32);
    drawables.push_back(sc);
    scores.push_back(sc);

    drawables.push_back(player);
    movables.push_back(player);
    eventListeners.push_back(player);

//    drawables.push_back(player1);
//    movables.push_back(player1);
//    eventListeners.push_back(player1);


    while(running) {
        frameStart = SDL_GetTicks();
        while(SDL_PollEvent(&event)) {
            if(event.type == SDL_QUIT) {
            	ofstream savegame("resources/creatures/savegame.txt");
            	board->save(savegame);
            	savegame.close();
                running = false;
            } else {
                for(size_t i = 0; i < eventListeners.size(); i++) {
                    eventListeners[i]->listen(event);
                }
            }
        }

        		for (Predmet *pr : predmeti){
        			if (player->score <= 50){
        				pr->dest->y += rand() % 10;
        			}
        			else if (player->score > 50 and player->score <= 75){
        				pr->dest->y += rand() %15;

        			}
        			else if (player->score > 75){
        				pr->dest->y += rand()% 20;

        			}
        			if(pr->dest->y > 600){
						pr->dest->y = -550;
					}
        		}
//        	}
//        }


        if (player->spriteRect->x <= 2){
        	player->spriteRect->x = 2;
        }
        else if(player->spriteRect->x >= 600){
        	player->spriteRect->x = 600;
        }
        else if(player->spriteRect->y <= 0){
        	player->spriteRect->y = 0;
        }
        else if(player->spriteRect->y >= 550){
        	player->spriteRect->y = 550;
        }

        for(size_t i = 0; i < movables.size(); i++) {
            movables[i]->move();

            for(Predmet *pr : predmeti){
            	player->kolizijaPredmet(pr);

//            	if(player->zivot == 0){
//            		p8->~Predmet();
//            		cout << "gotovo" << endl;
//            	}

            	if (player->mrtav == true){
            		cout << "kraj" << endl;
            		player->zivot -=1;
            		player->mrtav = false;

            		if(player->zivot == 2){
            			p6->~Predmet();
            		}
            		if(player->zivot == 1){
            			p7->~Predmet();
            		}
            		if(player->zivot == 0){
            			p8->~Predmet();
            			player->spriteRect->x = 300;
            			player->spriteRect->y = 500;
            			//p8->~Predmet();
            			for(Worker *w : workers){
            				w->~Worker();
            			}
            			for(Predmet *pr : zivoti){
            				pr->~Predmet();
            			}
            			for(Predmet *p : predmeti){
            				p->~Predmet();
						}
						for(Paradajz *p: paradajzi){
							p->~Paradajz();
						}
//						for(Score *s : scores){
//							s->~Score();
//						}
						player->score = 0;
//						Score *sc = new Score(renderer, player->score, 292, 58, 192, 32);
//						drawables.push_back(sc);
//						scores.push_back(sc);
						Gameover *go = new Gameover(renderer, "Game over!", 150, 250, 64, 64);
						drawables.push_back(go);
						//Gameover *go1 = new Gameover(renderer, "Press space to play again!", 20, 350, 64, 64);
						//drawables.push_back(go1);


            		}
            	}
            }

            for(Worker *w : workers){
            	player->kolizijaPoklon(w);

            	if (w->obrisan == true){
            		w->dest->x = 900;
            		w->dest->y = 900;
            		//cout << player->score << "aa" <<endl;
            		//w->obrisan = false;
            	}
            	if (player->score == 35 or player->score == 46 or player->score == 53){
            		player->score+=1;
            		w->dest->x = rand() %450 + 100;
            		w->dest->y = rand() %450 + 100;
            		w->obrisan=false;
            	}


				if (player->score == 32 or player->score == 42 or player->score == 52 or player->score == 62){
					player->pronasao = false;
				}
			}

            for (Paradajz *p : paradajzi){
            	player->kolizija(p);
            	if (p->obrisan == true){

					for(Score *s : scores){
						s->~Score();
					}
					Score *sc = new Score(renderer, player->score, 292, 58, 192, 32);
					drawables.push_back(sc);
					scores.push_back(sc);
		//            //sc->~Score();
					p->obrisan = false;
		//        }
				}
            }
        }

//        SDL_SetRenderDrawColor(renderer, 0, 0, 0, 255);
//        SDL_RenderClear(renderer);

        for(size_t i = 0; i < drawables.size(); i++) {
            drawables[i]->draw(renderer);
        }

        SDL_RenderPresent(renderer);

        frameEnd = SDL_GetTicks();
        if(frameEnd - frameStart < maxDelay) {
            SDL_Delay(maxDelay - (frameEnd - frameStart));
        }
    }
}

Engine::~Engine() {
    SDL_DestroyRenderer(renderer);
    SDL_DestroyWindow(window);
    SDL_Quit();
}
