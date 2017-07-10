//
// Created by lifka on 5/07/17.
//

#include "Strings.h"

Strings* Strings::instance = nullptr;

Strings* Strings::getInstance() {
    if (!instance)
        instance = new Strings();
    return instance;
}

const char *Strings::getScore() const {
    return score;
}

const char *Strings::getLevel() const {
    return level;
}

const char *Strings::getNext_piece() const {
    return next_piece;
}

const char *Strings::getTitle() const {
    return title;
}

const char *Strings::getGameOver() const {
    return gameover;
}

const char *Strings::getPressToRestart() const {
    return pressToRestart;
}
