#include "BSpace.hpp"
#include "BBoard.hpp"
using namespace std;

BBoard::BBoard() {
    for (unsigned i = 0; i < sizeof(currentBoard); i++) {
        currentBoard[i] = BSpace();
    }
}

int BBoard::getLength() {
    return sizeof(currentBoard) / sizeof(currentBoard[0]);
}

int BBoard::getSpaceStatus(int index) {
    return currentBoard[index-1].getStatus();
}

void BBoard::setSpaceStatus(int index, int newState) {
    currentBoard[index-1].setStatus(newState);
}