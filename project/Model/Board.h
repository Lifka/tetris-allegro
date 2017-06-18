//
// Created by lifka on 18/06/17.
//

#ifndef PROJECT_BOARD_H
#define PROJECT_BOARD_H

#include <vector>
#include "Point2D.h"
#include "Rotation.h"
#include "Piece.h"

class Board{
private:
    std::vector<std::vector<int> > m_board;
    Piece falling_piece = NULL;
    static Board* instance;
    Board();
    Board& operator=(Board const&){};
    Board(Board const&){};
    void deleteLine(int line);
public:
    static Board* getInstance();
    bool isFree(Point2D);
    bool isPossibleMoviment(Point2D, Rotation);
    void checkLines();
    bool isGameOver();
    void initBoard(Piece);
    void setFallingPiece(Piece);
};

#endif //PROJECT_BOARD_H
