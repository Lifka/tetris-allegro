//
// Created by metinu on 27/08/17.
//

#include <gtest/gtest.h>
#include "../Model/Factory.h"

// Context: only just initialized the board (the board is empty)
namespace {
    class FactoryTest : public testing::Test{
    public:
        Factory obj;
        FactoryTest(){
            obj = Factory();
        }
    };
}

TEST_F(FactoryTest, createPiece){
    Piece piece = Piece();
    PieceType type = piece.getPieceType();

    Piece p2 = obj.createPiece(type);

    ASSERT_EQ(p2.getPieceType(), type);
}
