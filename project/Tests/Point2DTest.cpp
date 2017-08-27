//
// Created by metinu on 28/07/17.
//

#include <gtest/gtest.h>
#include "../Model/Point2D.h"


namespace {
    class Point2DTest : public testing::Test{
    public:
        Point2DTest(){}
    };
}

TEST_F(Point2DTest, constructor){
    Point2D p = Point2D(5,5);
    ASSERT_EQ(p.getX(), 5);
    ASSERT_EQ(p.getY(), 5);
}

TEST_F(Point2DTest, getSetX){
    Point2D p = Point2D(5,5);
    p.setX(99);
    ASSERT_EQ(p.getX(), 99);
}

TEST_F(Point2DTest, getSetY){
    Point2D p = Point2D(5,5);
    p.setY(99);
    ASSERT_EQ(p.getY(), 99);
}

TEST_F(Point2DTest, getPositionPair){
    Point2D p = Point2D(5,5);
    std::pair<int, int> pair = std::make_pair(5,5);
    ASSERT_EQ(p.getX(), pair.first);
    ASSERT_EQ(p.getY(), pair.second);
}