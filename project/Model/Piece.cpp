//
// Created by lifka on 18/06/17.
//

#include <iostream>
#include "Piece.h"
#include "Options.h"

Piece::Piece(std::vector<std::vector<int> > rotation0, std::vector<std::vector<int> > rotation90,
             std::vector<std::vector<int> > rotation180, std::vector<std::vector<int> > rotation270,
             Rotation rotation, PieceType type, ColorName color)
        : rotation0(rotation0), rotation90(rotation90),
          rotation180(rotation180), rotation270(rotation270){
    this->current_rotation = rotation;
    this->type = type;
    this->color = color;

    calculateInitialPositions();

    this->current_position_matrix.first = getInitialPosition().first;
    this->current_position_matrix.second = getInitialPosition().second;


    /**///std::cout << "[DEBUG]: (Piece-Piece) piece created in position (" << current_position_matrix.first << "," << current_position_matrix.second << ")" << std::endl;

}

PieceType Piece::getPieceType() {
    return type;
}

std::pair <int,int> Piece::getInitialPosition() {
    switch (current_rotation){
        case degrees0:
            return initial_position_rotation0;
        case degrees90:
            return initial_position_rotation90;
        case degrees180:
            return initial_position_rotation180;
        case degrees270:
            return initial_position_rotation270;
    }
}

void Piece::setRotation(Rotation rotation) {
    this->current_rotation = rotation;
}

Rotation Piece::getRotation() {
    return current_rotation;
}

std::vector<std::vector<int>> &Piece::getPieceBlocks(){
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

    initial_position_rotation0.first = p2.initial_position_rotation0.first;
    initial_position_rotation0.second = p2.initial_position_rotation0.second;

    initial_position_rotation90.first = p2.initial_position_rotation90.first;
    initial_position_rotation90.second = p2.initial_position_rotation90.second;

    initial_position_rotation180.first = p2.initial_position_rotation180.first;
    initial_position_rotation180.second = p2.initial_position_rotation180.second;

    initial_position_rotation270.first = p2.initial_position_rotation270.first;
    initial_position_rotation270.second = p2.initial_position_rotation270.second;


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
}

void Piece::rotateRight() {
    setRotation(nextRotationRight());
}

void Piece::moveToRight() {
    current_position_matrix.first = nextPositionRight().first;
    current_position_matrix.second = nextPositionRight().second;
}

void Piece::moveToLeft() {
    current_position_matrix.first = nextPositionLeft().first;
    current_position_matrix.second = nextPositionLeft().second;
}

void Piece::fall() {
    current_position_matrix.first = nextPositionDown().first;
    current_position_matrix.second = nextPositionDown().second;
}

Rotation Piece::nextRotationRight() {
    Rotation next_rotation = degrees0;

    switch (getRotation()){
        case degrees0:
            next_rotation = (degrees90);
            break;
        case degrees90:
            next_rotation = (degrees180);
            break;
        case degrees180:
            next_rotation = (degrees270);
            break;
        case degrees270:
            next_rotation = (degrees0);
            break;
    }

    return next_rotation;

}

std::pair<int, int> Piece::nextPositionRight() {
    std::pair <int,int> next_position;
    next_position.first = getCurrent_position_matrix().first;
    next_position.second = getCurrent_position_matrix().second;

    next_position.first++;

    return next_position;
}

std::pair<int, int> Piece::nextPositionLeft() {
    std::pair <int,int> next_position;
    next_position.first = getCurrent_position_matrix().first;
    next_position.second = getCurrent_position_matrix().second;

    next_position.first--;

    return next_position;
}

std::pair<int, int> Piece::nextPositionDown() {
    std::pair <int,int> next_position;
    next_position.first = getCurrent_position_matrix().first;
    next_position.second = getCurrent_position_matrix().second;

    next_position.second++;

    return next_position;
}

std::vector<std::vector<int> > Piece::getRotation(Rotation rotation) {
    switch (rotation){
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

void Piece::calculateInitialPositions() {

    // first x
    // second y

    // Piece is spawned at row 0 of the board in the middle column (round to minor)
    this->initial_position_rotation0.first = (int)(Options::getInstance()->getBoard_blocks_width() / 2 -2);
    this->initial_position_rotation90.first = (int)(Options::getInstance()->getBoard_blocks_width() / 2 -2);
    this->initial_position_rotation180.first = (int)(Options::getInstance()->getBoard_blocks_width() / 2 -2);
    this->initial_position_rotation270.first = (int)(Options::getInstance()->getBoard_blocks_width() / 2 -2);

    bool empty_line = true;
    int count = 0;

    for (int i = 0; empty_line && i < rotation0.size(); i++){
        for (int j=0; empty_line && j < rotation0[i].size(); j++){

            if (rotation0[i][j] != 0){
                empty_line = false;
            }
        }
        if (empty_line){
            count++;
        }
    }

    this->initial_position_rotation0.second = 0 - count;

    // --------

    empty_line = true;
    count = 0;

    for (int i = 0; empty_line && i < rotation90.size(); i++){
        for (int j=0; empty_line && j < rotation90[i].size(); j++){

            if (rotation90[i][j] != 0){
                empty_line = false;
            }
        }
        if (empty_line){
            count++;
        }
    }

    this->initial_position_rotation90.second = 0 - count;

    // --------

    empty_line = true;
    count = 0;

    for (int i = 0; empty_line && i < rotation180.size(); i++){
        for (int j=0; empty_line && j < rotation180[i].size(); j++){

            if (rotation180[i][j] != 0){
                empty_line = false;
            }
        }
        if (empty_line){
            count++;
        }
    }

    this->initial_position_rotation180.second = 0 - count;

    // --------

    empty_line = true;
    count = 0;

    for (int i = 0; empty_line && i < rotation270.size(); i++){
        for (int j=0; empty_line && j < rotation270[i].size(); j++){

            if (rotation270[i][j] != 0){
                empty_line = false;
            }
        }
        if (empty_line){
            count++;
        }
    }

    this->initial_position_rotation270.second = 0 - count;

    // --------

}

int Piece::getSizeX() {

    int size = 0;
    int size_tmp = 0;

    for (std::vector<std::vector<int> >::iterator itx = getPieceBlocks().begin() ; itx != getPieceBlocks().end(); ++itx){
        for (int y = 0;y < (*itx).size(); y++){
            if ((*itx)[y] != 0){
                size_tmp++;
            }
        }
        if (size_tmp > size){
            size = size_tmp;
            size_tmp = 0;
        }
    }

    return size;
}

int Piece::getSizeY() {

    int size = 0;
    bool block = false;

    for (std::vector<std::vector<int> >::iterator itx = getPieceBlocks().begin() ; itx != getPieceBlocks().end(); ++itx){
        for (int y = 0;y < (*itx).size(); y++){
            if ((*itx)[y] != 0){
                block = true;
            }
        }
        if (block){
            size++;
            block = false;
        }
    }

    return size;
}
