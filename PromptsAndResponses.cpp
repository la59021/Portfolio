#include <iostream>
//#include "Board.hpp"
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

Responses::Responses() {

}

void Responses::printBoard(Board newBoard) {
    board = newBoard;
    string row1 = "_| A | B | C |_";
    string row2 = "1| " + statusToMark(1) + " | " + statusToMark(2) + " | " +statusToMark(3) + " |_";
    string row3 = "2| " + statusToMark(4) + " | " + statusToMark(5) + " | " +statusToMark(6) + " |_";
    string row4 = "3| " + statusToMark(7) + " | " + statusToMark(8) + " | " +statusToMark(9) + " |_";
    cout << row1 << endl << row2 << endl << row3 << endl << row4 << endl << endl;
}

void Responses::isInvalidSpace() {
    cout << "The entered space was invalid" << endl;
}

void Responses::winnerIsX() {
    cout << "X is the winner!" << endl;
}

void Responses::winnerIsO() {
    cout << "O is the winner!" << endl;
}

void Responses::gameWasTie() {
    cout << "The game was a tie!" << endl;
}

string Responses::statusToMark(int index) {
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

