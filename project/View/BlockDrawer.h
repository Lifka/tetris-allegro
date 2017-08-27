//
// Created by lifka on 3/07/17.
//

#ifndef PROJECT_BLOCKDRAWER_H
#define PROJECT_BLOCKDRAWER_H


#include <allegro5/color.h>
#include "../Model/Point2D.h"
#include "../Model/Options.h"
#include "../Model/Piece.h"
#include "../Model/Direction.h"

class BlockDrawer {
private:

    static BlockDrawer* instance;
    BlockDrawer& operator=(BlockDrawer const&){};
    BlockDrawer();

public:
    static BlockDrawer* getInstance();

    // Draws a block in a screen position
    void drawBlock(Point2D position, ColorName , float size = Options::getInstance()->getBlock_size());

    // Draws a blocks line from a screen position to direction of 'size' blocks
    void drawBlocksLine(Point2D init, Direction dir, int size, ColorName , int thickness = (int)(Options::getInstance()->getBlock_size()));

    // Draws the blocks of a piece in his board position (using the method for drawing blocks in board position). Fixes the matrix offset at the first row.
    void drawBlocksPiece(Piece);

    // Draws the blocks of a piece in the screen position of next piece
    void drawBlocksNextPiece(Piece);

    // Draws a block in board coordinates
    void drawBlockInBoardPosition(std::pair<int,int> board_position, ColorName color);

};


#endif //PROJECT_BLOCKDRAWER_H
