#include "BBoard.hpp"
using namespace std;

BBoard::BBoard() {

}

int BBoard::getSpaceStatus(int index) {
    return currentBoard[index-1].getStatus();
}

void BBoard::setSpaceStatus(int index, int newState) {
    currentBoard[index-1].setStatus(newState);
}

int BBoard::getLength() {
    return sizeof(currentBoard) / sizeof(currentBoard[0]);
}