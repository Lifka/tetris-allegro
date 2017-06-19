//
// Created by lifka on 18/06/17.
//

#ifndef PROJECT_PLAYERCONTROLLER_H
#define PROJECT_PLAYERCONTROLLER_H

#include "Subject.h"

class PlayerController : public Subject{
private:
    static PlayerController* instance;
    PlayerController();
    PlayerController& operator=(PlayerController const&){};
    PlayerController(PlayerController const&){};
public:
    static PlayerController* getInstance();
    void up();
    void down();
    void right();
    void left();
    void rotatePiece();
};


#endif //PROJECT_PLAYERCONTROLLER_H
