#include "../Terminate.cpp"
#include <array>
#include <iostream>
#include "NRules.hpp"
using namespace std;

NRules::NRules() {
    index = 10;
}

bool NRules::checkForTie() {
    bool allFull = true;
    for (int i = 1; i <= board.getLength(); i++) {
        if (board.getSpaceStatus(i) == 0) {
            allFull = false;
        }
    }
    if (allFull && checkForWin(true) == "" && checkForWin(false) == "") {
        responses.printBoard();
        responses.gameWasTie();
        return true;
    }
    return false;
}

bool NRules::followsRules() {
    if (inputIsInRange()) {
        changeToIndex();
        if (spaceIsOpen()) {
           return true;
        }
    }
    return false;
}

int NRules::wasThereAWinner() {
    if (checkForTie) {
        return 3;
    }
    else if (checkForWin(false) != "") {
        return 2;
    }
    else if (checkForWin(true) != "") {
        return 1;
    }
    return 0;
}

void NRules::takeXTurn() {
    index = 10;
    rowChar = 'R';
    colChar = 'C';
    if (wasThereAWinner() == (1 || 2 || 3)) {
        goto leave;
    }
    else {
        goto start;
    }
    start:
        responses.printBoard();
        prompts.askForXSpace();
        cin >> rowChar;
        if (rowChar == 'q' || rowChar == 'Q') {
            throw stop_now_t();
        }
        cin >> colChar;
        if (colChar == 'q' || colChar == 'Q') {
            throw stop_now_t();
        }
        cout << endl;
        goto checkValidity;

    checkValidity:
        if ((followsRules())) {
            changeToIndex();
            goto valid;
        }
        else {
            cout << "The entered space was invalid" << endl;
            cout << "Try Again" << endl;
            goto start;

        }

    valid:
        board.setSpaceStatus(index, 1);
        if (wasThereAWinner() == 1) {
            responses.winnerIsX();
            cout << checkForWin(true) << endl;
        }

    leave:
    index = 10; // just to get the compiler to shutup about the label at the end
}

void NRules::takeOTurn() {
    index = 10;
    rowChar = 'R';
    colChar = 'C';
    if (wasThereAWinner() == (1 || 2 || 3)) {
        goto leave;
    }
    else {
        goto start;
    }
    start:
        responses.printBoard();
        prompts.askForOSpace();
        cin >> rowChar;
        if (rowChar == 'q' || rowChar == 'Q') {
            throw stop_now_t();
        }
        cin >> colChar;
        if (colChar == 'q' || colChar == 'Q') {
            throw stop_now_t();
        }
        cout << endl;
        goto checkValidity;

    checkValidity:
        if ((followsRules())) {
            changeToIndex();
            goto valid;
        }
        else {
            cout << "The entered space was invalid" << endl;
            cout << "Try Again" << endl;
            goto start;

        }

    valid:
        board.setSpaceStatus(index, 2);
        if (wasThereAWinner() == 2) {
            responses.winnerIsO();
            cout << checkForWin(false) << endl;
        }

    leave:
    index = 10; // just to get the compiler to shutup about the label at the end
}

bool NRules::inputIsInRange() {
    array<char, 6> colRange = {'A', 'B', 'C', 'a', 'b', 'c'};
    array<char, 3> rowRange = {'1', '2', '3'};
    for (unsigned i = 0; i < rowRange.size(); i++) {
        if (rowChar == rowRange[i]) {
            for (unsigned x = 0; x < colRange.size(); x++) {
                if (colChar == colRange[x]) {
                    return true;
                }
            }
        }
    }
    return false;
}

bool NRules::spaceIsOpen() {
    if (board.getSpaceStatus(index) == 0) {
        return true;
    }
    return false;
}

string NRules::checkForWin(bool checkingX) {
    string reply = "";
    int toCheck = 2;
    if (checkingX) {
        toCheck = 1;
    }
    if (board.getSpaceStatus(1) == toCheck) {
        if (board.getSpaceStatus(2) == toCheck) {
            if (board.getSpaceStatus(3) == toCheck) {
                reply = "The Winning combo was (1, A), (1, B), (1, C).";
            }
        }
        if (board.getSpaceStatus(4) == toCheck) {
            if (board.getSpaceStatus(7) == toCheck) {
                reply = "The Winning combo was (1, A), (2, A), (3, A).";
            }
        }
        if (board.getSpaceStatus(5) == toCheck) {
            if (board.getSpaceStatus(9) == toCheck) {
                reply = "The Winning combo was (1, A), (2, B), (3, C).";
            }
        }
    }
    if (board.getSpaceStatus(2) == toCheck) {
        if (board.getSpaceStatus(5) == toCheck) {
            if (board.getSpaceStatus(8) == toCheck) {
                reply = "The Winning combo was (1, B), (2, B), (3, B).";
            }
        }
    }
    if (board.getSpaceStatus(3) == toCheck) {
        if (board.getSpaceStatus(5) == toCheck) {
            if (board.getSpaceStatus(7) == toCheck) {
                reply = "The Winning combo was (1, C), (2, B), (3, A).";
            }
        }
        if (board.getSpaceStatus(6) == toCheck) {
            if (board.getSpaceStatus(9) == toCheck) {
                reply = "The Winning combo was (1, C), (2, C), (3, C).";
            }
        }
    }
    if (board.getSpaceStatus(4) == toCheck) {
        if (board.getSpaceStatus(5) == toCheck) {
            if (board.getSpaceStatus(6) == toCheck) {
                reply = "The Winning combo was (2, A), (2, B), (2, C).";
            }
        }
    }
    if (board.getSpaceStatus(7) == toCheck) {
        if (board.getSpaceStatus(8) == toCheck) {
            if (board.getSpaceStatus(9) == toCheck) {
                reply = "The Winning combo was (3, A), (3, B), (3, C).";
            }
        }
    }
    return reply;
}

void NRules::changeToIndex() {
    if (rowChar == '1') {
        index = 1;
    }
    else if (rowChar == '2') {
        index = 4;
    }
    else {
        index = 7;
    }

    if (colChar == 'A' || colChar == 'a') {
        index += 0;
    }
    else if (colChar == 'B' || colChar == 'b') {
        index += 1;
    }
    else if (colChar == 'C' || colChar == 'c') {
        index += 2;
    }
}