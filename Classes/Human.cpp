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
    cout << "It is " << mark << "\'s Turn. Please enter the Desired space. \nUse the format row col:" << endl;
}

char Human::get_mark() {
    return mark;
}