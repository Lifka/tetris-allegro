//
// Created by lifka on 18/06/17.
//

#include <iostream>
#include "Board.h"
#include "Options.h"

#define wall 1
#define free 0

Board* Board::instance = nullptr;

void Board::checkLines() {
    int index = 0;
    for (std::vector<std::vector<int> >::iterator itx = m_board.begin() ; itx != m_board.end(); ++itx, index++){
        bool delete_line = true;
        for (int y = 0; y < (*itx).size() && delete_line; y++){
            delete_line = (*itx)[y] != 0;
        }
        if (delete_line) {
            /**std::cout << "[DEBUG]: (Board:checkLines) Is need to delete line --> " << index << std::endl;//*/
            deleteLine(index);
            notifyObserversLine(NotifyCode::up_score);
        }
    }
}

void Board::deleteLine(int n_line) {
    /**/std::cout << "[DEBUG]: (Board:deleteLine) Deleting line --> " << n_line << std::endl;//*/
    for(int x = n_line-1; x > 0; x--) {
        m_board[x + 1] = m_board[x];
        m_board_colors[x + 1] = m_board_colors[x];
    }
    // full last line except
    m_board[0] = std::vector<int>(m_board[0].size(), 0);
    m_board_colors[0] = std::vector<ColorName>(m_board_colors[0].size(), ColorName::none);
}

Board* Board::getInstance() {

    if (!instance){
        instance = new Board();
    }
    return instance;
}


bool Board::isFree(Point2D p) {
    return m_board[p.getX()][p.getY()] == 0;
}

void Board::setFallingPiece(Piece falling_piece) {
    this->falling_piece = falling_piece;
    //notifyObservers(NotifyCode::falling_piece_changed, falling_piece);
    /**/std::cout << "[DEBUG]: (Board:setFallingPiece) New falling piece setted --> Type = " << falling_piece.getPieceType() << std::endl;//*/
}

void Board::initBoard() {
    /**/std::cout << "[DEBUG]: (Board:initBoard) Starting board..." << std::endl;//*/
    fillBoard();
}

bool Board::isGameOver() {
    bool is_game_over = false;

    int falling_piece_size_y = falling_piece.getSizeY();
    int falling_piece_size_x = falling_piece.getSizeX();

    int falling_piece_start_x_position = falling_piece.getInitialPosition().first;

    int need_blocks_y = falling_piece_size_y;

    for (int y = need_blocks_y-1; !is_game_over && y >= 0; y--){
        for (int x = falling_piece_start_x_position; !is_game_over && x <= falling_piece_start_x_position+falling_piece_size_x; x++){
            if (m_board[y][x] != 0){
                is_game_over = true;
            }
        }
    }

    return is_game_over;
}

bool Board::isPossibleMoviment(std::pair <int,int> position, Rotation rotation) {
    bool possible = isPossibleMovimentX(position, rotation);

    possible = possible && isPossibleMovimentY(position, rotation);

    return possible;
}

bool Board::isPossibleMovimentY(std::pair <int,int> position, Rotation rotation) {
    bool possible = true;

    for(int y = 0; possible && y < falling_piece.getRotation(rotation).size(); y++){
        for(int x = 0; possible && x < falling_piece.getRotation(rotation)[y].size(); x++){

            if (falling_piece.getRotation(rotation)[y][x] == 1 || falling_piece.getRotation(rotation)[y][x] == 2){
                possible = (((y + position.second) < Options::getInstance()->getBoard_blocks_height())
                           && ((y + position.second) >= 0 )
                           && m_board[y + position.second][x + position.first] == 0);
            }

        }
    }

    return possible;
}

bool Board::isPossibleMovimentX(std::pair <int,int> position, Rotation rotation) {
    bool possible = true;

    for(int y = 0; possible && y < falling_piece.getRotation(rotation).size(); y++){
        for(int x = 0; possible && x < falling_piece.getRotation(rotation)[y].size(); x++){

            if (falling_piece.getRotation(rotation)[y][x] == 1 || falling_piece.getRotation(rotation)[y][x] == 2){
                possible = ((x + position.first) < Options::getInstance()->getBoard_blocks_width())
                           && ((x + position.first) >= 0 );
            }

        }
    }

    return possible;
}


Board::Board() {
    setFallingPiece(Piece());
}

void Board::fillBoard() {
    m_board = std::vector<std::vector<int> >((unsigned long) Options::getInstance()->getBoard_blocks_height(),
                                             std::vector<int>(
                                                     (unsigned long) Options::getInstance()->getBoard_blocks_width(), 0));

    m_board_colors = std::vector<std::vector<ColorName> >(
            (unsigned long) Options::getInstance()->getBoard_blocks_height(),
            std::vector<ColorName >((unsigned long) Options::getInstance()->getBoard_blocks_width(), ColorName::none));

    /**/std::cout << "[DEBUG]: (Board:fillBoard) Board created --> size = " <<  m_board.size() << " x " << m_board[0].size() << std::endl;//*/
    /**/debugPrintBoard();//*/
}

void Board::debugPrintBoard(){
    /**/std::cout << "[DEBUG]: (Board:debugPrintBoard) Showing board:" << std::endl;//*/
    /**/std::cout << std::endl << "-------------------------------------------" << std::endl;//*/
    for (int i = 0; i < m_board.size(); i++){
        for (int j = 0; j < m_board[i].size(); j++){
            std::cout << m_board[i][j] << " ";
        }
        std::cout << std::endl;
    }
    /**/std::cout << "-------------------------------------------" << std::endl << std::endl;//*/
}

int Board::getBoardPosition(int x, int y) const {
    return m_board[x][y];
}

ColorName Board::getColorPosition(int x, int y) const {
    return m_board_colors[x][y];
}

const Piece &Board::getFalling_piece() const {
    return falling_piece;
}

void Board::rotateFallingPiece() {
    if (isPossibleMoviment(falling_piece.getCurrent_position_matrix(), falling_piece.nextRotationRight()))
        falling_piece.rotateRight();
    /*falling_piece.debugMatrix();//*/
}

void Board::refreshFallingPiece() {
    notifyObservers(NotifyCode::falling_piece_changed, falling_piece);
}

void Board::moveFallingPieceToRight() {
    if (isPossibleMoviment(falling_piece.nextPositionRight(), falling_piece.getRotation()))
        falling_piece.moveToRight();
}

void Board::moveFallingPieceToLeft() {
    if (isPossibleMoviment(falling_piece.nextPositionLeft(), falling_piece.getRotation()))
        falling_piece.moveToLeft();
}

void Board::moveFallingPieceDown() {
    if (isPossibleMoviment(falling_piece.nextPositionDown(), falling_piece.getRotation()))
        falling_piece.fall();
    else
        requestNewPiece();
}

void Board::requestNewPiece() {

    for(int y = 0; y < falling_piece.getPieceBlocks().size(); y++){
        for(int x = 0; x < falling_piece.getPieceBlocks()[y].size(); x++){
            if (falling_piece.getPieceBlocks()[y][x] == 1 || falling_piece.getPieceBlocks()[y][x] == 2){
                m_board[y + falling_piece.getCurrent_position_matrix().second][x + falling_piece.getCurrent_position_matrix().first] = 1;
                m_board_colors[y + falling_piece.getCurrent_position_matrix().second][x + falling_piece.getCurrent_position_matrix().first] = falling_piece.getColor();
            }
        }
    }

    notifyObserversLine(NotifyCode::up_score_piece);

    debugPrintBoard();
    checkLines();

    notifyObserversLine(NotifyCode::prepare_next_piece);
}

