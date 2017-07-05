//
// Created by lifka on 18/06/17.
//

#include "Options.h"
#include "ColorPalette.h"

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

Point2D &Options::getBoard_offset(){
    return board_offset;
}

void Options::setBoard_offset(const Point2D &board_offset) {
    Options::board_offset = board_offset;
}

ColorName Options::getBackground_color() {
    return background_color;
}

void Options::setBackground_color(ColorName background_color) {
    if (Options::background_color !=  ColorName::none){
        ColorPalette::getInstance()->removeSystemColor(Options::background_color);
    }
    ColorPalette::getInstance()->setSystemColor(background_color);
    Options::background_color = background_color;
}

ColorName Options::getBoard_color() {
    return board_color;
}

void Options::setBoard_color(ColorName board_color) {
    if (Options::board_color != ColorName::none){
        ColorPalette::getInstance()->removeSystemColor(Options::board_color);
    }
    ColorPalette::getInstance()->setSystemColor(board_color);
    Options::board_color = board_color;
}

ColorName Options::getWalls_color() {
    return walls_color;
}

void Options::setWalls_color(ColorName walls_color) {
    if (Options::walls_color != ColorName::none){
        ColorPalette::getInstance()->removeSystemColor(Options::walls_color);
    }
    ColorPalette::getInstance()->setSystemColor(walls_color);
    Options::walls_color = walls_color;
}

unsigned long Options::getBoardWidthInPixels() const {
    return board_blocks_width * block_size;
}

unsigned long Options::getBoardHeightInPixels() const {
    return board_blocks_height * block_size;
}

int Options::getLine_score() const {
    return line_score;
}

int Options::getScore_for_levelup() const {
    return score_for_levelup;
}
