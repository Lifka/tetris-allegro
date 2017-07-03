//
// Created by lifka on 3/07/17.
//

#include <allegro5/addons/primitives/allegro5/allegro_primitives.h>
#include <iostream>
#include "BlockDrawer.h"
#include "../Model/direction.h"

BlockDrawer* BlockDrawer::instance = nullptr;

BlockDrawer::BlockDrawer() {

}

BlockDrawer *BlockDrawer::getInstance() {
    if (!instance){
        instance = new BlockDrawer();
    }
    return instance;
}

void BlockDrawer::drawBlock(Point2D position, ALLEGRO_COLOR color, float size) {
    al_draw_line(position.getX() - size/2,
                 position.getY(),
                 position.getX() + size/2,
                 position.getY(),
                 color,
                 size);
    /**/std::cout << "[DEBUG]: (BlockDrawer-drawBlock) drwaed block --> size=" << size << " Point(" << position.getX() << "," << position.getY() << ")" << std::endl;
}

void BlockDrawer::drawBlocksLine(Point2D init, Direction dir, int size, ALLEGRO_COLOR color, float thickness) {
    Point2D point = init;

    switch (dir){
        case Direction ::right:
            for (int i = 0; i < size; i++){
                drawBlock(point, color, thickness);
                point.setX(point.getX()+thickness);
            }
            break;
        case Direction ::left:
            for (int i = 0; i < size; i++){
                drawBlock(point, color, thickness);
                point.setX(point.getX()-thickness);
            }
            break;
        case Direction ::up:
            for (int i = 0; i < size; i++){
                drawBlock(point, color, thickness);
                point.setY(point.getY()+thickness);
            }
            break;
        case Direction ::down:
            for (int i = 0; i < size; i++){
                drawBlock(point, color, thickness);
                point.setY(point.getY()-thickness);
            }
            break;
    }
}

void BlockDrawer::drawBlocksPiece(Piece, ALLEGRO_COLOR) {

}

