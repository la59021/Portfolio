#include "../BBoard.hpp"
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

void Alchemist::move() {
    
}

string Alchemist::desc() {
    return "Alchemist\nYou are able to use you alchemy to transmute one mark into another.\n Beware the law of equviant exchange as you will have to change one of the oposite marks aswell.";
}

void Alchemist::skill() {
    int index1, index2;
    char rowChar1, colChar1, rowChar2, colChar2;
    prompt1:
    cout << "Select the first mark to swap. (use the standard format row col)" << endl;
    cin >> rowChar1;
    cin >> colChar1;
    if (!isValid(rowChar1, colChar1) || !isEmpty(rowChar2, colChar2)) {
        cout << "not valid" << endl;
        goto prompt1;
    }
    index1 = changeToIndex(colChar1, colChar2);

    prompt2:
    cout << "Select the mark to swap it with. (use the standard format row col)" << endl;
    cin >> rowChar2;
    cin >> colChar2;
    index2 = changeToIndex(rowChar2, colChar2);
    if (!isValid(rowChar2, colChar2) || isEmpty(rowChar2, colChar2) || !allowedSpace(index1, index2)) {
        cout << "not valid" << endl;
        goto prompt2;
    }
    int index1OldMark = board->getSpaceStatus(index1);
    board->setSpaceStatus(index1, board->getSpaceStatus(index2));
    board->setSpaceStatus(index2, index1OldMark);
}

void Alchemist::prompt() {
    cout << "It is " << mark << "\'s Turn." << endl;
    cout << "Do you want to..." << endl;
    cout << "[1] Make a move" << endl;
    cout << "[2] Use your skill to swap marks" << endl;
    cout << "[3] See an Explination of your skill" << endl;
    cout << "[4] Quit" << endl;
}

char Alchemist::get_mark() const {
    return mark;
}