#include <string>

#include "Paladin.hpp"
using namespace std;

Paladin::Paladin(Board *board, BattleRules *rules, char m) {
    this->mark = m;
    this->board = board;
    this->rules = rules;
}

void Paladin::move() {

}

void Paladin::prompt() {
    string paladinDesc = "Paladin\n";
}