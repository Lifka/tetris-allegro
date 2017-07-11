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

int Options::getWalls_width() const {
    return walls_width;
}

void Options::setWalls_width(int walls_width) {
    Options::walls_width = walls_width;
}

int Options::getBlock_size() const {
    return block_size;
}

void Options::setBlock_size(int block_size) {
    Options::block_size = block_size;
}

int Options::getBoard_blocks_width() const {
    return board_blocks_width;
}

void Options::setBoard_blocks_width(int board_blocks_width) {
    Options::board_blocks_width = board_blocks_width;
}

int Options::getBoard_blocks_height() const {
    return board_blocks_height;
}

void Options::setBoard_blocks_height(int board_blocks_height) {
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


ColorName Options::getTextColor(){
    return text_color;
}

void Options::setTextColor(ColorName text_color) {
    if (Options::text_color != ColorName::none){
        ColorPalette::getInstance()->removeSystemColor(Options::text_color);
    }
    ColorPalette::getInstance()->setSystemColor(text_color);
    Options::text_color = text_color;
}

int Options::getBoardWidthInPixels() const {
    return board_blocks_width * block_size;
}

int Options::getBoardHeightInPixels() const {
    return board_blocks_height * block_size;
}

int Options::getLine_score() const {
    return line_score;
}

int Options::getScore_for_levelup() const {
    return score_for_levelup;
}

int Options::getPieceScore() const {
    return piece_score;
}

const Point2D &Options::getNext_piece_offset_position_screen() const {
    return next_piece_offset_position_screen;
}

void Options::setNext_piece_offset_position_screen(const Point2D &next_piece_position_screen) {
    Options::next_piece_offset_position_screen = next_piece_position_screen;
}

const Point2D &Options::getScore_offset_position_screen() const {
    return score_offset_position_screen;
}

void Options::setScore_offset_position_screen(const Point2D &score_offset_position_screen) {
    Options::score_offset_position_screen = score_offset_position_screen;
}

const Point2D &Options::getLevel_offset_position_screen() const {
    return level_offset_position_screen;
}

void Options::setLevel_offset_position_screen(const Point2D &level_offset_position_screen) {
    Options::level_offset_position_screen = level_offset_position_screen;
}

int Options::getFont_size() const {
    return font_size;
}

void Options::setFont_size(int font_size) {
    Options::font_size = font_size;
}

char *Options::getFont() const {
    return font;
}

void Options::setFont(char *font) {
    Options::font = font;
}

int Options::getFont_game_over_size() const {
    return font_game_over_size;
}

void Options::setFont_game_over_size(int font__game_over_size) {
    Options::font_game_over_size = font__game_over_size;
}

ColorName Options::getgameOverColor() {
    return text_game_over_color;
}

void Options::setgameOverColor(ColorName color) {
    if (Options::text_game_over_color != ColorName::none){
        ColorPalette::getInstance()->removeSystemColor(Options::text_game_over_color);
    }
    ColorPalette::getInstance()->setSystemColor(color);
    Options::text_game_over_color = color;
}

const Point2D &Options::getGameOver_offset_position_screen() const {
    return Options::game_over_offset_position_screen;
}

void Options::setGameOver_offset_position_screen(const Point2D &GameOver_position_screen) {
    Options::game_over_offset_position_screen = GameOver_position_screen;
}

int Options::getFont_press_to_restart_size() const {
    return font_press_to_restart_size;
}

void Options::setFont_press_to_restart_size(int font_press_to_restart_size) {
    Options::font_press_to_restart_size = font_press_to_restart_size;
}

const Point2D &Options::getPressToRestartOffsetPositionScreen() const {
    return press_to_restart_offset_position_screen;
}

void Options::setPressToRestartOffsetPositionScreen(const Point2D &game_over_offset_position_screen) {
    Options::press_to_restart_offset_position_screen = game_over_offset_position_screen;
}

void Options::setFallingTimeFactorScale(const double& n) {
    fallingTimeFactorScale = n;
}

const double &Options::getFallingTimeFactorScale() const {
    return fallingTimeFactorScale;
}
