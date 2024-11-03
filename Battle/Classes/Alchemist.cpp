#include "../BBoard.hpp"
#include <array>
#include <iostream>
#include "Alchemist.hpp"
using namespace std;

Alchemist::Alchemist(BBoard *board, char m) : board(board), mark(m) {}

bool Alchemist::allowedSpace(int index1, int index2) {
    if (board->getSpaceStatus(index1) == board->getSpaceStatus(index2) || index1 == index2 ) {
        return false;
    }
    return true;
}

string Alchemist::desc() {
    return "Alchemist\nYou are able to use you alchemy to transmute one mark into another.\n Beware the law of equviant exchange as you will have to change one of the oposite marks aswell.";
}

void Alchemist::skill() {
    int index1, index2;
    char rowChar1 = '1', colChar1 = 'a', rowChar2 = '1', colChar2 = 'a';
    prompt1:
    cout << "Select the first mark to swap. (use the standard format row col)" << endl;
    cin >> rowChar1;
    cin >> colChar1;
    if (!isValid(rowChar1, colChar1) || isEmpty(rowChar1, colChar1)) {
        cout << "not valid" << endl;
        goto prompt1;
    }
    index1 = changeToIndex(rowChar1, colChar1);

    prompt2:
    cout << "Select the mark to swap it with. (use the standard format row col)" << endl;
    cin >> rowChar2;
    cin >> colChar2;
    index2 = changeToIndex(rowChar2, colChar2);
    if (!isValid(rowChar2, colChar2) || isEmpty(rowChar2, colChar2) || !allowedSpace(index1, index2)) {
        cout << "not valid" << endl;
        goto prompt2;
    }
    if (this->board->getSpaceStatus(index1) == 1) {
        this->board->setSpaceStatus(index1, 2);
        this->board->setSpaceStatus(index2, 1);
    }
    else if (this->board->getSpaceStatus(index1) == 2) {
        this->board->setSpaceStatus(index1, 1);
        this->board->setSpaceStatus(index2, 2);
    }
}

void Alchemist::prompt() {
    cout << "It is " << mark << "\'s Turn." << endl;
    cout << "Do you want to..." << endl;
    cout << "[1] Make a move" << endl;
    cout << "[2] Use your skill to swap marks" << endl;
    cout << "[3] See an Explination of your skill" << endl;
    cout << "[4] Quit" << endl;
}

char Alchemist::get_mark() {
    return mark;
}

bool Alchemist::isValid(char rowChar, char colChar) {
    cout << "rowChar: " << rowChar << "\ncolChar: " << colChar << endl;
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

int Alchemist::changeToIndex(char rowChar, char colChar) {
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

bool Alchemist::isEmpty(char rowChar, char colChar) {
    int index = changeToIndex(rowChar, colChar);
    if (this->board->getSpaceStatus(index) == 0) {
        return true;
    }
    else {
        return false;
    }
}