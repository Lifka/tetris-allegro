//
// Created by lifka on 18/06/17.
//

#ifndef PROJECT_PIECE_H
#define PROJECT_PIECE_H

#include <vector>
#include <allegro5/color.h>
#include "Rotation.h"
#include "PieceType.h"
#include "ColorName.h"

class Piece {
private:
    std::vector <std::vector<int> > rotation0;
    std::vector <std::vector<int> > rotation90;
    std::vector <std::vector<int> > rotation180;
    std::vector <std::vector<int> > rotation270;
    std::pair <int,int> initial_position_rotation0;
    std::pair <int,int> initial_position_rotation90;
    std::pair <int,int> initial_position_rotation180;
    std::pair <int,int> initial_position_rotation270;

    Rotation current_rotation;
    std::pair <int,int> current_position_matrix;
    PieceType type;
    ColorName color;

    void calculateInitialPositions();

public:
    Piece();
    Piece(const Piece &p2);

    // Creates a piece with a matrix map for each rotation. Also, initialices the spawn position at the middle of the first row
    Piece(std::vector<std::vector<int> >, std::vector<std::vector<int> >, std::vector<std::vector<int> >,
              std::vector<std::vector<int> >, Rotation, PieceType, ColorName);

    std::pair <int,int> getInitialPosition();
    PieceType getPieceType();
    void setRotation(Rotation rotation);
    Rotation getRotation();
    std::vector <std::vector<int> > getRotation(Rotation rotation);

    // Returns the map matrix of the current rotation of the piece
    std::vector<std::vector<int>> &getPieceBlocks();

    // Returns the board position of the piece in board coordinates ( x,y integers)
    std::pair <int,int> &getCurrent_position_matrix();

    void setCurrent_position_matrix(const std::pair <int,int> &current_position);
    ColorName getColor() const;
    void setColor(ColorName color);

    // Returns the center pivot of the piece in his current rotation
    std::pair <int,int> getCenterPiece();

    /**/void debugMatrix();

    Rotation nextRotationRight();
    void rotateRight();
    std::pair <int,int> nextPositionRight();
    void moveToRight();
    std::pair <int,int> nextPositionLeft();
    void moveToLeft();
    std::pair <int,int> nextPositionDown();
    void fall();

    int getSizeX();
    int getSizeY();
};


#endif //PROJECT_PIECE_H
