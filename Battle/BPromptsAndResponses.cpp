#include "BPromptsAndResponses.hpp"
using namespace std;

BPrompts::BPrompts() {
    //ctor
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