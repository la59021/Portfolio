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


void BResponses::isInvalidSpace() {
    cout << "The entered space was invalid" << endl;
}

void BResponses::winnerIsX() {
    cout << "X is the winner!" << endl;
}

void BResponses::winnerIsO() {
    cout << "O is the winner!" << endl;
}

void BResponses::gameWasTie() {
    cout << "The game was a tie!" << endl;
}