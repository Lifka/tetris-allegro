//
// Created by lifka on 18/06/17.
//

#ifndef PROJECT_DRAWER_H
#define PROJECT_DRAWER_H

#include <allegro5/allegro.h>
#include <allegro/gfx.h>
#include <allegro.h>
#include "../Controller/Observer.h"
#include "../Model/Options.h"

class Drawer : public Observer{
private:
    static Drawer* instance;

    BITMAP *buffer_bitmap = create_bitmap(Options::getInstance()->getScreen_height(), Options::getInstance()->getScreen_width());
    BITMAP *wall_bitmap = load_bitmap((char*)"sprites/wall.bmp",NULL);

    Drawer();
    Drawer& operator=(Drawer const&){};
    Drawer(Drawer const&){};
public:
    static Drawer* getInstance();
    void refreshBoard();
    void refreshNextPiece();
    void refreshFallingPiece();
};

#endif //PROJECT_DRAWER_H
