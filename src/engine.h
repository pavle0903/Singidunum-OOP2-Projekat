#ifndef ENGINE_H_INCLUDED
#define ENGINE_H_INCLUDED

#include <fstream>
#include <string>
#include <vector>
#include <map>

#include <iostream>

#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>

#include "drawable.h"
#include "movable.h"
#include "tileset.h"
#include "level.h"
#include "spritesheet.h"
#include "sprite.h"

#include "eventlistener.h"

#include "BishopSprite.h"
#include "player.h"
#include "Paradajz.h"
#include "Score.h"
#include "Worker.h"
#include "Predmet.h"
#include "Gameover.h"

using namespace std;

#include "Board.h"

/** \brief Klasa koja je zadužena za upravljanje svim entitetima u igri.
 */
class Engine {
private:
	vector<Predmet*> zivoti;
	vector<Predmet*> predmeti;
	vector<Worker*> workers;
	vector<Score*> scores;
	vector<Player*> players;
	vector<Paradajz*> paradajzi;
	vector<BishopSprite*> Bishops;
    map<string, Tileset*> tilesets;
    vector<Drawable*> drawables;
    vector<Movable*> movables;
    vector<EventListener*> eventListeners;
    SDL_Window *window;
    SDL_Renderer *renderer;
    int frameCap = 60;
public:
    /** \brief Konstruktor klase Engine.
     *
     * Vrši kreiranje glavnog prozora i renderer-a.
     *
     * \param title Naslov glavnog prozora.
     *
     */
    Engine(string title);
    /** \brief Dodaje instancu klase Tileset u Engine i pridružuje joj zadato ime.
     *
     * \param tileset Pokazivač na instancu klase Tileset.
     * \param name Ime koje treba pridružiti instanci.
     * \return void
     *
     */
    void addTileset(Tileset *tileset, const string &name);
    /** \brief Kreira instancu klase Tileset na osnovu sadržaja ulaznog toka, kreiranu instancu
     * dodaje u Engine i pridružuje joj zadato ime.
     *
     * \param inputStream Ulazni tok iz kojeg se učitavaju podaci za formiranje instance.
     * \param name Ime koje treba pridružiti instanci.
     * \return void
     *
     */
    void addTileset(istream &inputStream, const string &name);
    /** \brief Kreira instancu klase Tileset na osnovu sadržaja datoteke na datoj putanji, kreiranu instancu
     * dodaje u Engine i pridružuje joj zadato ime.
     *
     * \param path Putanja do datoteke na osnovu čijeg sadržaja se kreira instanca klase Tileset.
     * \param name Ime koje treba pridružiti instanci.
     * \return void
     *
     */
    void addTileset(const string &path, const string &name);
    /** \brief Metoda za dobavljanje instance klase Tileset na osnovu imena.
     *
     * \param name Ime Tileset instance.
     * \return Pokazivač na Tileset instancu.
     *
     */
    Tileset* getTileset(const string &name);

    /** \brief U Engine dodaje objekte koji nasleđuju klasu Drawable.
     *
     * \param drawable Objekat koji treba dodati.
     * \return void
     *
     */
    void addDrawable(Drawable* drawable);

    /** \brief Metoda u kojoj se izvršava glavna petlja video igre.
     *
     * Poziv ove metode je blokirajući.
     *
     * \return void
     *
     */
    void run();

    /** \brief Destruktor klase Engine. Oslobađa zauzete resurse window i renderer.
     *
     *
     */
    virtual ~Engine();
};

#endif // ENGINE_H_INCLUDED
