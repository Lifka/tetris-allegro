//
// Created by metinu on 25/07/17.
//

#include <gtest/gtest.h>
#include "../Model/Options.h"

// Context: only just initialized the board (the board is empty)
namespace {
    class OptionsTest : public testing::Test{
    public:
        Options* options = Options::getInstance();
        OptionsTest(){}
    };
}

TEST_F(OptionsTest, singleton){
    Options* one_instance = Options::getInstance();
    Options* another_instance = Options::getInstance();

    // Same memory address, same object
    ASSERT_EQ(one_instance, another_instance);
}

TEST_F(OptionsTest, getSetBackground){
    ColorName color = ColorName ::blue;
    options->setBackground_color(color);

    ASSERT_EQ(options->getBackground_color(), color);
}

TEST_F(OptionsTest, getSetBoardColor){
    ColorName color = ColorName ::blue;
    options->setBoard_color(color);

    ASSERT_EQ(options->getBoard_color(), color);
}

TEST_F(OptionsTest, getSetWalls_color){
    ColorName color = ColorName ::blue;
    options->setWalls_color(color);

    ASSERT_EQ(options->getWalls_color(), color);
}

TEST_F(OptionsTest, getSetTextColor){
    ColorName color = ColorName ::blue;
    options->setTextColor(color);

    ASSERT_EQ(options->getTextColor(), color);
}

TEST_F(OptionsTest, getSetgameOverColor){
    ColorName color = ColorName ::blue;
    options->setgameOverColor(color);

    ASSERT_EQ(options->getgameOverColor(), color);
}

TEST_F(OptionsTest, getSetBoard_offset){
    Point2D offset = Point2D(5,4);
    options->setBoard_offset(offset);

    ASSERT_EQ(options->getBoard_offset().getPosition(), offset.getPosition());
}

TEST_F(OptionsTest, lineScore){
    ASSERT_GT(options->getLine_score(), 0);
}

TEST_F(OptionsTest, pieceScore){
    ASSERT_GT(options->getPieceScore(), 0);
}

TEST_F(OptionsTest, Score_for_levelup){
    ASSERT_GT(options->getScore_for_levelup(), 0);
}

TEST_F(OptionsTest, Next_piece_offset_position_screen){
    Point2D offset = Point2D(5,4);
    options->setNext_piece_offset_position_screen(offset);

    ASSERT_EQ(options->getNext_piece_offset_position_screen().getPosition(), offset.getPosition());
}

TEST_F(OptionsTest, Level_offset_position_screen){
    Point2D offset = Point2D(5,4);
    options->setLevel_offset_position_screen(offset);

    ASSERT_EQ(options->getLevel_offset_position_screen().getPosition(), offset.getPosition());
}

TEST_F(OptionsTest, Score_offset_position_screen){
    Point2D offset = Point2D(5,4);
    options->setScore_offset_position_screen(offset);

    ASSERT_EQ(options->getScore_offset_position_screen().getPosition(), offset.getPosition());
}

TEST_F(OptionsTest, GameOver_offset_position_screen){
    Point2D offset = Point2D(5,4);
    options->setGameOver_offset_position_screen(offset);

    ASSERT_EQ(options->getGameOver_offset_position_screen().getPosition(), offset.getPosition());
}

TEST_F(OptionsTest, getSetFont_size){
    int size = 10;
    options->setFont_size(size);
    ASSERT_EQ(size, options->getFont_size());
}

TEST_F(OptionsTest, getSetFont){
    char* f = "test";
    options->setFont(f);
    ASSERT_EQ(f, options->getFont());
}

TEST_F(OptionsTest, getSetFont_game_over_size){
    int size = 10;
    options->setFont_game_over_size(size);
    ASSERT_EQ(size, options->getFont_game_over_size());
}

TEST_F(OptionsTest, getSetFont_press_to_restart_size){
    int size = 10;
    options->setFont_press_to_restart_size(size);
    ASSERT_EQ(size, options->getFont_press_to_restart_size());
}

TEST_F(OptionsTest, getSetPressToRestartOffsetPositionScreen){
    Point2D offset = Point2D(5,4);
    options->setPressToRestartOffsetPositionScreen(offset);

    ASSERT_EQ(options->getPressToRestartOffsetPositionScreen().getPosition(), offset.getPosition());
}

TEST_F(OptionsTest, getFallingTimeFactorScale){
    double size = 10;
    options->setFallingTimeFactorScale(size);
    ASSERT_EQ(size, options->getFallingTimeFactorScale());
}