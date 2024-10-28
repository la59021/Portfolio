#include <string>

#include "Human.hpp"
using namespace std;

Human::Human(Board *board, NormalRules *rules,  char m) {
    this->mark = m;
    this->board = board;
    this->rules = rules;
}

void Human::move() {
    
}

void Human::prompt() {
    char rowChar, colChar;
    start:
    cin >> rowChar;
    cin >> colChar;
    cout << endl;
    goto checkValidity;

    checkValidity:
    if (rules->follows_rules(rowChar, colChar)) {
        int index = board->change_to_index(rowChar, colChar);
        goto valid;
    }
    else {
        cout << "The entered space was invalid" << endl;
        print_board();
        goto start;
    }

    valid:
    this->board->set_space_status(index, 1);
}