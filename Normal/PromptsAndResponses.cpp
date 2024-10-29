#include "PromptsAndResponses.hpp"
using namespace std;

Prompts::Prompts() {
    //ctor
}

void Prompts::askForXSpace() {
    cout << "It is X's Turn. Please enter the Desired space. \nUse the format row col:" << endl;
}

void Prompts::askForOSpace() {
    cout << "It is O's Turn. Please enter the Desired space. \nUse the format row col:" << endl;
}

void Prompts::askToPlayAgain() {
    cout << "Would you like to play Again? Y/N:" << endl;
}

Responses::Responses(Board *board) {
    this->board = board;
}

void Responses::printBoard() {
    cout << "  |  A  |  B  |  C  |  " << endl;
    cout << "--|-----|-----|-----|--" << endl;
    cout << "1 |  " << statusToMark(1) << "  |  " + statusToMark(2) << "  |  " +statusToMark(3) << "  |  " << endl;
    cout << "--|-----|-----|-----|--" << endl;
    cout << "2 |  " << statusToMark(4) << "  |  " + statusToMark(5) << "  |  " +statusToMark(6) << "  |  " << endl;
    cout << "--|-----|-----|-----|--" << endl;
    cout << "3 |  " << statusToMark(7) << "  |  " + statusToMark(8) << "  |  " +statusToMark(9) << "  |  " << endl;
}

void Responses::isInvalidSpace() {
    cout << "The entered space was invalid" << endl;
}

void Responses::winnerIsX() {
    printBoard();
    cout << "X is the winner!" << endl;
}

void Responses::winnerIsO() {
    printBoard();
    cout << "O is the winner!" << endl;
}

void Responses::gameWasTie() {
    cout << "The game was a tie!" << endl;
}

string Responses::statusToMark(int index) {
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