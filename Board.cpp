#include <string>
#include <array>
#include "Board.hpp"
using namespace std;

int row;
int col;

GameBoard::GameBoard() {

}

bool GameBoard::pickedSpaceUnoccupied(int* cords) {
    int row = *cords, col = *cords+1;
    if (board[row][col] != "") {
        return false;
    }
    return true;
}

void GameBoard::addPiece(int* cords, string marker) {
    int row = *cords, col = *cords+1;
    cout << "row = " << row << endl;
    cout << "col = " << col << endl;
    board[row][col] = marker;
}

bool GameBoard::checkForWin() {

}

void GameBoard::printBoard() {
    string boardPrint[4];
    boardPrint[0] = " | A | B | C |";
    boardPrint[1] = "1| " + board[0][0] + " | " + board[0][1] + " | " + board[0][2] + " |";
    boardPrint[2] = "2| " + board[1][0] + " | " + board[1][1] + " | " + board[1][2] + " |";
    boardPrint[3] = "3| " + board[2][0] + " | " + board[2][1] + " | " + board[2][2] + " |";
    for (int i = 0; i < 4; i++) {
        cout << boardPrint[i] << endl;
    }
}
