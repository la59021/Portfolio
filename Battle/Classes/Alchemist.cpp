#include <string>

#include "Alchemist.hpp"
using namespace std;

Alchemist::Alchemist(BattleBoard *board, BattleRules *rules, char m) {
    mark = m;
    this->rules = *rules;
    this->board = *board;
}

void Alchemist::move() {

}

void Alchemist::prompt() {
    string alchemistDesc = "Alchemist\n";
    char rowChar, colChar;
    cin >> rowChar;
    cin >> colChar;
    cout << endl;
    goto checkValidity;

    checkValidity:
    if (this->*rules->follows_rules(rowChar, colChar)) {
        int index = this->board->change_to_index(rowChar, colChar);
        goto valid;
    }
    else {
        this->responses->is_invalid_space();
        this->responses->print_board();
        goto start;
    }

    valid:
    this->board->set_space_status(index, 1);
}
}