//
// Created by lifka on 18/06/17.
//

#include <iostream>
#include <allegro5/addons/primitives/allegro5/allegro_primitives.h>
#include "Drawer.h"
#include "../Model/Board.h"
#include "../Model/Options.h"
#include "BlockDrawer.h"

#define wall 1


Drawer* Drawer::instance = nullptr;

Drawer *Drawer::getInstance() {
    if (!instance){
        instance = new Drawer();
    }
    return instance;
}

void Drawer::refreshBoard() {

}

void Drawer::initBoard() {
    ALLEGRO_COLOR color = Options::getInstance()->getBoard_color();

    /**/std::cout << "[DEBUG]: (Drawer:initBoard) initBoard..." << std::endl;

    float x_init = Options::getInstance()->getBoard_offset().getX() + Options::getInstance()->getBlock_size()/2 + Options::getInstance()->getWalls_width();

    Point2D init_point = Point2D(x_init,
                                 Options::getInstance()->getBoard_offset().getY() + Options::getInstance()->getBlock_size()/2 + Options::getInstance()->getWalls_width());

    for(int i = 0; i < Options::getInstance()->getBoard_blocks_height(); i++){
        for(int j = 0; j < Options::getInstance()->getBoard_blocks_width(); j++){
            BlockDrawer::getInstance()->drawBlock(init_point, color);
            init_point.setX(init_point.getX() + Options::getInstance()->getBlock_size());
        }
        init_point.setY(init_point.getY() + Options::getInstance()->getBlock_size());
        init_point.setX(x_init);
    }
}

void Drawer::walls() {
    ALLEGRO_COLOR color = Options::getInstance()->getWalls_color();

    // Up
    Point2D init_point = Point2D(Options::getInstance()->getBoard_offset().getX(),Options::getInstance()->getBoard_offset().getY() + Options::getInstance()->getWalls_width()/2);
    float size = Options::getInstance()->getBoardWidthInPixels() + Options::getInstance()->getWalls_width()/2;
    Point2D final_point = Point2D(Options::getInstance()->getBoard_offset().getX() + size + Options::getInstance()->getWalls_width(), Options::getInstance()->getBoard_offset().getY() + Options::getInstance()->getWalls_width()/2);

    al_draw_line(init_point.getX(), init_point.getY(), final_point.getX(), final_point.getY(), color, Options::getInstance()->getWalls_width());

    // Down
    init_point = Point2D(Options::getInstance()->getBoard_offset().getX(),Options::getInstance()->getBoard_offset().getY() + Options::getInstance()->getWalls_width()/2 + Options::getInstance()->getBoardHeightInPixels() + Options::getInstance()->getWalls_width());
    size = Options::getInstance()->getBoardWidthInPixels() + Options::getInstance()->getWalls_width()/2;
    final_point = Point2D(Options::getInstance()->getBoard_offset().getX() + size + Options::getInstance()->getWalls_width(),Options::getInstance()->getBoard_offset().getY() + Options::getInstance()->getWalls_width()/2 + Options::getInstance()->getBoardHeightInPixels() + Options::getInstance()->getWalls_width());

    al_draw_line(init_point.getX(), init_point.getY(), final_point.getX(), final_point.getY(), color, Options::getInstance()->getWalls_width());

    // Left
    init_point = Point2D(Options::getInstance()->getBoard_offset().getX() + Options::getInstance()->getWalls_width()/2,Options::getInstance()->getBoard_offset().getY());
    size = Options::getInstance()->getBoardHeightInPixels() + Options::getInstance()->getWalls_width();
    final_point = Point2D(Options::getInstance()->getBoard_offset().getX() + Options::getInstance()->getWalls_width()/2,Options::getInstance()->getBoard_offset().getY() + size + Options::getInstance()->getWalls_width());

    al_draw_line(init_point.getX(), init_point.getY(), final_point.getX(), final_point.getY(), color, Options::getInstance()->getWalls_width());

    // Right
    init_point = Point2D(Options::getInstance()->getBoard_offset().getX() + Options::getInstance()->getBoardWidthInPixels() + Options::getInstance()->getWalls_width() + Options::getInstance()->getWalls_width()/2,Options::getInstance()->getBoard_offset().getY());
    size = Options::getInstance()->getBoardHeightInPixels() + Options::getInstance()->getWalls_width();
    final_point = Point2D(Options::getInstance()->getBoard_offset().getX() + Options::getInstance()->getBoardWidthInPixels() + Options::getInstance()->getWalls_width() + Options::getInstance()->getWalls_width()/2,Options::getInstance()->getBoard_offset().getY() + size + Options::getInstance()->getWalls_width());

    al_draw_line(init_point.getX(), init_point.getY(), final_point.getX(), final_point.getY(), color, Options::getInstance()->getWalls_width());

}

void Observer::update(NotifyCode code){
    /**/std::cout << "[DEBUG]: (Drawer-update) notify recieved with code --> " << code << std::endl;
    switch (code){
        case draw_screen:
            Drawer::getInstance()->walls();
            Drawer::getInstance()->initBoard();
            break;
    }
}

void Drawer::refreshNextPiece() {
    //TODO
}

void Drawer::refreshFallingPiece() {
    //TODO
}

Drawer::Drawer() {

}