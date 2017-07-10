//
// Created by lifka on 18/06/17.
//

#include <iostream>
#include <allegro5/allegro_primitives.h>
#include "Drawer.h"
#include "../Model/Board.h"
#include "../Model/Strings.h"
#include "BlockDrawer.h"
#include "../Model/ColorPalette.h"
#include <allegro5/allegro_font.h>
#include <allegro5/allegro_ttf.h>

#define block 1


Drawer* Drawer::instance = nullptr;

Drawer *Drawer::getInstance() {
    if (!instance){
        instance = new Drawer();
    }
    return instance;
}

void Drawer::refreshBoard() {

    /**/std::cout << "[DEBUG]: (Drawer:refreshBoard) refreshing..." << std::endl;//*/

    Board::getInstance()->debugPrintBoard();


    for (int i = 0; i < Options::getInstance()->getBoard_blocks_height(); i++){
        for (int j= 0; j < Options::getInstance()->getBoard_blocks_width(); j++){

            if (Board::getInstance()->getBoardPosition(i,j) == 1 || Board::getInstance()->getBoardPosition(i,j) == 2) {


                BlockDrawer::getInstance()->drawBlockInBoardPosition(
                        std::make_pair(j,
                                       i),
                        Board::getInstance()->getColorPosition(i, j));
;
            } else {

                BlockDrawer::getInstance()->drawBlockInBoardPosition(
                        std::make_pair(j,
                                       i),
                        Options::getInstance()->getBoard_color());
            }
        }

    }

}

void Drawer::initBoard() {

    /**/std::cout << "[DEBUG]: (Drawer:initBoard) initBoard..." << std::endl;//*/

    int x_init = Options::getInstance()->getBoard_offset().getX() + Options::getInstance()->getBlock_size()/2 + Options::getInstance()->getWalls_width();
    int y_init = Options::getInstance()->getBoard_offset().getY() + Options::getInstance()->getBlock_size()/2 + Options::getInstance()->getWalls_width();

    Point2D init_point = Point2D(x_init, y_init);

    for(int i = 0; i < Options::getInstance()->getBoard_blocks_height(); i++){
        for(int j = 0; j < Options::getInstance()->getBoard_blocks_width(); j++){
            BlockDrawer::getInstance()->drawBlock(init_point, Options::getInstance()->getBoard_color());
            init_point.setX(init_point.getX() + Options::getInstance()->getBlock_size());
        }
        init_point.setY(init_point.getY() + Options::getInstance()->getBlock_size());
        init_point.setX(x_init);
    }
    writeFonts();
}

void Drawer::walls() {
    ALLEGRO_COLOR color = ColorPalette::getInstance()->getColor(Options::getInstance()->getWalls_color());

    // Up
    Point2D init_point = Point2D(Options::getInstance()->getBoard_offset().getX(),Options::getInstance()->getBoard_offset().getY() + Options::getInstance()->getWalls_width()/2);
    int size = Options::getInstance()->getBoardWidthInPixels() + Options::getInstance()->getWalls_width()/2;
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

void Observer::update(NotifyCode code,  Piece piece){
    /**/std::cout << "[DEBUG]: (Drawer-update) notify recieved with code --> " << code; //*/
    /**/std::cout << " with piece in position (" << piece.getCurrent_position_matrix().first << "," << piece.getCurrent_position_matrix().second << ")" << std::endl;
    switch (code){
        case falling_piece_changed:
            /*piece.debugMatrix();//*/
            BlockDrawer::getInstance()->drawBlocksPiece(piece);
            break;
        case next_piece:
            Drawer::getInstance()->refreshNextPiece(piece);
            break;

    }
}

void Observer::update(NotifyCode code,  int n){
    /**/std::cout << "[DEBUG]: (Drawer-update) notify recieved with code --> " << code << std::endl;//*/
   switch (code){
        case draw_scoreup:
            Drawer::getInstance()->writeScore(n);
            break;
        case draw_levelup:
            Drawer::getInstance()->writeLevel(n);
            break;

    }
}

void Drawer::refreshNextPiece(Piece piece) {
    BlockDrawer::getInstance()->drawBlocksNextPiece(piece);
}


Drawer::Drawer() {

    score = al_load_ttf_font(Options::getInstance()->getFont(),
                             Options::getInstance()->getFont_size(),0 );


    level = al_load_ttf_font(Options::getInstance()->getFont(),
                             Options::getInstance()->getFont_size(),0 );
}

void Drawer::writeFonts() {

    ALLEGRO_FONT *font = al_load_ttf_font(Options::getInstance()->getFont(),
                                          Options::getInstance()->getFont_size(),0 );

    Point2D offset_next_piece = Options::getInstance()->getNext_piece_offset_position_screen();
    int adjust_y = 50;

    al_draw_text(font,
            ColorPalette::getInstance()->getColor(Options::getInstance()->getTextColor()),
                 offset_next_piece.getX(),
                 offset_next_piece.getY()-adjust_y,
                 ALLEGRO_ALIGN_LEFT,
                 Strings::getInstance()->getNext_piece());


    Point2D offset_level = Options::getInstance()->getLevel_offset_position_screen();

    al_draw_text(font,
                 ColorPalette::getInstance()->getColor(Options::getInstance()->getTextColor()),
                 offset_level.getX(),
                 offset_level.getY()-adjust_y,
                 ALLEGRO_ALIGN_LEFT,
                 Strings::getInstance()->getLevel());


    Point2D offset_score = Options::getInstance()->getScore_offset_position_screen();

    al_draw_text(font,
                 ColorPalette::getInstance()->getColor(Options::getInstance()->getTextColor()),
                 offset_score.getX(),
                 offset_score.getY()-adjust_y,
                 ALLEGRO_ALIGN_LEFT,
                 Strings::getInstance()->getScore());
}

void Drawer::writeScore(int i) {

    char str[10];
    sprintf(str, "%d", i);


    Point2D offset_score = Options::getInstance()->getScore_offset_position_screen();

    al_draw_text(score,
                 ColorPalette::getInstance()->getColor(Options::getInstance()->getTextColor()),
                 offset_score.getX(),
                 offset_score.getY(),
                 ALLEGRO_ALIGN_LEFT,
                 str);
}

void Drawer::writeLevel(int i) {

    char str[10];
    sprintf(str, "%d", i);


    Point2D offset_level = Options::getInstance()->getLevel_offset_position_screen();

    al_draw_text(level,
                 ColorPalette::getInstance()->getColor(Options::getInstance()->getTextColor()),
                 offset_level.getX(),
                 offset_level.getY(),
                 ALLEGRO_ALIGN_LEFT,
                 str);
}

void Drawer::writeGameOver() {

    ALLEGRO_FONT *font = al_load_ttf_font(Options::getInstance()->getFont(),
                                          Options::getInstance()->getFont_game_over_size(),0 );

    Point2D offset_game_over = Options::getInstance()->getGameOver_offset_position_screen();

    al_draw_text(font,
                 ColorPalette::getInstance()->getColor(Options::getInstance()->getgameOverColor()),
                 offset_game_over.getX(),
                 offset_game_over.getY(),
                 ALLEGRO_ALIGN_CENTRE,
                 Strings::getInstance()->getGameOver());

    // -------------------

    ALLEGRO_FONT *font_2 = al_load_ttf_font(Options::getInstance()->getFont(),
                                          Options::getInstance()->getFont_press_to_restart_size(),0 );

    Point2D offset_press_to_restart = Options::getInstance()->getPressToRestartOffsetPositionScreen();

    al_draw_text(font_2,
                 ColorPalette::getInstance()->getColor(Options::getInstance()->getgameOverColor()),
                 offset_press_to_restart.getX(),
                 offset_press_to_restart.getY(),
                 ALLEGRO_ALIGN_CENTRE,
                 Strings::getInstance()->getPressToRestart());

}


