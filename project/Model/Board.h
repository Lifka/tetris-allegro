//
// Created by lifka on 18/06/17.
//

#ifndef PROJECT_BOARD_H
#define PROJECT_BOARD_H

#include <vector>
#include <allegro5/color.h>
#include "Point2D.h"
#include "Piece.h"
#include "../Controller/Subject.h"
#include "ColorName.h"

class Board : public Subject{
private:
    std::vector<std::vector<int> > m_board;
    std::vector<std::vector<ColorName> > m_board_colors;
    Piece falling_piece;

    Board();

    static Board* instance;
    Board& operator=(Board const&){};
    Board(Board const&){};

    void deleteLine(int line);
    void fillBoard();
public:
    static Board* getInstance();
    bool isFree(Point2D);
    bool isPossibleMoviment(std::pair <int,int>, Rotation);
    bool isPossibleMovimentY(std::pair <int,int>, Rotation);
    bool isPossibleMovimentX(std::pair <int,int>, Rotation);
    void checkLines();
    bool isGameOver();
    void initBoard();
    void setFallingPiece(Piece);
    int getBoardPosition(int x, int y) const;
    ColorName getColorPosition(int x, int y) const;
    void rotateFallingPiece();
    void refreshFallingPiece();
    void moveFallingPieceToRight();
    void moveFallingPieceToLeft();
    void moveFallingPieceDown();
    void requestNewPiece();

    /**/ void debugPrintBoard();//*/
    /**/ const Piece &getFalling_piece() const;//*/
};

#endif //PROJECT_BOARD_H
