#include "../BBoard.hpp"
#include <iostream>
#include "Alchemist.hpp"
using namespace std;

Alchemist::Alchemist(BBoard *board, char m) {
    mark = m;
}

void Alchemist::move() {
    
}

string Alchemist::desc() {
    return "Alchemist\n";
}

void Alchemist::skill() {
    int index1, index2;
    char rowChar1, colChar1, rowChar2, colChar2;
    prompt1:
    cout << "Select the First space" << endl;
    cin >> rowChar1;
    cin >> colChar1;
    index1 = Player::changeToIndex(rowChar1, colChar1);
    if (index1 < 0 || index1 > 8) {
        cout << "not valid" << endl;
        goto prompt1;
    }
    prompt2:
    cout << "Select the Second space" << endl;
    cin >> rowChar2;
    cin >> colChar2;
    index2 = changeToIndex(rowChar2, colChar2);
    if (index2 < 0 || index2 > 8) {
        cout << "not valid" << endl;
        goto prompt2;
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

char Alchemist::get_mark() const {
    return mark;
}