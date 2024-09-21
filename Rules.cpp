#include "Rules.hpp"
using namespace std;

Rules::Rules() {
    index = 10;
}

bool Rules::followsRules() {
    if (inputIsInRange()) {
        changeToIndex();
        if (spaceIsOpen()) {
           return true;
        }
    }
    return false;
}

bool Rules::wasThereAWinner() {
    return won;
}

void Rules::takeXTurn() {
    index = 10;
    rowChar = 'R';
    colChar = 'C';
    if (checkForWin(true) != "" || checkForWin(false) != "") {
        won = true;
    }
    if (checkForWin(true) == "" && checkForWin(false) == "") {
        goto start;
    }
    else {
        goto leave;
    }
    start:
        responses.printBoard(board);
        prompts.askForXSpace();
        cin >> rowChar;
        cin >> colChar;
        cout << endl;
        goto checkValidity;

    checkValidity:
        if ((followsRules())) {
            changeToIndex();
            goto valid;
        }
        else {
            responses.isInvalidSpace();
            responses.printBoard(board);
            goto start;

        }

    valid:
        board.setSpaceStatus(index, 1);
        if (!won && checkForWin(true) != "") {
            responses.winnerIsX();
            cout << checkForWin(true) << endl;
            won = true;
        }
        else {
        }

    leave:
}

void Rules::takeOTurn() {
    index = 10;
    rowChar = 'R';
    colChar = 'C';
    if (checkForWin(true) != "" || checkForWin(false) != "") {
        won = true;
    }
    if (checkForWin(true) == "" && checkForWin(false) == "") {
        goto start;
    }
    else {
        goto leave;
    }
    start:
        responses.printBoard(board);
        prompts.askForOSpace();
        cin >> rowChar;
        cin >> colChar;
        cout << endl;
        goto checkValidity;

    checkValidity:
        if ((followsRules())) {
            changeToIndex();
            goto valid;
        }
        else {
            responses.isInvalidSpace();
            responses.printBoard(board);
            goto start;

        }

    valid:
        board.setSpaceStatus(index, 2);
        if (!won && checkForWin(false) != "") {
            responses.winnerIsO();
            cout << checkForWin(false) << endl;
            won = true;
        }
        else {
        }
    leave:

}

bool Rules::checkForTie() {
    bool allFull = true;
    for (int i = 1; i <= board.getLength(); i++) {
        if (board.getSpaceStatus(i) == 0) {
            allFull = false;
        }
    }
    if (allFull && checkForWin(true) == "" && checkForWin(false) == "") {
        responses.printBoard(board);
        responses.gameWasTie();
        return true;
    }
    return false;
}

bool Rules::inputIsInRange() {
    array <char, 6> colRange = {'A', 'B', 'C', 'a', 'b', 'c'};
    array <char, 3> rowRange = {'1', '2', '3'};
    for (int i = 0; i < rowRange.size() ; i++) {
        if (rowChar == rowRange[i]) {
            for (int x = 0; x < colRange.size(); x++) {
                if (colChar == colRange[x]) {
                    return true;
                }
            }
        }
    }
    return false;
}

bool Rules::spaceIsOpen() {
    if (board.getSpaceStatus(index) == 0) {
        return true;
    }
    return false;
}

string Rules::checkForWin(bool checkingX) {
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

void Rules::changeToIndex() {
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
