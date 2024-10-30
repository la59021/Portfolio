#include "BPromptsAndResponses.hpp"
using namespace std;

BPrompts::BPrompts() {
    //ctor
}

void BPrompts::askForXSpace() {
    cout << "It is X's Turn. Please enter the Desired space. \nUse the format row col:" << endl;
}

void BPrompts::askForOSpace() {
    cout << "It is O's Turn. Please enter the Desired space. \nUse the format row col:" << endl;
}

void BPrompts::askToPlayAgain() {
    cout << "Would you like to play Again? Y/N:" << endl;
}

BResponses::BResponses(BBoard *board) {
    this->board = board;
}

void BResponses::printBoard() {
    cout << "  |  A  |  B  |  C  |  " << endl;
    cout << "--|-----|-----|-----|--" << endl;
    cout << "1 |  " << statusToMark(1) << "  |  " + statusToMark(2) << "  |  " +statusToMark(3) << "  |  " << endl;
    cout << "--|-----|-----|-----|--" << endl;
    cout << "2 |  " << statusToMark(4) << "  |  " + statusToMark(5) << "  |  " +statusToMark(6) << "  |  " << endl;
    cout << "--|-----|-----|-----|--" << endl;
    cout << "3 |  " << statusToMark(7) << "  |  " + statusToMark(8) << "  |  " +statusToMark(9) << "  |  " << endl;
}

void BResponses::isInvalidSpace() {
    cout << "The entered space was invalid" << endl;
}

void BResponses::winnerIsX() {
    printBoard();
    cout << "X is the winner!" << endl;
}

void BResponses::winnerIsO() {
    printBoard();
    cout << "O is the winner!" << endl;
}

void BResponses::gameWasTie() {
    cout << "The game was a tie!" << endl;
}

string BResponses::statusToMark(int index) {
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