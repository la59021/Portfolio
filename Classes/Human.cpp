#include <string>

#include "Human.hpp"
using namespace std;

Human::Human(Board *board, NormalRules *rules, char m) {
    this->mark = m;
    this->board = board;
    this->rules = rules;
}

void Human::move() {
    
}

void Human::prompt() {
    char rowChar, colChar;
}