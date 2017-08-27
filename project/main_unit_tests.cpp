#include <gtest/gtest.h>
#include "Model/Options.h"
#include "Model/ColorPalette.h"
#include "View/Drawer.h"

#include "Model/Board.h"
#include "Controller/GameManager.h"

// Compute pixels values for the window size depending on the current screen resolution
void initResolutionsResponsive(){

    // Lifka Screen 1920 x 1080
    double height_factor = 945.0 / 1080.0;
    double width_factor = 900.0 / 1920.0;

    // Recovering screen info of this monitor
    ALLEGRO_MONITOR_INFO info;

    al_get_monitor_info(0, &info);
    double w = (double) (info.x2 - info.x1);
    double h = (double) (info.y2 - info.y1);

    //std::cout << "Resolution of screen = " << w << " x " << h << std::endl;

    double screen_height = h * height_factor;
    double screen_width = w * width_factor;
    Options::getInstance()->setScreen_height((int) std::round(screen_height)); // pixels
    Options::getInstance()->setScreen_width((int) std::round(screen_width)); // pixels

    int walls_width = 14;
    Options::getInstance()->setWalls_width( walls_width );

    double block_size = (screen_height - walls_width * 2.0) / Options::getInstance()->getBoard_blocks_height();
    Options::getInstance()->setBlock_size((int) std::round(block_size)); // pixels block

    // Basing on screen width... Lifka font_size = 20
    double font_size = 20;
    double font_factor = w / 1920.0;
    font_size *= font_factor;

    Options::getInstance()->setFont_size((int) std::round(font_size)); // 20
    Options::getInstance()->setFont_game_over_size((int) std::round(font_size * 5.0)); // 100
    Options::getInstance()->setFont_press_to_restart_size((int) std::round(font_size * 1.5)); // 30
    /*
    Options::getInstance()->setFont_size(12); // 20
    Options::getInstance()->setFont_game_over_size(12); // 100
    Options::getInstance()->setFont_press_to_restart_size(12); // 30*/

    Options::getInstance()->setBoard_offset(Point2D(0,0)); // Don't change without adjust width and height factor!

    // Lifka previous window size: 900x945

    width_factor = 650.0 / 900.0;
    height_factor = 100.0 / 945.0;

    Options::getInstance()->setNext_piece_offset_position_screen(Point2D((int) std::round(screen_width * width_factor),
                                                                         (int) std::round(screen_height * height_factor)));
    Options::getInstance()->setLevel_offset_position_screen(Point2D((int) std::round(screen_width * width_factor),
                                                                    (int) (std::round(screen_height * height_factor) * 5)));
    Options::getInstance()->setScore_offset_position_screen(Point2D((int) std::round(screen_width * width_factor),
                                                                    (int) (std::round(screen_height * height_factor) * 7)));
    Options::getInstance()->setGameOver_offset_position_screen(Point2D(Options::getInstance()->getScreen_height()/2,
                                                                       (int) (Options::getInstance()->getScreen_width() / 2 - std::round(screen_height * height_factor * 1.5))));
    Options::getInstance()->setPressToRestartOffsetPositionScreen(Point2D(Options::getInstance()->getScreen_height()/2,
                                                                          (int) (Options::getInstance()->getScreen_width() / 2 - std::round(screen_height * height_factor * 0.5))));
}

// Init options values, needed for board and game
void initDefaultsSettings(){

    Options::getInstance()->setBoard_blocks_height(20); // blocks
    Options::getInstance()->setBoard_blocks_width(11); // blocks

    initResolutionsResponsive();

    Options::getInstance()->setWalls_color(ColorName::purple);
    Options::getInstance()->setBoard_color(ColorName::indigo);
    Options::getInstance()->setBackground_color(ColorName::black);
    Options::getInstance()->setTextColor(ColorName::white);
    Options::getInstance()->setgameOverColor(ColorName::lime);

    Options::getInstance()->setFont((char *) "../fonts/pirulen.ttf");

    Options::getInstance()->setFallingTimeFactorScale(0.6); // blocks
}

int main(int argc, char *argv[]) {

    initDefaultsSettings();

    GameManager::getInstance()->initGame();
    GameManager::getInstance()->refreshNextPiece();
    Board::getInstance()->refreshFallingPiece();

    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}