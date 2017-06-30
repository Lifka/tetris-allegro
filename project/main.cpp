#include <iostream>
#include "Model/Piece.h"
#include "Model/Point2D.h"
#include "Controller/GameManager.h"
#include "Model/Options.h"
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

    display = al_create_display(640, 480);
    if(!display) {
        fprintf(stderr, "failed to create display!\n");
        return -1;
    }

    al_clear_to_color(al_map_rgb(0,0,0));

    al_flip_display();

    al_rest(10.0);

    al_destroy_display(display);

    Options::getInstance()->setBoard_blocks_height(200);
    Options::getInstance()->setBoard_blocks_width(200);
    Options::getInstance()->setWalls_width(10);
    Options::getInstance()->setGame_width(150);
    GameManager::getInstance()->initGame();
    game_loop();

    return 0;
}
