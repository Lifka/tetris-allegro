//
// Created by lifka on 18/06/17.
//

#include "Board.h"
#include "Options.h"

void Board::deleteLine(int n_line) {
    for(int x = n_line+1; x < m_board.size(); x++)
        m_board[x-1] = m_board[x];
    // full last line except
    m_board[m_board.size()-1] = std::vector<int>(m_board[m_board.size()-1].size(), 0);

}

Board* Board::getInstance() {
    if (!instance){
        new Board();
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
}

void Board::initBoard(Piece first_piece) {
    setFallingPiece(first_piece);
    m_board = std::vector<std::vector<int> >(Options::getInstance()->getBoard_blocks_height(),
                                             std::vector<int>(Options::getInstance()->getBoard_blocks_width(),0));
}

bool Board::isGameOver() {
    return false; // TODO
}

bool Board::isPossibleMoviment(Point2D, Rotation) {
    return false; // TODO
}

