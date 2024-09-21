#include <iostream>
#include <array>
//#include "Space.hpp"
#include "Board.hpp"
using namespace std;

Board::Board() {

}

int Board::getSpaceStatus(int index) {
    return currentBoard[index-1].getStatus();
}

void Board::setSpaceStatus(int index, int newState) {
    currentBoard[index-1].setStatus(newState);
}
