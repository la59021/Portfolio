#include <string>
#include "../BRules.hpp"
#include "Paladin.hpp"
using namespace std;

Paladin::Paladin(char m) {
    mark = m;
}

void Paladin::turn() {
    prompt();
    prompt_selection() == 1 ? move() : skill();
}

void Paladin::move() {
/*
    int index;
    char rowChar, colChar;
    start:
    cout << "Enter the Desired space. \nUse the format row col: "; 
    cin >> rowChar;
    cin >> colChar;
    cout << endl;

    checkValidity:
    if (this->rules->follows_rules(rowChar, colChar)) {
        int index = this->board->change_to_index(rowChar, colChar);
        goto valid;
    }
    else {
        cout << "The entered space was invalid" << endl;
        goto start;
    }

    valid:
    this->board->set_space_status(index, mark);
*/
}

void Paladin::skill() {

}

void Paladin::prompt() {
/*
    cout << "It is " << mark << "\'s Turn." << endl;
    cout << "Do you want to..." << endl;
    cout << "[1] Make a move" << endl;
    cout << "[2] Use your skill to move a mark";
*/
}

int Paladin::prompt_selection() {
/*
    int reply;
    cin >> reply;
    return reply;
*/
    return 1;
}

char Paladin::get_mark() const {
    return mark;
}