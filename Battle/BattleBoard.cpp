#include "BattleBoard.hpp"
using namespace std;

BattleBoard::BattleBoard() {

}

int BattleBoard::getSpaceStatus(int index) {
    return currentBoard[index-1].getStatus();
}

void BattleBoard::setSpaceStatus(int index, int newState) {
    currentBoard[index-1].setStatus(newState);
}

int BattleBoard::getLength() {
    return sizeof(currentBoard) / sizeof(currentBoard[0]);
}

