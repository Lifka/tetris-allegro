//
// Created by lifka on 18/06/17.
//

#include "PlayerController.h"

PlayerController* PlayerController::getInstance() {
    if (!instance){
        new PlayerController();
    }
    return instance;
}

void PlayerController::up() {
    //TODO
}

void PlayerController::down() {
    //TODO
}

void PlayerController::right() {
    //TODO
}

void PlayerController::left() {
    //TODO
}

void PlayerController::rotatePiece() {
    //TODO
}
