//
// Created by metinu on 15/08/17.
//

#include <gtest/gtest.h>
#include "../Controller/GameManager.h"
#include "../Model/Board.h"

namespace {
    class GameManagerTest : public testing::Test{
    public:
        GameManager* obj = GameManager::getInstance();
        Board* board = Board::getInstance();
        GameManagerTest(){
            obj;
        }
    };
}


TEST_F(GameManagerTest, getInstance){
    GameManager* one_instance = GameManager::getInstance();
    GameManager* another_instance = GameManager::getInstance();

    // Same memory address, same object
    ASSERT_EQ(one_instance, another_instance);
}

TEST_F(GameManagerTest, initGame){
    obj->initGame();
    int actual_value = obj->getLevel();
    int expected_value = 1;

    ASSERT_EQ(actual_value, expected_value);
    ASSERT_FALSE(obj->isGameOver());
}

TEST_F(GameManagerTest, scoreUp){
    for (int i = 0; i < 999; i++)
        obj->scoreUp();

    ASSERT_TRUE(obj->getLevel() > 1);
}

TEST_F(GameManagerTest, scoreUpPiece){
    for (int i = 0; i < 999; i++)
        obj->scoreUp();

    ASSERT_TRUE(obj->getLevel() > 1);
}

TEST_F(GameManagerTest, nextPiece){
    Piece piece_1 = board->getFalling_piece();
    obj->nextPiece();
    Piece piece_2 = board->getFalling_piece();
    obj->nextPiece();
    Piece piece_3 = board->getFalling_piece();
    obj->nextPiece();
    Piece piece_4 = board->getFalling_piece();

    ASSERT_FALSE((piece_1 == piece_2) && (piece_3 == piece_4));
}


TEST_F(GameManagerTest, newFallingPiece){
    Piece piece_1 = board->getFalling_piece();
    obj->nextPiece();
    Piece piece_2 = board->getFalling_piece();
    obj->nextPiece();
    Piece piece_3 = board->getFalling_piece();
    obj->nextPiece();
    Piece piece_4 = board->getFalling_piece();

    ASSERT_FALSE((piece_1 == piece_2) && (piece_3 == piece_4));
}



TEST_F(GameManagerTest, isGameOver){
    ASSERT_EQ(obj->isGameOver(), board->isGameOver());
}



TEST_F(GameManagerTest, getLevel){
    for (int i = 0; i < 999; i++)
        obj->scoreUp();

    ASSERT_TRUE(obj->getLevel() > 1);
}