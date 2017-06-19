//
// Created by lifka on 18/06/17.
//

#ifndef PROJECT_BOARD_H
#define PROJECT_BOARD_H

#include <vector>
#include "Point2D.h"
#include "Piece.h"
#include "../Controller/Subject.h"

class Board : public Subject{
private:
    std::vector<std::vector<int> > m_board;
    Piece falling_piece;
    Board();

    static Board* instance;
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
