//
// Created by lifka on 18/06/17.
//

#include <iostream>
#include <random>
#include "GameManager.h"
#include "../Model/Options.h"
#include "../Model/Board.h"


GameManager* GameManager::instance = nullptr;

GameManager* GameManager::getInstance() {
    if (!instance){
        instance = new GameManager();
    }
    return instance;
}

void GameManager::initGame() {
    /**/std::cout << "[DEBUG]: (GameManager:initGame) starting game..." << std::endl;//*/

    level = 0;
    score = 0;

    /**/std::cout << "[DEBUG]: (GameManager:initGame) starting board..." << std::endl;//*/

    Board::getInstance()->initBoard();
    notifyObservers(NotifyCode::draw_screen);

    scoreUp();

    // First piece..
    createNewPiece();

    nextPiece();
}

void GameManager::createNewPiece() {

    PieceType type;

    std::mt19937 rng;
    rng.seed(std::random_device()());
    std::uniform_int_distribution<std::mt19937::result_type> rnd(0,6); // distribution in range [0, 6]
    unsigned long random = rnd(rng);

    switch (random) {
        case 0:
            type = square;
            break;
        case 1:
            type = L;
            break;
        case 2:
            type = L_mirrored;
            break;
        case 3:
            type = N;
            break;
        case 4:
            type = N_mirrored;
            break;
        case 5:
            type = I;
            break;
        case 6:
            type = T;
            break;
    }


    next_piece = factory.createPiece(type);
    /**/std::cout << "[DEBUG]: (GameManager:createNewPiece) New piece created --> Type = " <<  type << " -- Showing: " << std::endl;//*/
    /**next_piece.debugMatrix();//*/
}



void Observer::updateLine(NotifyCode code){

    /**/std::cout << "[DEBUG]: (GameManager-update) notify recieved with code --> " << code;//*/
    switch (code){
        case up_score:
            GameManager::getInstance()->scoreUp();
            GameManager::getInstance()->nextPiece();
            break;
        case next_piece:
            GameManager::getInstance()->nextPiece();
            break;

    }

}

void GameManager::scoreUp(){
    score += Options::getInstance()->getLine_score()*level;

    if (score >= Options::getInstance()->getScore_for_levelup()*level*level){
        level++;
        notifyObservers(NotifyCode::draw_levelup, level);
    }

    notifyObservers(NotifyCode::draw_scoreup, score);

}

void GameManager::nextPiece() {
    /**/std::cout << "[DEBUG]: (GameManager:nextPiece) " << std::endl;//*/

    // Set falling piece:
    newFallingPiece();

    // Set next piece:
    createNewPiece();
    //notifyObservers(NotifyCode::next_piece, next_piece);

}

void GameManager::newFallingPiece() {
    /**/std::cout << "[DEBUG]: (GameManager:newFallingPiece) " << std::endl;//*/
    Board::getInstance()->setFallingPiece(next_piece);

}

void GameManager::refreshNextPiece() {
    notifyObservers(NotifyCode::next_piece, next_piece);
}

void GameManager::refreshScoreAndLevel() {
    notifyObservers(NotifyCode::draw_levelup, level);
    notifyObservers(NotifyCode::draw_scoreup, score);
}


void Observer::update(NotifyCode code, KeyCode key) {

    /**/std::cout << "[DEBUG]: (GameManager-update) notify recieved with code --> " << code << std::endl;//*/
    if (code == NotifyCode::key_pressed){

        switch(key){
            case KeyCode::key_up:
                Board::getInstance()->rotateFallingPiece();
                break;
            case KeyCode::key_down:
                Board::getInstance()->moveFallingPieceDown();
                break;
            case KeyCode::key_right:
                Board::getInstance()->moveFallingPieceToRight();
                break;
            case KeyCode::key_left:
                Board::getInstance()->moveFallingPieceToLeft();
                break;
        }

    }
}