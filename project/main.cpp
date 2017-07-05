#include <iostream>
#include "Model/Options.h"
#include "Model/ColorPalette.h"
#include "Controller/GameManager.h"
#include "Model/Board.h"
#include "View/Drawer.h"
#include <stdlib.h>
#include <allegro5/addons/primitives/allegro5/allegro_primitives.h>
#include <allegro5/addons/image/allegro5/allegro_image.h>
#include <allegro5/allegro_font.h>
#include <allegro5/allegro_ttf.h>

void updateGame(){

}

void displayGame(){

}

void game_loop() {

    bool game_is_running = true;

    while(game_is_running){
        updateGame();
        displayGame();
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
    Options::getInstance()->setBoard_blocks_width(11); // blocks

    Options::getInstance()->setWalls_width(14);

    Options::getInstance()->setBlock_size(46); // pixels block

    Options::getInstance()->setScreen_height(945); // pixels
    Options::getInstance()->setScreen_width(900); // pixels

    Options::getInstance()->setWalls_color(ColorName::purple);
    Options::getInstance()->setBoard_color(ColorName::indigo);
    Options::getInstance()->setBackground_color(ColorName::black);
    Options::getInstance()->setTextColor(ColorName::white);

    Options::getInstance()->setFont_size(20);
    Options::getInstance()->setFont((char *) "../fonts/pirulen.ttf");

    Options::getInstance()->setBoard_offset(Point2D(0,0));
    Options::getInstance()->setNext_piece_offset_position_screen(Point2D(650,100));
    Options::getInstance()->setLevel_offset_position_screen(Point2D(650,500));
    Options::getInstance()->setScore_offset_position_screen(Point2D(650,700));

    // ********* /OPTIONS


    display = al_create_display(Options::getInstance()->getScreen_width(), Options::getInstance()->getScreen_height());

    if(!display) {
        fprintf(stderr, "failed to create display!\n");
        return -1;
    }

    al_set_window_title(display, "Tetris");

    al_clear_to_color(ColorPalette::getInstance()->getColor(Options::getInstance()->getBackground_color()));


    al_init_primitives_addon();
    al_init_image_addon();

    al_init_font_addon();
    al_init_ttf_addon();




    GameManager::getInstance()->addObserver(Drawer::getInstance());
    Board::getInstance()->addObserver(GameManager::getInstance());
    Board::getInstance()->addObserver(Drawer::getInstance());

    GameManager::getInstance()->initGame();

    game_loop();


    al_flip_display();


    al_rest(60.0);

    al_destroy_display(display);




    return 0;
}
