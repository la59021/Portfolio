#include <string>

#include "Alchemist.hpp"
using namespace std;

Alchemist::Alchemist(Board *board, BattleRules *rules, char m) {
    mark = m;
    this->board = *board;
    this->rules = *rules;
}

void Alchemist::move() {

}

void Alchemist::prompt() {
    string alchemistDesc = "Alchemist\n";
    char rowChar, colChar;
}