//
// Created by metinu on 18/08/17.
//

#include <gtest/gtest.h>
#include "../Controller/GameManager.h"
#include "../Model/Options.h"

namespace {
    class PieceTest : public testing::Test{
    public:
        Piece obj;
        PieceTest(){
            obj = Piece();
        }
    };
}

TEST_F(PieceTest, constructor){
    std::vector<std::vector<int> > r0, r90, r180, r270 = std::vector<std::vector<int> >();
    Rotation rot = Rotation::degrees0;
    PieceType type = PieceType::I;
    ColorName color = ColorName::blue;


    Piece p = Piece(r0, r90, r180, r270, rot, type, color);

    // After constructor call values
    Rotation rot_actual = p.getRotation();
    std::vector<std::vector<int> > r0_actual = p.getRotation(rot_actual);
    PieceType type_actual = p.getPieceType();
    ColorName color_actual = p.getColor();

    ASSERT_EQ(r0, r0_actual);
    ASSERT_EQ(rot, rot_actual);
    ASSERT_EQ(type, type_actual);
    ASSERT_EQ(color, color_actual);
}

TEST_F(PieceTest, copy_constructor){
    std::vector<std::vector<int> > r0, r90, r180, r270 = std::vector<std::vector<int> >();
    Rotation rot = Rotation::degrees0;
    PieceType type = PieceType::I;
    ColorName color = ColorName::blue;


    Piece p = Piece(r0, r90, r180, r270, rot, type, color);

    Piece p2 = Piece(p);

    ASSERT_TRUE(p == p2);
}

TEST_F(PieceTest, getInitialPosition){
    std::vector<std::vector<int> > r0, r90, r180, r270 = std::vector<std::vector<int> >();
    Rotation rot = Rotation::degrees0;
    PieceType type = PieceType::I;
    ColorName color = ColorName::blue;


    Piece p = Piece(r0, r90, r180, r270, rot, type, color);

    std::pair <int,int> expected_initial_position_r0 = std::make_pair((int)(Options::getInstance()->getBoard_blocks_width() / 2 -2),0);

    bool empty_line = true;
    int count = 0;

    for (int i = 0; empty_line && i < p.getPieceBlocks().size(); i++) {
        for (int j = 0; empty_line && j < p.getPieceBlocks()[i].size(); j++) {

            if (p.getPieceBlocks()[i][j] != 0) {
                empty_line = false;
            }
        }
        if (empty_line) {
            count++;
        }

    }
    expected_initial_position_r0.second = 0 - count;
    std::pair <int,int> actual_initial_position_r0 = p.getInitialPosition();

    ASSERT_EQ(expected_initial_position_r0, actual_initial_position_r0);

}