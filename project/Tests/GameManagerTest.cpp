//
// Created by metinu on 15/08/17.
//

#include <gtest/gtest.h>
#include <gmock/gmock.h>
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
/*
TEST_F(GameManagerTest, createNewPiece){

}

TEST_F(GameManagerTest, scoreUp){

}

TEST_F(GameManagerTest, scoreUpPiece){

}

TEST_F(GameManagerTest, nextPiece){

}

TEST_F(GameManagerTest, newFallingPiece){

}

TEST_F(GameManagerTest, refreshNextPiece){

}

TEST_F(GameManagerTest, refreshScoreAndLevel){

}

TEST_F(GameManagerTest, isGameOver){

}

TEST_F(GameManagerTest, getLevel){

}
 */