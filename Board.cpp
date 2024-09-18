#include <iostream>
#include <array>
//#include "Space.hpp"
#include "Board.hpp"
using namespace std;

Board::Board() {

}

int Board::getSpaceStatus(int row, int col) {
    return currentBoard[row][col].getStatus();
}

void Board::setSpaceStatus(int row, int col, int newState) {
    currentBoard[row][col].setStatus(newState);
}
