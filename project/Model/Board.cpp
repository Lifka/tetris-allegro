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
    notifyObservers(NotifyCode::falling_piece, falling_piece);
    /**/std::cout << "[DEBUG]: (Board:setFallingPiece) New falling piece setted --> Type = " << falling_piece.getPieceType() << std::endl;
}

void Board::initBoard() {
    /**/std::cout << "[DEBUG]: (Board:initBoard) Starting board..." << std::endl;
    fillBoard();
}

bool Board::isGameOver() {
    return false; // TODO
}

bool Board::isPossibleMoviment(Point2D, Rotation) {
    return false; // TODO
}

Board::Board() {
    setFallingPiece(Piece());
}

void Board::fillBoard() {
    m_board = std::vector<std::vector<int> >(Options::getInstance()->getBoard_blocks_height(),
                                             std::vector<int>(Options::getInstance()->getBoard_blocks_width(),0));

    /**/std::cout << "[DEBUG]: (Board:fillBoard) Board created --> size = " <<  m_board.size() << " x " << m_board[0].size() << std::endl;
    /**/debugPrintBoard();
}


std::vector<std::vector<int> > Board::getBoardMatrix(){
    return m_board;
}

void Board::debugPrintBoard(){
    /**/std::cout << "[DEBUG]: (Board:debugPrintBoard) Showing board:" << std::endl;
    /**/std::cout << std::endl << "-------------------------------------------" << std::endl;
    for (int i = 0; i < m_board.size(); i++){
        for (int j = 0; j < m_board[i].size(); j++){
            std::cout << m_board[i][j] << " ";
        }
        std::cout << std::endl;
    }
    /**/std::cout << "-------------------------------------------" << std::endl << std::endl;
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

