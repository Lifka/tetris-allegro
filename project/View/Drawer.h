//
// Created by lifka on 18/06/17.
//

#ifndef PROJECT_DRAWER_H
#define PROJECT_DRAWER_H

#include <stdlib.h>
#include <allegro5/allegro.h>

#include "../Controller/Observer.h"
#include "../Model/Options.h"

class Drawer : public Observer{
private:
    static Drawer* instance;

    ALLEGRO_BITMAP *buffer_bitmap = al_create_bitmap(Options::getInstance()->getScreen_height(), Options::getInstance()->getScreen_width());
    ALLEGRO_BITMAP *wall_bitmap = al_load_bitmap("sprites/wal.bmp");

    Drawer();
    Drawer& operator=(Drawer const&){};
    Drawer(Drawer const&){};
public:
    static Drawer* getInstance();
    void initBoard();
    void walls();
    void refreshBoard();
    void refreshNextPiece();
    void refreshFallingPiece();
};

#endif //PROJECT_DRAWER_H
