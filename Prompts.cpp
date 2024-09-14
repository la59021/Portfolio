#include <iostream>
#include <cstring>
#include "Board.hpp"
#include "Prompts.hpp"
using namespace std;

GameBoard board;

int* Prompts::changeToArrray (string pickedSpace) {
    int cords[2];
    if (pickedSpace[0] == 'A'){
        cords[1] = 0;
    }
    if (pickedSpace[0] == 'B'){
        cords[1] = 1;
    }
    if (pickedSpace[0] == 'C'){
        cords[1] = 2;
    }
    cords[0] = pickedSpace[1];
    int* cordsPointer = cords;
    cout << cordsPointer << ", " << *cordsPointer+1 << endl;
    return cordsPointer;
}

bool Prompts::inputInRange(string pickedSpace) {
    bool possibleSpot = false;
    string spaces[9] = {"A1","A2","A3","B1","B2","B3","C1","C2","C3"};
    for (int i = 0; i < 9; i++) {
        if (pickedSpace == spaces[i]) {
                possibleSpot = true;
        }
    }
    int* cords = changeToArrray(pickedSpace);
    if (!board.pickedSpaceUnoccupied(cords)) {
        possibleSpot = false;
    }
    return possibleSpot;
}

string Prompts::promptToPickSpace() {
    cout << "Pick a Space" << endl;
    string pickedSpace = "";
    cin >> pickedSpace;

    while (!inputInRange(pickedSpace)) {
        cout << "invalid space. Pick again" << endl;
        cin >> pickedSpace;
    }
    return pickedSpace;
}

void Prompts::takeTurn(bool isOsTurn) {
    int col = 0;
    if (!isOsTurn) {
        cout << "X's turn." << endl;
    }
    else {
        cout << "O's turn." << endl;
    }
    string pickedSpace = "";
    pickedSpace = promptToPickSpace();

    int* cords = changeToArrray(pickedSpace);

    if (!isOsTurn) {
        board.addPiece(cords, "X");
    }
    else {
        board.addPiece(cords, "O");
    }
    board.printBoard();

}


Prompts::Prompts(bool xStarts) {
    GameBoard board;
    if (xStarts) {
        isXsTurn = true;
    }
    else {
        isXsTurn = false;
    }
}


