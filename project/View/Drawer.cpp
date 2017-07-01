//
// Created by lifka on 18/06/17.
//

#include "Drawer.h"
#include "../Model/Board.h"
#include "../Model/Options.h"

#define wall 1


Drawer* Drawer::instance = nullptr;

Drawer *Drawer::getInstance() {
    if (!instance){
        instance = new Drawer();
    }
    return instance;
}

void Drawer::refreshBoard() {
    for(int i = 0; i < Options::getInstance()->getBoard_blocks_height(); i++){
        for(int j = 0; j < Options::getInstance()->getBoard_blocks_width(); j++){
            if (Board::getInstance()->getBoardMatrix()[i][j] == wall){
                draw_sprite(buffer_bitmap, wall_bitmap, i*(int)Options::getInstance()->getBlock_size(), j*(int)Options::getInstance()->getBlock_size());
            }
        }

    }
}

void Observer::update(NotifyCode code){
    switch (code){
        case draw_screen:
            Drawer::getInstance()->refreshBoard();
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