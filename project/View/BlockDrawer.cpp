//
// Created by lifka on 3/07/17.
//

#include <allegro5/allegro_primitives.h>
#include <iostream>
#include "BlockDrawer.h"
#include "../Model/ColorPalette.h"

BlockDrawer* BlockDrawer::instance = nullptr;

BlockDrawer::BlockDrawer() {

}

BlockDrawer *BlockDrawer::getInstance() {
    if (!instance){
        instance = new BlockDrawer();
    }
    return instance;
}

void BlockDrawer::drawBlock(Point2D position, ColorName color, float size) {
    al_draw_line(position.getX() - size/2,
                 position.getY(),
                 position.getX() + size/2,
                 position.getY(),
                 ColorPalette::getInstance()->getColor(color),
                 size);
    /*std::cout << "[DEBUG]: (BlockDrawer-drawBlock) drawed block --> size=" << size << " Point(" << position.getX() << "," << position.getY() << ")" << std::endl;//*/
}

void BlockDrawer::drawBlocksLine(Point2D init, Direction dir, int size, ColorName color, int thickness) {
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

void BlockDrawer::drawBlockInBoardPosition(std::pair<int,int> board_position, ColorName color){
    /*std::cout << "[DEBUG]: (BlockDrawer-drawBlockInBoardPosition) drawing block --> (" << board_position.first << "," << board_position.second << ") - Color: " << color << std::endl;//*/

    int screen_position_x = (int)(Options::getInstance()->getBoard_offset().getX() + Options::getInstance()->getBlock_size()/2 + Options::getInstance()->getWalls_width());
    int screen_position_y = (int)(Options::getInstance()->getBoard_offset().getY() + Options::getInstance()->getBlock_size()/2 + Options::getInstance()->getWalls_width());

    screen_position_x += Options::getInstance()->getBlock_size() * (board_position.first );
    screen_position_y += Options::getInstance()->getBlock_size() * (board_position.second );

    Point2D block_screen_position = Point2D(screen_position_x, screen_position_y);
    drawBlock(block_screen_position, color);

}

void BlockDrawer::drawBlocksPiece(Piece piece) {
    /**/std::cout << "[DEBUG]: (BlockDrawer-drawBlocksPiece) drawing piece in position --> (" << piece.getCurrent_position_matrix().first << "," << piece.getCurrent_position_matrix().second << ") - With rotation ->" << piece.getRotation() << std::endl;//*/
    /**piece.debugMatrix();//*/
   // int count_y = 0;

    bool piece_paint = false;

    for (int y = 0; y < piece.getPieceBlocks().size(); y++){
        for (int x = 0; x < piece.getPieceBlocks()[y].size(); x++){

            if (piece.getPieceBlocks()[y][x] == 1 || piece.getPieceBlocks()[y][x] == 2) {


                drawBlockInBoardPosition(
                        std::make_pair(piece.getCurrent_position_matrix().first + x,
                                       piece.getCurrent_position_matrix().second + /**/y/**//*count_y*/),
                        piece.getColor());

                piece_paint = true;
            }
        }

        if (piece_paint){
            //count_y++;
            piece_paint = false;
        }
    }

}

void BlockDrawer::drawBlocksNextPiece(Piece piece) {

    Point2D offset = Options::getInstance()->getNext_piece_offset_position_screen();

    int position_x = offset.getX();
    int position_y = offset.getY();

    int size_block = Options::getInstance()->getBlock_size();

    for (int y = 0; y < piece.getPieceBlocks().size(); y++) {
        for (int x = 0; x < piece.getPieceBlocks()[y].size(); x++) {
            Point2D position = Point2D(position_x + x * size_block,
                                       position_y + y * size_block);

            if (piece.getPieceBlocks()[y][x] == 1 || piece.getPieceBlocks()[y][x] == 2) {
                drawBlock(position, piece.getColor());
            } else {
                drawBlock(position, Options::getInstance()->getBackground_color());
            }
        }
    }
}

