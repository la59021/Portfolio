#include <string>

#include "Alchemist.hpp"
using namespace std;

Alchemist::Alchemist(Board *board, BattleRules *rules, char m) {
    this->mark = m;
    this->board = board;
    this->rules = rules;
}

void Alchemist::move() {
    char rowChar, colChar;
}

void Alchemist::skill() {

}

void Alchemist::prompt() {
    cout << "It is " << mark << "\'s Turn. Please enter the Desired space. \nUse the format row col:" << endl;
    
}

char Alchemist::get_mark() {
    return mark;
}