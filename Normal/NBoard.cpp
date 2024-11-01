#include "NBoard.hpp"
using namespace std;

NBoard::NBoard() {

}

int NBoard::getLength() {
    return sizeof(currentBoard) / sizeof(currentBoard[0]);
}

int NBoard::getSpaceStatus(int index) {
    return currentBoard[index-1].getStatus();
}

void NBoard::setSpaceStatus(int index, int newState) {
    currentBoard[index-1].setStatus(newState);
}