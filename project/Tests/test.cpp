//
// Created by metinu on 25/07/17.
//

#include <gtest/gtest.h>
#include <gmock/gmock.h>
#include "TestClass.h"

namespace {
    class ClassDeclaration : public testing::Test{
    public:
        TestClass obj;
        ClassDeclaration(){
            obj;
        }
    };
}

TEST_F(ClassDeclaration, nameOfTheTest1){
    ASSERT_EQ("","");
}

TEST_F(ClassDeclaration, nameOfTheTest2){
    ASSERT_EQ(1,2);
}