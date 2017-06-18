//
// Created by lifka on 18/06/17.
//

#include "Options.h"

Options* Options::getInstance() {
    if (!instance)
        instance = new Options();
    return instance;
}

unsigned long Options::getWalls_width() const {
    return walls_width;
}

void Options::setWalls_width(int walls_width) {
    Options::walls_width = walls_width;
}

unsigned long Options::getBlock_size() const {
    return block_size;
}

void Options::setBlock_size(int block_size) {
    Options::block_size = block_size;
}

unsigned long Options::getBoard_blocks_width() const {
    return board_blocks_width;
}

void Options::setBoard_blocks_width(int board_blocks_width) {
    Options::board_blocks_width = board_blocks_width;
}

unsigned long Options::getBoard_blocks_height() const {
    return board_blocks_height;
}

void Options::setBoard_blocks_height(int board_blocks_height) {
    Options::board_blocks_height = board_blocks_height;
}
