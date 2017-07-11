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



ALLEGRO_DISPLAY *display = NULL;
ALLEGRO_EVENT_QUEUE *event_queue = NULL;
ALLEGRO_SAMPLE *main_track=NULL;
ALLEGRO_SAMPLE *gameover_track=NULL;
ALLEGRO_SAMPLE_ID *id_main_track = NULL;
ALLEGRO_SAMPLE_ID *id_gameover_track = NULL;
bool game_over_souned = false;

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
    al_install_audio();
    al_init_acodec_addon();
    al_reserve_samples(50);

    event_queue = al_create_event_queue();
    al_register_event_source(event_queue, al_get_display_event_source(display));
    al_register_event_source(event_queue, al_get_keyboard_event_source());
}

void initDefaultsSettings(){

    Options::getInstance()->setBoard_blocks_height(20); // blocks
    Options::getInstance()->setBoard_blocks_width(11); // blocks

    Options::getInstance()->setWalls_width(14);

    Options::getInstance()->setBlock_size(46); // pixels block

    Options::getInstance()->setScreen_height(945); // pixels
    Options::getInstance()->setScreen_width(900); // pixels

    Options::getInstance()->setWalls_color(ColorName::purple);
    Options::getInstance()->setBoard_color(ColorName::indigo);
    Options::getInstance()->setBackground_color(ColorName::black);
    Options::getInstance()->setTextColor(ColorName::white);
    Options::getInstance()->setgameOverColor(ColorName::lime);

    Options::getInstance()->setFont_size(20);
    Options::getInstance()->setFont_game_over_size(100);
    Options::getInstance()->setFont_press_to_restart_size(30);
    Options::getInstance()->setFont((char *) "../fonts/pirulen.ttf");

    Options::getInstance()->setBoard_offset(Point2D(0,0));
    Options::getInstance()->setNext_piece_offset_position_screen(Point2D(650,100));
    Options::getInstance()->setLevel_offset_position_screen(Point2D(650,500));
    Options::getInstance()->setScore_offset_position_screen(Point2D(650,700));
    Options::getInstance()->setGameOver_offset_position_screen(Point2D(Options::getInstance()->getScreen_height()/2,Options::getInstance()->getScreen_width()/2 - 150));
    Options::getInstance()->setPressToRestartOffsetPositionScreen(Point2D(Options::getInstance()->getScreen_height()/2,Options::getInstance()->getScreen_width()/2 - 50));
}

bool updateGame(){

   // Board::getInstance()->moveFallingPieceDown();
    bool result = true;
    bool need_restart = false;

    ALLEGRO_EVENT ev;
    al_wait_for_event(event_queue, &ev);

    if (!GameManager::getInstance()->isGameOver()) {
        game_over_souned = false;
        result = PlayerInput::getInstance()->updateInput(ev, *display, need_restart);
    } else {
        result = PlayerInput::getInstance()->updateLimitedInput(ev, *display, need_restart);

        if (!game_over_souned){
            al_stop_samples();
            al_play_sample(gameover_track, 1.0, 0.0,1.0,ALLEGRO_PLAYMODE_ONCE,id_gameover_track);
            game_over_souned = true;
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

    const double FRAMES_PER_SECOND = 25;
    const double SKIP_TICKS =  1 / FRAMES_PER_SECOND; // s to update game

    double next_game_tick = al_get_time();

    double sleep_time = 0;
    bool game_is_running = true;


    while(game_is_running) {
        game_is_running = updateGame();
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

    if (!al_reserve_samples(1)){
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

    al_stop_samples();
    al_destroy_sample(main_track);
    al_destroy_sample(gameover_track);
    al_destroy_display(display);

    return 0;
}
