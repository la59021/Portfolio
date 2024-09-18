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

Responses::Responses() {

}

void Responses::isInvalidSpace() {
    cout << "The entered space was invalid" << endl;
}

string Responses::statusToMark(int row, int col) {
    if (board.getSpaceStatus(row, col) == 0) {
        return " ";
    }
    if (board.getSpaceStatus(row, col) == 1) {
        return "X";
    }
    if (board.getSpaceStatus(row, col) == 2) {
        return "O";
    }
}

void Responses::printBoard(Board newBoard) {
    board = newBoard;
    string row1 = "_| 1 | 2 | 3 |_";
    string row2 = "1| " + statusToMark(0, 0) + " | " + statusToMark(0, 1) + " | " +statusToMark(0, 2) + " |_";
    string row3 = "2| " + statusToMark(1, 0) + " | " + statusToMark(1, 1) + " | " +statusToMark(1, 2) + " |_";
    string row4 = "3| " + statusToMark(2, 0) + " | " + statusToMark(2, 1) + " | " +statusToMark(2, 2) + " |_";
    cout << row1 << endl << row2 << endl << row3 << endl << row4 << endl;
}

void Responses::winnerIsX() {
    cout << "X is the winner!" << endl;
}

void Responses::winnerIsO() {
    cout << "O is the winner!" << endl;
}
