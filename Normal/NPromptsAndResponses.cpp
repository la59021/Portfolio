#include "NPromptsAndResponses.hpp"
using namespace std;

NPrompts::NPrompts() {
    //ctor
}

void NPrompts::askForXSpace() {
    cout << "It is X's Turn. Please enter the Desired space. \nUse the format row col:" << endl;
}

void NPrompts::askForOSpace() {
    cout << "It is O's Turn. Please enter the Desired space. \nUse the format row col:" << endl;
}

void NPrompts::askToPlayAgain() {
    cout << "Would you like to play Again? Y/N:" << endl;
}

NResponses::NResponses(NBoard *board) {
    this->board = board;
}

void NResponses::printBoard() {
    cout << "  |  A  |  B  |  C  |  " << "\n";
    cout << "--|-----|-----|-----|--" << "\n";
    cout << "1 |  " << statusToMark(1) << "  |  " + statusToMark(2) << "  |  " +statusToMark(3) << "  |  " << "\n";
    cout << "--|-----|-----|-----|--" << "\n";
    cout << "2 |  " << statusToMark(4) << "  |  " + statusToMark(5) << "  |  " +statusToMark(6) << "  |  " << "\n";
    cout << "--|-----|-----|-----|--" << "\n";
    cout << "3 |  " << statusToMark(7) << "  |  " + statusToMark(8) << "  |  " +statusToMark(9) << "  |  " << "\n";
}

void NResponses::isInvalidSpace() {
    cout << "The entered space was invalid" << endl;
}

void NResponses::winnerIsX() {
    printBoard();
    cout << "X is the winner!" << endl;
}

void NResponses::winnerIsO() {
    printBoard();
    cout << "O is the winner!" << endl;
}

void NResponses::gameWasTie() {
    cout << "The game was a tie!" << endl;
}

string NResponses::statusToMark(int index) {
    if (board->getSpaceStatus(index) == 0) {
        return " ";
    }
    if (board->getSpaceStatus(index) == 1) {
        return "X";
    }
    if (board->getSpaceStatus(index) == 2) {
        return "O";
    }
    return "-1";
}