//
// Created by lifka on 18/06/17.
//

#ifndef PROJECT_OPTIONS_H
#define PROJECT_OPTIONS_H

#include <allegro5/color.h>
#include "Point2D.h"
#include "ColorName.h"

class Options{
private:
    Point2D board_offset;
    Point2D next_piece_offset_position_screen;
    Point2D score_offset_position_screen;
    Point2D level_offset_position_screen;
    Point2D game_over_offset_position_screen;
    Point2D press_to_restart_offset_position_screen;

    ColorName background_color = ColorName::none;
    ColorName board_color = ColorName::none;
    ColorName walls_color = ColorName::none;
    ColorName text_color = ColorName::none;
    ColorName text_game_over_color = ColorName::none;

    double fallingTimeFactorScale = 1;
    char* font;
    int font_size = 20;
    int font_game_over_size = 200;
    int font_press_to_restart_size = 200;
    int line_score = 10;
    int piece_score = 1;
    int score_for_levelup = 100;
    int walls_width;
    int block_size;
    int board_blocks_width;
    int board_blocks_height;
    int screen_width;
    int screen_height;
    static Options* instance;
    Options& operator=(Options const&){};
    Options(Options const&){};
    Options();
public:
    static Options* getInstance();
    int getWalls_width() const;
    void setWalls_width(int walls_width);
    int getBlock_size() const;
    void setBlock_size(int block_size);
    int getBoard_blocks_width() const;
    void setBoard_blocks_width(int board_blocks_width);
    int getBoard_blocks_height() const;
    void setBoard_blocks_height(int board_blocks_height);
    int getScreen_width() const;
    void setScreen_width(int screen_width);
    int getScreen_height() const;
    void setScreen_height(int screen_height);

    int getBoardWidthInPixels() const;
    int getBoardHeightInPixels() const;

    //Colors
    ColorName getBackground_color();
    void setBackground_color(ColorName background_color);
    ColorName getBoard_color();
    void setBoard_color(ColorName board_color);
    ColorName getWalls_color();
    void setWalls_color(ColorName walls_color);
    ColorName getTextColor();
    void setTextColor(ColorName color);
    ColorName getgameOverColor();
    void setgameOverColor(ColorName color);

    //Board position
    Point2D &getBoard_offset();
    void setBoard_offset(const Point2D &board_offset);

    int getLine_score() const;
    int getPieceScore() const;
    int getScore_for_levelup() const;

    const Point2D &getNext_piece_offset_position_screen() const;
    void setNext_piece_offset_position_screen(const Point2D &next_piece_position_screen);
    const Point2D &getScore_offset_position_screen() const;
    void setScore_offset_position_screen(const Point2D &score_position_screen);
    const Point2D &getLevel_offset_position_screen() const;
    void setLevel_offset_position_screen(const Point2D &level_position_screen);
    const Point2D &getGameOver_offset_position_screen() const;
    void setGameOver_offset_position_screen(const Point2D &GameOver_position_screen);

    int getFont_size() const;
    void setFont_size(int font_size);

    char *getFont() const;
    void setFont(char *font);

    int getFont_game_over_size() const;
    void setFont_game_over_size(int font__game_over_size);

    int getFont_press_to_restart_size() const;
    void setFont_press_to_restart_size(int font_press_to_restart_size);

    const Point2D &getPressToRestartOffsetPositionScreen() const;
    void setPressToRestartOffsetPositionScreen(const Point2D &game_over_offset_position_screen);

    void setFallingTimeFactorScale(const double&);
    const double &getFallingTimeFactorScale() const;
};
#endif //PROJECT_OPTIONS_H
