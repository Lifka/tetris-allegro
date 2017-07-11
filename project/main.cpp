#include <iostream>
#include "Model/Options.h"
#include "Model/ColorPalette.h"
#include "Controller/GameManager.h"
#include "Model/Board.h"
#include "View/Drawer.h"
#include "Model/PlayerInput.h"
#include "Model/Strings.h"
#include <allegro5/allegro_primitives.h>
#include <allegro5/allegro_ttf.h>
#include <allegro5/allegro_audio.h>
#include <allegro5/allegro_acodec.h>
#include <cmath>


ALLEGRO_DISPLAY *display = NULL;
ALLEGRO_EVENT_QUEUE *event_queue = NULL;
ALLEGRO_SAMPLE *main_track=NULL;
ALLEGRO_SAMPLE *gameover_track=NULL;
ALLEGRO_SAMPLE_ID *id_main_track = NULL;
ALLEGRO_SAMPLE_ID *id_gameover_track = NULL;
ALLEGRO_TIMER *timer_falling_piece = NULL;
const double FRAMES_PER_SECOND = 25;
bool is_game_over = false;
int level_cache = 0;

void prepareGame(){
    GameManager::getInstance()->addObserver(Drawer::getInstance());
    PlayerInput::getInstance()->addObserver(GameManager::getInstance());
    Board::getInstance()->addObserver(Drawer::getInstance());
}

void startGame(){
    GameManager::getInstance()->initGame();
    GameManager::getInstance()->refreshNextPiece();
    Board::getInstance()->refreshFallingPiece();
    al_play_sample(main_track, 1.0, 0.0,1.0,ALLEGRO_PLAYMODE_LOOP,id_main_track);
    timer_falling_piece = al_create_timer(Options::getInstance()->getFallingTimeFactorScale());
    al_register_event_source(event_queue, al_get_timer_event_source(timer_falling_piece));
    al_start_timer(timer_falling_piece);
}

void music(){
    main_track = al_load_sample( "../music/main.ogg" );
    gameover_track = al_load_sample( "../music/gameover.ogg" );
}

void initAllegro(){

    al_set_window_title(display, Strings::getInstance()->getTitle());

    al_clear_to_color(ColorPalette::getInstance()->getColor(Options::getInstance()->getBackground_color()));

    al_install_keyboard();
    al_init_primitives_addon();
    al_init_font_addon();
    al_init_ttf_addon();

    event_queue = al_create_event_queue();
    al_register_event_source(event_queue, al_get_display_event_source(display));
    al_register_event_source(event_queue, al_get_keyboard_event_source());
}

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

bool updateGame(){

   // Board::getInstance()->moveFallingPieceDown();
    bool result;
    bool need_restart = false;


    ALLEGRO_EVENT ev;
    al_wait_for_event(event_queue, &ev);

    if(ev.type == ALLEGRO_EVENT_TIMER) {
        Board::getInstance()->moveFallingPieceDown();
    }

    if (!GameManager::getInstance()->isGameOver()) {
        is_game_over = false;
        result = PlayerInput::getInstance()->updateInput(ev, *display, need_restart);
    } else {
        result = PlayerInput::getInstance()->updateLimitedInput(ev, *display, need_restart);

        if (!is_game_over){
            /**/std::cout << " \n\n\n ******* STOP ***** " << "\n\n";
            al_stop_timer(timer_falling_piece);
            al_stop_samples();
            al_play_sample(gameover_track, 1.0, 0.0,1.0,ALLEGRO_PLAYMODE_ONCE,id_gameover_track);
            is_game_over = true;
        }

    }


    if (need_restart){
        al_stop_samples();
        startGame();
    }

    return result;
}

void displayGame(){
    al_clear_to_color(al_map_rgb(0,0,0));

    Drawer::getInstance()->writeFonts();
    GameManager::getInstance()->refreshNextPiece();
    Drawer::getInstance()->walls();
    Drawer::getInstance()->refreshBoard();
    Board::getInstance()->refreshFallingPiece();
    GameManager::getInstance()->refreshScoreAndLevel();

    if (GameManager::getInstance()->isGameOver()){
        Drawer::getInstance()->writeGameOver();
    }

    al_flip_display();
}

void game_loop() {

    const double SKIP_TICKS =  1 / FRAMES_PER_SECOND; // s to update game

    double next_game_tick = al_get_time();

    double sleep_time = 0;
    bool game_is_running = true;


    while(game_is_running) {

        game_is_running = updateGame();

        if (level_cache != GameManager::getInstance()->getLevel()) {
            /**/std::cout << " \n\n\n ******* LEVEL UP MAIN ***** " << level_cache << "\n\n";
            level_cache = GameManager::getInstance()->getLevel();
            al_set_timer_speed(timer_falling_piece, Options::getInstance()->getFallingTimeFactorScale()/level_cache);

        }

        displayGame();

        next_game_tick += SKIP_TICKS; // Next time to update in s
        sleep_time = next_game_tick - al_get_time();

        if (sleep_time >= 0) {
            al_rest(sleep_time); // sleep

        }

    }

}


int main(int argc, char **argv)  {


    if(!al_init()) {
        fprintf(stderr, "failed to initialize allegro!\n");
        return -1;
    }

    if(!al_install_audio()){
        fprintf(stderr, "failed to initialize audio!\n");
        return -1;
    }

    if(!al_init_acodec_addon()){
        fprintf(stderr, "failed to initialize audio codecs!\n");
        return -1;
    }

    if (!al_reserve_samples(2)){
        fprintf(stderr, "failed to reserve samples!\n");
        return -1;
    }



    // ********* SETTINGS
    initDefaultsSettings();
    // ********* /SETTINGS


    display = al_create_display(Options::getInstance()->getScreen_width(), Options::getInstance()->getScreen_height());

    if(!display) {
        fprintf(stderr, "failed to create display!\n");
        return -1;
    }

    initAllegro();

    music();

    if (!main_track || !gameover_track){
        printf( "Audio clip sample not loaded!\n" );
        return -1;
    }

    prepareGame();
    startGame();

    al_flip_display();


    game_loop();

    al_destroy_timer(timer_falling_piece);
    al_stop_samples();
    al_destroy_sample(main_track);
    al_destroy_sample(gameover_track);
    al_destroy_display(display);

    return 0;
}
