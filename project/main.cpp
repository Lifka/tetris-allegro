#include <iostream>
#include "Model/Piece.h"
#include "Model/Point2D.h"
#include "Controller/GameManager.h"
#include "Model/Options.h"
#include "View/Drawer.h"
#include <stdio.h>
#include <stdlib.h>
#include <allegro5/allegro.h>

void game_loop() {

    while(true){

    }
}

int main(int argc, char **argv)  {


    ALLEGRO_DISPLAY *display = NULL;

    if(!al_init()) {
        fprintf(stderr, "failed to initialize allegro!\n");
        return -1;
    }

    // ********* OPTIONS

    Options::getInstance()->setBoard_blocks_height(30);
    Options::getInstance()->setBoard_blocks_width(19);
    Options::getInstance()->setGame_width(11);

    Options::getInstance()->setWalls_width(1);

    Options::getInstance()->setBlock_size(30);
    Options::getInstance()->setScreen_height(900);
    Options::getInstance()->setScreen_width(570);

    // ********* /OPTIONS



    display = al_create_display(Options::getInstance()->getScreen_height(), Options::getInstance()->getScreen_width());
    if(!display) {
        fprintf(stderr, "failed to create display!\n");
        return -1;
    }

    al_clear_to_color(al_map_rgb(0,0,0));

    al_flip_display();

    al_rest(10.0);

    al_destroy_display(display);


    GameManager::getInstance()->addObserver(Drawer::getInstance());
    GameManager::getInstance()->initGame();

    game_loop();

    return 0;
}
