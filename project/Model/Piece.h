//
// Created by lifka on 18/06/17.
//

#ifndef PROJECT_PIECE_H
#define PROJECT_PIECE_H

#include <vector>
#include "Rotation.h"
#include "Point2D.h"
#include "PieceType.h"

class Piece {
private:
    std::vector <std::vector<int> > rotation0;
    std::vector <std::vector<int> > rotation90;
    std::vector <std::vector<int> > rotation180;
    std::vector <std::vector<int> > rotation270;
    Rotation current_rotation;
    Point2D initial_position;
    PieceType type;
public:
    Piece(std::vector<std::vector<int> >, std::vector<std::vector<int> >, std::vector<std::vector<int> >,
              std::vector<std::vector<int> >, Point2D, Rotation, PieceType);
    Point2D getInitialPosition();
    PieceType getPieceType();
    void setRotation(Rotation rotation);
    Rotation getRotation();
    std::vector <std::vector<int> > getPieceBlocks();

};


#endif //PROJECT_PIECE_H
