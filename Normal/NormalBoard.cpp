#include "NormalBoard.hpp"
using namespace std;

NormalBoard::NormalBoard() {

}

int NormalBoard::getSpaceStatus(int index) {
    return currentBoard[index-1].getStatus();
}

void NormalBoard::setSpaceStatus(int index, int newState) {
    currentBoard[index-1].setStatus(newState);
}

int NormalBoard::getLength() {
    return sizeof(currentBoard) / sizeof(currentBoard[0]);
}

