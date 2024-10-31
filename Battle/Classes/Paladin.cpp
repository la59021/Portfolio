#include <string>
#include "../BRules.hpp"
#include "Paladin.hpp"
using namespace std;

Paladin::Paladin(BBoard *board, char m) {
    this -> board = board;
    mark = m;
}

void Paladin::move() {

}

string Paladin::desc() {
    return "Paladin\n";
}

array<int, 2> Paladin::skill() {
    int index1, index2;
    char rowChar1, colChar1, rowChar2, colChar2;
    prompt1:
    cout << "Select the First space" << endl;
    cin >> rowChar1;
    cin >> colChar1;
    if (!checkValidity(rowChar1, colChar1)) {
        cout << "not valid" << endl;
        goto prompt1;
    }
    index1 = changeToIndex(colChar1, colChar2);
    prompt2:
    cout << "Select the Second space" << endl;
    cin >> rowChar2;
    cin >> colChar2;
    if (!checkValidity(rowChar2, colChar2)) {
        cout << "not valid" << endl;
        goto prompt2;
    }
    index2 = changeToIndex(rowChar2, colChar2);
    return {index1, index2}; 
}

void Paladin::prompt() {
    cout << "It is " << mark << "\'s Turn." << endl;
    cout << "Do you want to..." << endl;
    cout << "[1] Make a move" << endl;
    cout << "[2] Use your skill to move a mark" << endl;
    cout << "[3] See an Explination of your skill" << endl;
    cout << "[4] Quit" << endl;
}

char Paladin::get_mark() const {
    return mark;
}