//
// Created by lifka on 18/06/17.
//

#include "Board.h"
#include "Options.h"

#define wall 1

Board* Board::instance = nullptr;

void Board::deleteLine(int n_line) {
    for(int x = n_line+1; x < m_board.size(); x++)
        m_board[x-1] = m_board[x];
    // full last line except
    m_board[m_board.size()-1] = std::vector<int>(m_board[m_board.size()-1].size(), 0);

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
}

void Board::initBoard(Piece first_piece) {
    setFallingPiece(first_piece);
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

    unsigned long game_width = Options::getInstance()->getGame_width();
    unsigned long wall_width = Options::getInstance()->getWalls_width();

    int up = 0;

    for (int i = 0; i < m_board.size(); i++){

        up++;

        for(int j = 0; j < m_board.size(); j++){

            if (j < wall_width) // Pared derecha
                m_board[i][j] = wall;

            if ((m_board.size() - j) < wall_width) // Pared izquierda
                m_board[i][j] = wall;

            if (up < wall_width) // Superior
                m_board[i][j] = wall;

            if ((m_board.size() - up) < wall_width) // Inferior
                m_board[i][j] = wall;

            if (j >= game_width && (game_width + wall_width) < j) // Game
                m_board[i][j] = wall;

        }
    }
}


std::vector<std::vector<int> > Board::getBoardMatrix(){
    return m_board;
}



