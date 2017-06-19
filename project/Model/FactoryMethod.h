//
// Created by lifka on 18/06/17.
//

#ifndef PROJECT_FACTORYMETHOD_H
#define PROJECT_FACTORYMETHOD_H

#include "Piece.h"

class FactoryMethod{
public:
    virtual Piece createPiece(PieceType type){};
};


#endif //PROJECT_FACTORYMETHOD_H
