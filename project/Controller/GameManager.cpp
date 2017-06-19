//
// Created by lifka on 18/06/17.
//

#include "GameManager.h"
#include "../Model/Board.h"


GameManager* GameManager::instance = nullptr;

GameManager* GameManager::getInstance() {
    if (!instance){
        instance = new GameManager();
    }
    return instance;
}

void GameManager::initGame() {
    createNewPiece();
    Board::getInstance()->initBoard(next_piece);
    createNewPiece();
}

void GameManager::createNewPiece() {

    PieceType type;
    int random = 0 + (rand() % static_cast<int>(6 - 0 + 1));
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
}
