#include <string>
#include "../BRules.hpp"
#include "Alchemist.hpp"
using namespace std;

Alchemist::Alchemist (char m) {
    mark = m;
}

void Alchemist::turn() {
    prompt();
}

void Alchemist::move() {
    char rowChar, colChar;
}

void Alchemist::skill() {

}

void Alchemist::prompt() {
    cout << "It is " << mark << "\'s Turn. Please enter the Desired space. \nUse the format row col:" << endl;
    
}

char Alchemist::get_mark() const {
    return mark;
}