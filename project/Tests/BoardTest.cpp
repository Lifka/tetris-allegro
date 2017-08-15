//
// Created by metinu on 25/07/17.
//

#include <gtest/gtest.h>
#include <gmock/gmock.h>
#include "../Model/Board.h"
#include "../Model/Options.h"

// Context: only just initialized the board (the board is empty)
namespace {
    class BoardTest : public testing::Test{
    public:
        Board* obj = Board::getInstance();
        std::pair <int,int> board_center;
        BoardTest(){
            obj;
            board_center = std::make_pair(Options::getInstance()->getBoard_blocks_width()/2, Options::getInstance()->getBoard_blocks_height()/2);
        }
    };
}

TEST_F(BoardTest, getInstance){
    Board* one_instance = Board::getInstance();
    Board* another_instance = Board::getInstance();

    // Same memory address, same object
    ASSERT_EQ(one_instance, another_instance);
}

TEST_F(BoardTest, isFree){
    ASSERT_EQ(obj->isFree(Point2D(0,0)),true);
}

TEST_F(BoardTest, isPossibleMovement){
    bool expected_value = true;

    std::pair<int,int> test_position = board_center;
    Rotation test_rotation = Rotation::degrees0;

    bool actual_value = obj->isPossibleMoviment(test_position, test_rotation);

    ASSERT_EQ(expected_value,actual_value);
}

TEST_F(BoardTest, isPossibleMovementX){
    bool expected_value = true;

    std::pair<int,int> test_position = board_center;
    Rotation test_rotation = Rotation::degrees0;

    bool actual_value = obj->isPossibleMovimentX(test_position, test_rotation);

    ASSERT_EQ(expected_value,actual_value);
}

TEST_F(BoardTest, isPossibleMovementY){
    bool expected_value = true;

    std::pair<int,int> test_position = board_center;
    Rotation test_rotation = Rotation::degrees0;

    bool actual_value = obj->isPossibleMovimentY(test_position, test_rotation);

    ASSERT_EQ(expected_value,actual_value);
}

// checkLines delete full filled lines, so after calling it the last line can't be full
TEST_F(BoardTest, checkLines){
    obj->checkLines();

    int last_line_filled_blocks = 0;

    for (int i = 0; i < Options::getInstance()->getBoard_blocks_width(); i++){
        if (obj->getBoardPosition(i, Options::getInstance()->getBoard_blocks_height()) != 0)
            last_line_filled_blocks++;
    }

    ASSERT_TRUE(last_line_filled_blocks < Options::getInstance()->getBoard_blocks_width());
}

TEST_F(BoardTest, isGameOver){
    bool actual_value = obj->isGameOver();
    bool expected_value = false;

    ASSERT_EQ(actual_value, expected_value);
}


TEST_F(BoardTest, initBoard){
    obj->initBoard();

    int used_blocks = 0;

    for (int i = 0; i < Options::getInstance()->getBoard_blocks_width(); i++)
        for (int j = 0; j < Options::getInstance()->getBoard_blocks_height(); j++)
            if(obj->getBoardPosition(i,j) == 1)
                used_blocks++;

    ASSERT_EQ(used_blocks,0);
}

TEST_F(BoardTest, setFallingPiece){
    Piece piece_before_call = obj->getFalling_piece();
    obj->setFallingPiece(Piece());
    Piece piece_after_call = obj->getFalling_piece();

    ASSERT_FALSE(piece_before_call == piece_after_call);
}

TEST_F(BoardTest, getBoardPosition){
    int expected_value = 0;
    int actual_value = obj->getBoardPosition(board_center.first, board_center.second);

    ASSERT_EQ(expected_value, actual_value);
}

TEST_F(BoardTest, getColorPosition){
    ColorName expected_value = ColorName::none;
    ColorName actual_value = obj->getColorPosition(board_center.first, board_center.second);

    ASSERT_EQ(expected_value, actual_value);
}

TEST_F(BoardTest, rotateFallingPiece){
    Rotation before_calling_rotation = obj->getFalling_piece().getRotation();

    obj->rotateFallingPiece();

    Rotation after_calling_rotation = obj->getFalling_piece().getRotation();

    switch (before_calling_rotation){
        case degrees0:
            ASSERT_EQ(degrees270, after_calling_rotation);
            break;
        case degrees90:
            ASSERT_EQ(degrees0, after_calling_rotation);
            break;
        case degrees180:
            ASSERT_EQ(degrees90, after_calling_rotation);
            break;
        case degrees270:
            ASSERT_EQ(degrees180, after_calling_rotation);
            break;
    }
}

TEST_F(BoardTest, moveFallingPieceToRight){
    std::pair <int,int> before_calling_position;
    bool is_possible;
    std::pair <int,int> after_calling_position;


    before_calling_position = obj->getFalling_piece().getCurrent_position_matrix();

    is_possible = obj->isPossibleMoviment(obj->getFalling_piece().nextPositionRight(), obj->getFalling_piece().getRotation());

    obj->moveFallingPieceToRight();
    after_calling_position = obj->getFalling_piece().getCurrent_position_matrix();

    if (is_possible) {
        ASSERT_NE(before_calling_position, after_calling_position);
        ASSERT_EQ(obj->getFalling_piece().nextPositionLeft(), before_calling_position);
    } else {
        ASSERT_EQ(before_calling_position, after_calling_position);
        ASSERT_NE(obj->getFalling_piece().nextPositionLeft(), before_calling_position);
    }
}


TEST_F(BoardTest, moveFallingPieceToLeft){
    std::pair <int,int> before_calling_position;
    bool is_possible;
    std::pair <int,int> after_calling_position;

    before_calling_position = obj->getFalling_piece().getCurrent_position_matrix();

    is_possible = obj->isPossibleMoviment(obj->getFalling_piece().nextPositionLeft(), obj->getFalling_piece().getRotation());

    obj->moveFallingPieceToLeft();
    after_calling_position = obj->getFalling_piece().getCurrent_position_matrix();

    if (is_possible) {
        ASSERT_NE(before_calling_position, after_calling_position);
        ASSERT_EQ(obj->getFalling_piece().nextPositionRight(), before_calling_position);
    } else {
        ASSERT_EQ(before_calling_position, after_calling_position);
        ASSERT_NE(obj->getFalling_piece().nextPositionRight(), before_calling_position);
    }
}

TEST_F(BoardTest, moveFallingPieceToDown){
    std::pair <int,int> before_calling_position;
    bool is_possible;
    std::pair <int,int> after_calling_position;

    before_calling_position = obj->getFalling_piece().getCurrent_position_matrix();

    is_possible = obj->isPossibleMoviment(obj->getFalling_piece().nextPositionDown(), obj->getFalling_piece().getRotation());

    obj->moveFallingPieceDown();
    after_calling_position = obj->getFalling_piece().getCurrent_position_matrix();

    if (is_possible) {
        ASSERT_NE(before_calling_position, after_calling_position);
    } else {
        ASSERT_EQ(before_calling_position, after_calling_position);
        ASSERT_NE(obj->getFalling_piece().nextPositionDown(), before_calling_position);
    }
}

TEST_F(BoardTest, storeFallingPiece){
    obj->storeFallingPiece();

    int used_blocks = 0;

    for (int i = 0; i < Options::getInstance()->getBoard_blocks_width(); i++)
        for (int j = 0; j < Options::getInstance()->getBoard_blocks_height(); j++)
            if(obj->getBoardPosition(i,j) != 0)
                used_blocks++;

    ASSERT_NE(used_blocks,0);
}

TEST_F(BoardTest, getFallingPiece){
    Piece piece_before_call = obj->getFalling_piece();
    obj->setFallingPiece(Piece());
    ASSERT_FALSE(piece_before_call == obj->getFalling_piece());
}