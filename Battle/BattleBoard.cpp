#include "BattleBoard.hpp"
using namespace std;

BattleBoard::BattleBoard() {

}

int BattleBoard::get_space_status(int index) {
    return currentBoard[index-1].getStatus();
}

void BattleBoard::set_space_status(int index, int newState) {
    currentBoard[index-1].setStatus(newState);
}

int BattleBoard::get_length() {
    return sizeof(currentBoard) / sizeof(currentBoard[0]);
}

bool BattleBoard::unfilled_spaces() {
    for (int x = 0; x < 9; x++) {
        if (currentBoard[x].getStatus() != 0) {
            return false;
        }
    }
    return true;
}

int BattleBoard::change_to_index(char rowChar, char colChar) {
    int index;
    if (rowChar == '1') {
        index = 1;
    }
    else if (rowChar == '2') {
        index = 4;
    }
    else {
        index = 7;
    }

    if (colChar == 'A' || colChar == 'a') {
        index += 0;
    }
    else if (colChar == 'B' || colChar == 'b') {
        index += 1;
    }
    else if (colChar == 'C' || colChar == 'c') {
        index += 2;
    }
    return index;
}

bool BattleBoard::valid_inputs(char rowChar, char colChar) {
    array <char, 6> colRange = {'A', 'B', 'C', 'a', 'b', 'c'};
    array <char, 3> rowRange = {'1', '2', '3'};
    for (int i = 0; i < rowRange.size() ; i++) {
        if (rowChar == rowRange[i]) {
            for (int x = 0; x < colRange.size(); x++) {
                if (colChar == colRange[x]) {
                    return true;
                }
            }
        }
    }
    return false;
}

bool BattleBoard::empty_space(int index) {
    if (get_space_status(index) == 0) {
        return true;
    }
    return false;
}