#include "NormalResponses.hpp"
using namespace std;

NormalResponses::NormalResponses() {

}

void NormalResponses::printBoard(NormalBoard newBoard) {
    board = newBoard;
    string row1 = "_| A | B | C |_";
    string row2 = "1| " + statusToMark(1) + " | " + statusToMark(2) + " | " +statusToMark(3) + " |_";
    string row3 = "2| " + statusToMark(4) + " | " + statusToMark(5) + " | " +statusToMark(6) + " |_";
    string row4 = "3| " + statusToMark(7) + " | " + statusToMark(8) + " | " +statusToMark(9) + " |_";
    cout << row1 << endl << row2 << endl << row3 << endl << row4 << endl << endl;
}

void NormalResponses::isInvalidSpace() {
    cout << "The entered space was invalid" << endl;
}

void NormalResponses::winnerIsX() {
    cout << "X is the winner!" << endl;
}

void NormalResponses::winnerIsO() {
    cout << "O is the winner!" << endl;
}

void NormalResponses::gameWasTie() {
    cout << "The game was a tie!" << endl;
}

string NormalResponses::statusToMark(int index) {
    if (board.getSpaceStatus(index) == 0) {
        return " ";
    }
    if (board.getSpaceStatus(index) == 1) {
        return "X";
    }
    if (board.getSpaceStatus(index) == 2) {
        return "O";
    }
}

