//
// Created by lifka on 18/06/17.
//

#ifndef PROJECT_OPTIONS_H
#define PROJECT_OPTIONS_H

#include <allegro5/color.h>
#include "Point2D.h"

class Options{
private:
    Point2D board_offset;
    ALLEGRO_COLOR background_color;
    ALLEGRO_COLOR board_color;
    ALLEGRO_COLOR walls_color;

    unsigned long walls_width;
    unsigned long block_size;
    unsigned long board_blocks_width;
    unsigned long board_blocks_height;
    int screen_width;
    int screen_height;
    static Options* instance;
    Options& operator=(Options const&){};
    Options(Options const&){};
    Options();
public:
    static Options* getInstance();
    unsigned long getWalls_width() const;
    void setWalls_width(unsigned long walls_width);
    unsigned long getBlock_size() const;
    void setBlock_size(unsigned long block_size);
    unsigned long getBoard_blocks_width() const;
    void setBoard_blocks_width(unsigned long board_blocks_width);
    unsigned long getBoard_blocks_height() const;
    void setBoard_blocks_height(unsigned long board_blocks_height);
    int getScreen_width() const;
    void setScreen_width(int screen_width);
    int getScreen_height() const;
    void setScreen_height(int screen_height);

    unsigned long getBoardWidthInPixels() const;
    unsigned long getBoardHeightInPixels() const;

    //Colors
    const ALLEGRO_COLOR &getBackground_color() const;
    void setBackground_color(const ALLEGRO_COLOR &background_color);
    const ALLEGRO_COLOR &getBoard_color() const;
    void setBoard_color(const ALLEGRO_COLOR &board_color);
    const ALLEGRO_COLOR &getWalls_color() const;
    void setWalls_color(const ALLEGRO_COLOR &walls_color);

    //Board position
    Point2D &getBoard_offset();
    void setBoard_offset(const Point2D &board_offset);



};
#endif //PROJECT_OPTIONS_H
