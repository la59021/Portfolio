#include "BSpace.hpp"
#include "BBoard.hpp"
using namespace std;

BBoard::BBoard() {
}

int BBoard::getLength() {
    return sizeof(currentBoard) / sizeof(currentBoard[0]);
}

int BBoard::getSpaceStatus(int index) {
    return currentBoard[index].getStatus();
}

void BBoard::setSpaceStatus(int index, int newState) {
    currentBoard[index].setStatus(newState);
}