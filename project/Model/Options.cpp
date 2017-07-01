//
// Created by lifka on 18/06/17.
//

#include "Options.h"

Options* Options::instance = nullptr;

Options* Options::getInstance() {
    if (!instance)
        instance = new Options();
    return instance;
}

unsigned long Options::getWalls_width() const {
    return walls_width;
}

void Options::setWalls_width(unsigned long walls_width) {
    Options::walls_width = walls_width;
}

unsigned long Options::getBlock_size() const {
    return block_size;
}

void Options::setBlock_size(unsigned long block_size) {
    Options::block_size = block_size;
}

unsigned long Options::getBoard_blocks_width() const {
    return board_blocks_width;
}

void Options::setBoard_blocks_width(unsigned long board_blocks_width) {
    Options::board_blocks_width = board_blocks_width;
}

unsigned long Options::getBoard_blocks_height() const {
    return board_blocks_height;
}

void Options::setBoard_blocks_height(unsigned long board_blocks_height) {
    Options::board_blocks_height = board_blocks_height;
}

unsigned long Options::getGame_width() const{
    return game_width;
}

void Options::setGame_width(unsigned long game_width){
    Options::game_width = game_width;
}

int Options::getScreen_width() const{
    return screen_width;
}

void Options::setScreen_width(int screen_width){
    Options::screen_width = screen_width;
}


int Options::getScreen_height() const{
    return screen_height;
}

void Options::setScreen_height(int screen_height){
    Options::screen_height = screen_height;
}


Options::Options() {
}
