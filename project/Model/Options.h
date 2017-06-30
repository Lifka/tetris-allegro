//
// Created by lifka on 18/06/17.
//

#ifndef PROJECT_OPTIONS_H
#define PROJECT_OPTIONS_H

class Options{
private:
    unsigned long walls_width;
    unsigned long block_size;
    unsigned long board_blocks_width;
    unsigned long board_blocks_height;
    unsigned long game_width;
    static Options* instance;
    Options& operator=(Options const&){};
    Options(Options const&){};
    Options();
public:
    static Options* getInstance();
    unsigned long getWalls_width() const;
    void setWalls_width(int walls_width);
    unsigned long getBlock_size() const;
    void setBlock_size(int block_size);
    unsigned long getBoard_blocks_width() const;
    void setBoard_blocks_width(int board_blocks_width);
    unsigned long getBoard_blocks_height() const;
    void setBoard_blocks_height(int board_blocks_height);
    unsigned long getGame_width() const;
    void setGame_width(int board_blocks_height);
};
#endif //PROJECT_OPTIONS_H
