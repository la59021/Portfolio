#include <iostream>
#include "PromptsAndResponses.hpp"
#include "Board.hpp"
#include "Rules.hpp"
using namespace std;

Rules::Rules() {
    responses.printBoard(board);
}

void Rules::takeXTurn() {
    if (checkForWin(true) || checkForWin(false)) {
        won = true;
    }
    if (!checkForWin(true) && !checkForWin(false) && !won) {
        goto start;
    }
    else {
        goto leave;
    }
    start:
        prompts.askForXSpace();
        int row, col;
        cin >> row;
        cin >> col;
        row -= 1;
        col -= 1;
        goto checkValidity;

    checkValidity:
        if (!(this -> followsRules(0, false, row, col))) {
            responses.isInvalidSpace();
            responses.printBoard(board);
            goto start;
        }
        else {
            goto valid;
        }

    valid:
        board.setSpaceStatus(row, col, 1);
        if (followsRules(1, true, 0, 0)) {
            responses.winnerIsX();
        }
        else {
            responses.printBoard(board);
        }
    leave:

}

void Rules::takeOTurn() {
    if (checkForWin(true) || checkForWin(false)) {
        won = true;
    }
    if (!checkForWin(true) && !checkForWin(false)&& !won) {
        goto start;
    }
    else {
        goto leave;
    }
    start:
        prompts.askForOSpace();
        int row, col;
        cin >> row;
        cin >> col;
        row -= 1;
        col -= 1;
        goto checkValidity;

    checkValidity:
        if (!(followsRules(0, false, row, col))) {
            responses.isInvalidSpace();
            responses.printBoard(board);
            goto start;
        }
        else {
            goto valid;
        }

    valid:
        board.setSpaceStatus(row, col, 2);
        if (followsRules(1, false, 0, 0)) {
            responses.winnerIsO();
        }
        else {
            responses.printBoard(board);
        }
    leave:

}

bool Rules::followsRules(int typeOfCheck, bool lookingAtX, int row, int col) {
    if (typeOfCheck == 0) {
        if (inputIsInRange(row, col) && spaceIsOpen(row, col)){
            return true;
        }
    }
    else if (typeOfCheck == 0 && lookingAtX) { // checking for x win
        if (checkForWin(true)) {
            return true;
        }
    }
    else if (typeOfCheck == 1 && !lookingAtX) { // checking for o win
        if (checkForWin(false)) {
            return true;
        }
    }
    else if (typeOfCheck == 2) {
        if (checkForTie()) {
            return true;
        }
    }
    return false;
}

bool Rules::inputIsInRange(int row, int col) {
    if (row < 3 && row > -1 && col < 3 && col > -1) {
        return true;
    }
    return false;
}

bool Rules::spaceIsOpen(int row, int col) {
    if (board.getSpaceStatus(row, col) == 0) {
        return true;
    }
    return false;
}

bool Rules::checkForWin(bool checkingX) {
    if (checkingX) {
        if (board.getSpaceStatus(0, 0) == 1 && board.getSpaceStatus(1, 1) == 1 && board.getSpaceStatus(2, 2) == 1) {
            responses.winnerIsX();
            cout << "The Winning combo was (1,1), (2,2), (3,3)." << endl;
            return true;
        }
        if (board.getSpaceStatus(0, 2) == 1 && board.getSpaceStatus(1, 1) == 1 && board.getSpaceStatus(2, 0) == 1) {
            responses.winnerIsX();
            cout << "The Winning combo was (1,3), (2,2), (3,0)." << endl;
            return true;
        }
        if (board.getSpaceStatus(0, 0) == 1 && board.getSpaceStatus(1, 0) == 1 && board.getSpaceStatus(2, 0) == 1) {
            responses.winnerIsX();
            cout << "The Winning combo was (1,1), (2,1), (3,1)." << endl;
            return true;
        }
        if (board.getSpaceStatus(0, 1) == 1 && board.getSpaceStatus(1, 1) == 1 && board.getSpaceStatus(2, 1) == 1) {
            responses.winnerIsX();
            cout << "The Winning combo was (1,2), (2,2), (3,2)." << endl;
            return true;
        }
        if (board.getSpaceStatus(0, 2) == 1 && board.getSpaceStatus(1, 2) == 1 && board.getSpaceStatus(2, 2) == 1) {
            responses.winnerIsX();
            cout << "The Winning combo was (1,3), (2,3), (3,3)." << endl;
            return true;
        }
        if (board.getSpaceStatus(0, 0) == 1 && board.getSpaceStatus(0, 1) == 1 && board.getSpaceStatus(0, 2) == 1) {
            responses.winnerIsX();
            cout << "The Winning combo was (1,1), (1,2), (1,3)." << endl;
            return true;
        }
        if (board.getSpaceStatus(1, 0) == 1 && board.getSpaceStatus(1, 1) == 1 && board.getSpaceStatus(1, 2) == 1) {
            responses.winnerIsX();
            cout << "The Winning combo was (2,1), (2,2), (2,3)." << endl;
            return true;
        }
        if (board.getSpaceStatus(2, 0) == 1 && board.getSpaceStatus(2, 1) == 1 && board.getSpaceStatus(2, 2) == 1) {
            responses.winnerIsX();
            cout << "The Winning combo was (3,1), (3,2), (3,3)." << endl;
            return true;
        }
        return false;
    }
    if (!checkingX) {
        if (board.getSpaceStatus(0, 0) == 2 && board.getSpaceStatus(1, 1) == 2 && board.getSpaceStatus(2, 2) == 2) {
            responses.winnerIsO();
            cout << "The Winning combo was (1,1), (2,2), (3,3)." << endl;
            return true;
        }
        if (board.getSpaceStatus(0, 2) == 2 && board.getSpaceStatus(1, 1) == 2 && board.getSpaceStatus(2, 0) == 2) {
            responses.winnerIsO();
            cout << "The Winning combo was (1,3), (2,2), (3,0)." << endl;
            return true;
        }
        if (board.getSpaceStatus(0, 0) == 2 && board.getSpaceStatus(1, 0) == 2 && board.getSpaceStatus(2, 0) == 2) {
            responses.winnerIsO();
            cout << "The Winning combo was (1,1), (2,1), (3,1)." << endl;
            return true;
        }
        if (board.getSpaceStatus(0, 1) == 2 && board.getSpaceStatus(1, 1) == 2 && board.getSpaceStatus(2, 1) == 2) {
            responses.winnerIsO();
            cout << "The Winning combo was (1,2), (2,2), (3,2)." << endl;
            return true;
        }
        if (board.getSpaceStatus(0, 2) == 2 && board.getSpaceStatus(1, 2) == 2 && board.getSpaceStatus(2, 2) == 2) {
            responses.winnerIsO();
            cout << "The Winning combo was (1,3), (2,3), (3,3)." << endl;
            return true;
        }
        if (board.getSpaceStatus(0, 0) == 2 && board.getSpaceStatus(0, 1) == 2 && board.getSpaceStatus(0, 2) == 2) {
            responses.winnerIsO();
            cout << "The Winning combo was (1,1), (1,2), (1,3)." << endl;
            return true;
        }
        if (board.getSpaceStatus(1, 0) == 2 && board.getSpaceStatus(1, 1) == 2 && board.getSpaceStatus(1, 2) == 2) {
            responses.winnerIsO();
            cout << "The Winning combo was (2,1), (2,2), (2,3)." << endl;
            return true;
        }
        if (board.getSpaceStatus(2, 0) == 2 && board.getSpaceStatus(2, 1) == 2 && board.getSpaceStatus(2, 2) == 2) {
            responses.winnerIsO();
            cout << "The Winning combo was (3,1), (3,2), (3,3)." << endl;
            return true;
        }
        return false;
    }
}

bool Rules::checkForTie() {
    if (checkForWin(true) || checkForWin(false)) {
        return false;
    }
    return true;
}
