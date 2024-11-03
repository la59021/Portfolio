#include "../BBoard.hpp"
#include <iostream>
#include "Paladin.hpp"
using namespace std;

Paladin::Paladin(BBoard *board, char m) {
    this -> board = board;
    mark = m;
}

bool Paladin::allowedSpace(int index1, int index2) {
    if (index1 == 1) {
        if (index2 == 2 || index2 ==4 || index2 == 5) {
            return true;
        }
    }
    else if (index1 == 2) {
        if (index2 == 1 || index2 == 3 || index2 == 4 || index2 == 5 || index2 == 6) {
            return true;
        }
    }
    else if (index1 == 3) { 
        if (index2 == 2 || index2 == 5 || index2 == 6) {
            return true;
        }
    }
    else if (index1 == 4) {
        if (index2 == 1 || index2 == 2 || index2 == 5 || index2 == 7 || index2 == 8) {
            return true;
        }
    }
    else if (index1 == 5 && index2 != 5) {
        return true;
    }
    else if (index1 == 6) {
        if (index2 == 2 || index2 == 3 || index2 == 5 || index2 == 8 || index2 == 9) {
            return true;
        }
    }
    else if (index1 == 7) {
        if (index2 == 4 || index2 == 5 || index2 == 8) {
            return true;
        }
    }
    else if (index1 == 8) {
        if (index2 == 4 || index2 == 5 || index2 == 6 || index2 == 7 || index2 == 9) {
            return true;
        }
    }
    else if (index1 == 9) {
        if (index2 == 5 || index2 == 6 || index2 == 8) {
            return true;
        }
    }
    return false;
}

void Paladin::move() {

}

string Paladin::desc() {
    return "Paladin\n You are able to use your sheild to protect yourself while moving one of the marks.\nBut be aware that you can't move more than 1 piece";
}

void Paladin::skill() {
    int index1, index2;
    char rowChar1, colChar1, rowChar2, colChar2;
    prompt1:
    cout << "Select the mark to move. (use the standard format row col)" << endl;
    cin >> rowChar1;
    cin >> colChar1;
    if (!isValid(rowChar1, colChar1) || isEmpty(rowChar1, colChar1)) {
        cout << "not valid" << endl;
        goto prompt1;
    }
    index1 = changeToIndex(colChar1, colChar2);

    prompt2:
    cout << "Select where to move it to. (use the standard format row col)" << endl;
    cin >> rowChar2;
    cin >> colChar2;
    index2 = changeToIndex(rowChar2, colChar2);
    if (!isValid(rowChar2, colChar2) || !isEmpty(rowChar2, colChar2) || !allowedSpace(index1, index2)) {
        cout << "not valid" << endl;
        goto prompt2;
    }
    index2 = changeToIndex(rowChar2, colChar2);
    int status = board->getSpaceStatus(index1);
    board->setSpaceStatus(index2, status);
    board->setSpaceStatus(index1, 0);
}

void Paladin::prompt() {
    cout << "It is " << mark << "\'s Turn." << endl;
    cout << "Do you want to..." << endl;
    cout << "[1] Make a move" << endl;
    cout << "[2] Use your skill to move a mark" << endl;
    cout << "[3] See an Explination of your skill" << endl;
    cout << "[4] Quit" << endl;
}

char Paladin::get_mark() {
    return mark;
}


bool Paladin::isValid(char rowChar, char colChar) {
    array <char, 6> colRange = {'A', 'B', 'C', 'a', 'b', 'c'};
    array <char, 3> rowRange = {'1', '2', '3'};
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

int Paladin::changeToIndex(char rowChar, char colChar) {
    bool validRow = false;
    int index;
    if (rowChar == '1') {
        validRow = true;
        index = 0;
    }
    else if (rowChar == '2') {
        validRow = true;
        index = 3;
    }
    else if (rowChar == '3') {
        validRow = true;
        index = 6;
    }
    else {
        index = 9;
    }

    if (validRow) {
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
    return index;
}

bool Paladin::isEmpty(char rowChar, char colChar) {
    int index = changeToIndex(rowChar, colChar);
            if (this->board->getSpaceStatus(index) == 0) {
                return true;
            }
            return false;
}