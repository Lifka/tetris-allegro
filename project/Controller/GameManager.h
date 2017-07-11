//
// Created by lifka on 18/06/17.
//

#ifndef PROJECT_GAMEMANAGER_H
#define PROJECT_GAMEMANAGER_H

#include "Subject.h"
#include "../Model/Factory.h"

class GameManager : public Subject, public Observer{
private:
    int level = 1;
    int score = 0;
    static GameManager* instance;
    GameManager(){};
    GameManager& operator=(GameManager const&){};
    GameManager(GameManager const&){};
    Factory factory = Factory();
    Piece next_piece;
public:
    static GameManager* getInstance();
    void initGame();
    void createNewPiece();
    void scoreUp();
    void scoreUpPiece();
    void nextPiece();
    void newFallingPiece();
    void refreshNextPiece();
    void refreshScoreAndLevel();
    bool isGameOver();
    int getLevel();
};

#endif //PROJECT_GAMEMANAGER_H
