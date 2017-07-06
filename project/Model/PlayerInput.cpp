//
// Created by lifka on 6/07/17.
//

#include "PlayerInput.h"
#include <iostream>

PlayerInput* PlayerInput::instance = nullptr;

PlayerInput* PlayerInput::getInstance() {
    if (!instance)
        instance = new PlayerInput();
    return instance;
}

void PlayerInput::updateInput(ALLEGRO_EVENT& ev) {

    if(ev.type == ALLEGRO_EVENT_KEY_DOWN) {
        switch(ev.keyboard.keycode) {
            case ALLEGRO_KEY_UP:
                keys[KeyCode::key_up] = true;
                notifyObservers(NotifyCode::key_pressed, KeyCode::key_up);
                break;

            case ALLEGRO_KEY_DOWN:
                keys[KeyCode::key_down] = true;
                notifyObservers(NotifyCode::key_pressed, KeyCode::key_down);
                break;

            case ALLEGRO_KEY_LEFT:
                keys[KeyCode::key_left] = true;
                notifyObservers(NotifyCode::key_pressed, KeyCode::key_left);
                break;

            case ALLEGRO_KEY_RIGHT:
                keys[KeyCode::key_right] = true;
                notifyObservers(NotifyCode::key_pressed, KeyCode::key_right);
                break;

            case ALLEGRO_KEY_ESCAPE:
                keys[KeyCode::key_escape] = true;
                notifyObservers(NotifyCode::key_pressed, KeyCode::key_escape);
                break;
        }
    }
    else if(ev.type == ALLEGRO_EVENT_KEY_UP) {
        switch (ev.keyboard.keycode) {
            case ALLEGRO_KEY_UP:
                keys[KeyCode::key_up] = false;
                break;

            case ALLEGRO_KEY_DOWN:
                keys[KeyCode::key_down] = false;
                break;

            case ALLEGRO_KEY_LEFT:
                keys[KeyCode::key_left] = false;
                break;

            case ALLEGRO_KEY_RIGHT:
                keys[KeyCode::key_right] = false;
                break;

            case ALLEGRO_KEY_ESCAPE:
                keys[KeyCode::key_escape] = false;
                break;
        }
    }
}

bool PlayerInput::getKeyState(KeyCode code) {
    return keys[code];
}

bool PlayerInput::getUpState() {
    return keys[KeyCode::key_up];
}

bool PlayerInput::getDownState() {
    return keys[KeyCode::key_down];
}

bool PlayerInput::getRightState() {
    return keys[KeyCode::key_right];
}

bool PlayerInput::getLeftState() {
    return keys[KeyCode::key_left];
}

bool PlayerInput::getEscapeState() {
    return keys[KeyCode::key_escape];
}

