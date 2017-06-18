//
// Created by lifka on 18/06/17.
//

#ifndef PROJECT_DRAWER_H
#define PROJECT_DRAWER_H

#include "../Controller/Observer.h"

class Drawer : public Observer{
private:
    static Drawer* instance;
    Drawer();
    Drawer& operator=(Drawer const&){};
    Drawer(Drawer const&){};
public:
    static Drawer* getInstance();
    void refreshBoard();
    void refreshNextPiece();
    void refreshFallingPiece();
};

#endif //PROJECT_DRAWER_H
