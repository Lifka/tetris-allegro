//
// Created by lifka on 18/06/17.
//

#ifndef PROJECT_FACTORY_H
#define PROJECT_FACTORY_H

#include "FactoryMethod.h"

class Factory: public FactoryMethod {
public:
    virtual Piece createPiece(PieceType type);

};

#endif //PROJECT_FACTORY_H
