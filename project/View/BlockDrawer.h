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
    void drawBlock(Point2D position, ColorName , float size = Options::getInstance()->getBlock_size());
    void drawBlocksLine(Point2D init, Direction dir, int size, ColorName , float thickness = Options::getInstance()->getBlock_size());
    void drawBlocksPiece(Piece);

    void drawBlockInBoardPosition(std::pair<int,int> board_position, ColorName color);
};


#endif //PROJECT_BLOCKDRAWER_H
