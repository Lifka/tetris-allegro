//
// Created by lifka on 6/07/17.
//

#ifndef PROJECT_PLAYERINPUT_H
#define PROJECT_PLAYERINPUT_H


#include "keycode.h"
#include "../Controller/Subject.h"
#include <map>
#include <allegro5/allegro.h>

class PlayerInput : public Subject {
private:
    static PlayerInput* instance;
    PlayerInput& operator=(PlayerInput const&){};
    PlayerInput(PlayerInput const&){};
    PlayerInput(){};

    std::map<KeyCode, bool > keys;

    void close(ALLEGRO_DISPLAY&);

public:
    static PlayerInput* getInstance();
    bool updateInput(ALLEGRO_EVENT&, ALLEGRO_DISPLAY&, bool&);
    bool updateLimitedInput(ALLEGRO_EVENT&, ALLEGRO_DISPLAY&, bool&);
    bool getKeyState(KeyCode);
    bool getUpState();
    bool getDownState();
    bool getRightState();
    bool getLeftState();
    bool getEscapeState();
    bool getRState();

};


#endif //PROJECT_PLAYERINPUT_H
