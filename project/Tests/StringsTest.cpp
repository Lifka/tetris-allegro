//
// Created by metinu on 28/07/17.
//

#include <gtest/gtest.h>
#include "../Model/Strings.h"


namespace {
    class StringsTest : public testing::Test{
    public:
        Strings* obj = Strings::getInstance();
        StringsTest(){}
    };
}

TEST_F(StringsTest, singleton){
    Strings* one_instance = Strings::getInstance();
    Strings* another_instance = Strings::getInstance();

    // Same memory address, same object
    ASSERT_EQ(one_instance, another_instance);
}


// Check if strings are not empty strings

TEST_F(StringsTest, score) {
    ASSERT_GT(strlen(obj->getScore()), 0);
}

TEST_F(StringsTest, level) {
    ASSERT_GT(strlen(obj->getLevel()), 0);
}

TEST_F(StringsTest, next_piece) {
    ASSERT_GT(strlen(obj->getNext_piece()), 0);
}

TEST_F(StringsTest, title) {
    ASSERT_GT(strlen(obj->getTitle()), 0);
}

TEST_F(StringsTest, gameover) {
    ASSERT_GT(strlen(obj->getGameOver()), 0);
}

TEST_F(StringsTest, pressToRestart) {
    ASSERT_GT(strlen(obj->getPressToRestart()), 0);
}
