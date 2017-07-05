//
// Created by lifka on 18/06/17.
//

#include <iostream>
#include "Piece.h"
#include "Options.h"

Piece::Piece(std::vector<std::vector<int> > rotation0, std::vector<std::vector<int> > rotation90,
             std::vector<std::vector<int> > rotation180, std::vector<std::vector<int> > rotation270,
             std::pair <int,int> initial_position, Rotation rotation, PieceType type, ColorName color)
        : initial_position_matrix(initial_position), rotation0(rotation0), rotation90(rotation90),
          rotation180(rotation180), rotation270(rotation270){
    this->current_rotation = rotation;
    this->type = type;
    this->color = color;

    // Piece is spawned at row 0 of the board in the middle column (round to minor)
    this->initial_position_matrix.first = (int)(Options::getInstance()->getBoard_blocks_width() / 2 -2);
    this->initial_position_matrix.second = 0;

    this->current_position_matrix.first = initial_position_matrix.first;
    this->current_position_matrix.second = initial_position_matrix.second;


    /**///std::cout << "[DEBUG]: (Piece-Piece) piece created in position (" << current_position_matrix.first << "," << current_position_matrix.second << ")" << std::endl;

}

PieceType Piece::getPieceType() {
    return type;
}

std::pair <int,int> Piece::getInitialPosition() {
    return initial_position_matrix;
}

void Piece::setRotation(Rotation rotation) {
    this->current_rotation = rotation;
}

Rotation Piece::getRotation() {
    return current_rotation;
}

const std::vector<std::vector<int>> &Piece::getPieceBlocks() const{
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

Piece::Piece() {}

Piece::Piece(const Piece &p2){
    current_rotation = p2.current_rotation;
    current_position_matrix.first = p2.current_position_matrix.first;
    current_position_matrix.second = p2.current_position_matrix.second;
    initial_position_matrix.first = p2.initial_position_matrix.first;
    initial_position_matrix.second = p2.initial_position_matrix.second;


    rotation0 = p2.rotation0;
    rotation90 = p2.rotation90;
    rotation180 = p2.rotation180;
    rotation270 = p2.rotation270;


    color = p2.color;
    type = p2.type;

}

std::pair <int,int> &Piece::getCurrent_position_matrix() {
    return current_position_matrix;
}

void Piece::setCurrent_position_matrix(const std::pair <int,int> &current_position) {
    Piece::current_position_matrix.first = current_position.first;
    Piece::current_position_matrix.second = current_position.second;
}

ColorName Piece::getColor() const {
    return color;
}

void Piece::setColor(ColorName color) {
    Piece::color = color;
}

void Piece::debugMatrix() {
    /**/std::cout << "[DEBUG]: (Piece:debugMatrix) Showing piece type " << type << std::endl;
    /**/std::cout << std::endl << "-------------------------------------------" << std::endl;
    for (int i = 0; i < getPieceBlocks().size(); i++){
        for (int j = 0; j < getPieceBlocks()[i].size(); j++){
            std::cout << getPieceBlocks()[i][j] << " ";
        }
        std::cout << std::endl;
    }
    /**/std::cout << "-------------------------------------------" << std::endl << std::endl;
}

std::pair<int, int> Piece::getCenterPiece() {
    std::pair<int, int> coord;

    for (int i = 0; i < getPieceBlocks().size(); i++){
        for (int j = 0; j < getPieceBlocks()[i].size(); j++){
            if (getPieceBlocks()[j][i] == 2) {
                coord.first = j;
                coord.second = i;
            }
        }
    }

    return coord;
};
