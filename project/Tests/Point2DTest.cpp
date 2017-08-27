//
// Created by metinu on 25/07/17.
//

#include <gtest/gtest.h>
#include "../Model/Point2DTest.h"

// Context: only just initialized the board (the board is empty)
namespace {
    class Point2DTest : public testing::Test{
    public:
        Point2DTest(){}
    };
}

TEST_F(Point2DTest, aaa){
    ASSERT_EQ(1, 1);
}