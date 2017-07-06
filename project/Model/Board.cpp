//
// Created by lifka on 18/06/17.
//

#include <iostream>
#include "Board.h"
#include "Options.h"

#define wall 1
#define free 0

Board* Board::instance = nullptr;

void Board::deleteLine(int n_line) {
    for(int x = n_line+1; x < m_board.size(); x++)
        m_board[x-1] = m_board[x];
    // full last line except
    m_board[m_board.size()-1] = std::vector<int>(m_board[m_board.size()-1].size(), 0);

    // TODO ---



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

void Board::checkLines() {
    int index = 0;
    for (std::vector<std::vector<int> >::iterator itx = m_board.begin() ; itx != m_board.end(); ++itx, index++){
        bool delete_line = true;
        for (int y = 0; y < (*itx).size() && delete_line; y++){
            int value = (*itx)[y];
            delete_line = (value != 0);
        }
        if (delete_line)
            deleteLine(index);
    }
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
    return false; // TODO
}

bool Board::isPossibleMoviment(std::pair <int,int> position, Rotation rotation) {
    bool possible = isPossibleMovimentX(position, rotation);

    if (possible){
        if (!isPossibleMovimentY(position, rotation) ){
            possible = false;
            requestNewPiece();
        }
    }

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
    m_board = std::vector<std::vector<int> >(Options::getInstance()->getBoard_blocks_height(),
                                             std::vector<int>(Options::getInstance()->getBoard_blocks_width(),0));

    m_board_colors = std::vector<std::vector<ColorName> >(Options::getInstance()->getBoard_blocks_height(),
                                             std::vector<ColorName >(Options::getInstance()->getBoard_blocks_width(),ColorName::none));

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
}

void Board::requestNewPiece() {

    for(int y = 0; y < falling_piece.getPieceBlocks().size(); y++){
        for(int x = 0; x < falling_piece.getPieceBlocks()[y].size(); x++){
            if (falling_piece.getPieceBlocks()[y][x] == 1 || falling_piece.getPieceBlocks()[y][x] == 2){

                std::cout << "[" <<y + falling_piece.getCurrent_position_matrix().second <<
                          "," << x + falling_piece.getCurrent_position_matrix().first << "]" << std::endl << std::endl;

                m_board[y + falling_piece.getCurrent_position_matrix().second][x + falling_piece.getCurrent_position_matrix().first] = 1;
                m_board_colors[y + falling_piece.getCurrent_position_matrix().second][x + falling_piece.getCurrent_position_matrix().first] = falling_piece.getColor();
            }
        }
    }


    Board::getInstance()->debugPrintBoard();


    notifyObserversLine(NotifyCode::next_piece);
}

