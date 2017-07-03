//
// Created by lifka on 18/06/17.
//

#include "Piece.h"

Piece::Piece(std::vector<std::vector<int> > rotation0, std::vector<std::vector<int> > rotation90,
             std::vector<std::vector<int> > rotation180, std::vector<std::vector<int> > rotation270,
             Point2D initial_position, Rotation rotation, PieceType type)
        : initial_position(initial_position), rotation0(rotation0), rotation90(rotation90),
          rotation180(rotation180), rotation270(rotation270){
    this->current_rotation = rotation;
    this->type = type;
}

PieceType Piece::getPieceType() {
    return type;
}

Point2D Piece::getInitialPosition() {
    return initial_position;
}

void Piece::setRotation(Rotation rotation) {
    this->current_rotation = rotation;
}

Rotation Piece::getRotation() {
    return current_rotation;
}

std::vector <std::vector<int> > Piece::getPieceBlocks() {
    switch (current_rotation){
        case degrees0:
            return rotation0;
        case degrees90:
            return rotation90;
        case degrees180:
            return rotation180;
        case degrees270:
            return rotation270;
    }
}

Piece::Piece() {
}

Piece::Piece(const Piece &p2){
    current_rotation = p2.current_rotation;
    initial_position = p2.initial_position;
    type = p2.type;
}
