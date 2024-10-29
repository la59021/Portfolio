#include <string>

#include "Human.hpp"
using namespace std;

Human::Human(Board *board, NormalRules *rules,  char m) {
    this->mark = m;
    this->board = board;
    this->rules = rules;
}

void Human::turn() {
    prompt();
    move();
}

void Human::move() {
    int index;
    char rowChar, colChar;
    start:
    board->print();
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
}

void Human::prompt() {
    cout << "It is " << mark << "\'s Turn." << endl;
}

char Human::get_mark() {
    return mark;
}