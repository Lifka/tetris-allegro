//
// Created by lifka on 18/06/17.
//

#ifndef PROJECT_DRAWER_H
#define PROJECT_DRAWER_H

#include <stdlib.h>
#include <allegro5/allegro.h>
#include <allegro5/allegro_font.h>

#include "../Controller/Observer.h"
#include "../Model/Options.h"
#include "../Model/Piece.h"

class Drawer : public Observer{
private:
    static Drawer* instance;

    ALLEGRO_FONT *score;
    ALLEGRO_FONT *level;

    Drawer();
    Drawer& operator=(Drawer const&){};
    Drawer(Drawer const&){};
public:
    static Drawer* getInstance();

    // Draws the background of the board depending on his offset, the size of the block, the walls, etc
    void initBoard();

    // Draws the walls of the board depending on the board offset position and the walls width
    void walls();

    // Repaint the board filling the stored blocks
    void refreshBoard();

    // Repaint the next piece indicator in the screen position setted in the options (using the BlockDrawer method)
    void refreshNextPiece(Piece piece);

    void writeLevel(int i);
    void writeScore(int i);
    void writeFonts();
    void writeGameOver();
};

#endif //PROJECT_DRAWER_H
