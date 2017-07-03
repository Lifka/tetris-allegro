#include <iostream>
#include "Model/Options.h"
#include "Controller/GameManager.h"
#include "View/Drawer.h"
#include "View/BlockDrawer.h"
#include <stdlib.h>
#include <allegro5/addons/primitives/allegro5/allegro_primitives.h>
#include <allegro5/addons/image/allegro5/allegro_image.h>

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

    Options::getInstance()->setBoard_blocks_height(20); // blocks
    Options::getInstance()->setBoard_blocks_width(9); // blocks

    Options::getInstance()->setWalls_width(14);

    Options::getInstance()->setBlock_size(30); // pixels block

    Options::getInstance()->setScreen_height(900); // pixels
    Options::getInstance()->setScreen_width(900); // pixels

    Options::getInstance()->setWalls_color(ALLEGRO_COLOR(al_map_rgb(255,255,255)));
    Options::getInstance()->setBoard_color(ALLEGRO_COLOR(al_map_rgb(55,55,55)));
    Options::getInstance()->setBackground_color(ALLEGRO_COLOR(al_map_rgb(4,0,90)));

    Options::getInstance()->setBoard_offset(Point2D(400,100));

    // ********* /OPTIONS


    display = al_create_display(Options::getInstance()->getScreen_width(), Options::getInstance()->getScreen_height());

    if(!display) {
        fprintf(stderr, "failed to create display!\n");
        return -1;
    }

    al_set_window_title(display, "Tetris");

    al_clear_to_color(Options::getInstance()->getBackground_color());


    al_init_primitives_addon();
    al_init_image_addon();



    ALLEGRO_COLOR electric_blue = al_map_rgb(44, 117, 255);


    GameManager::getInstance()->addObserver(Drawer::getInstance());
    GameManager::getInstance()->initGame();

    // BlockDrawer::getInstance()->drawBlock(Point2D(15,15), electric_blue);




    al_flip_display();


    al_rest(60.0);

    al_destroy_display(display);

    game_loop();



    return 0;
}
