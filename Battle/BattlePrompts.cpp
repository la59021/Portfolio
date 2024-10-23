#include "BattlePrompts.hpp"
using namespace std;

Prompts::Prompts() {
    //ctor
}

void Prompts::askForXSpace() {
    cout << "It is X's Turn. Please enter the Desired space. \nUse the format row col:" << endl;
}

void Prompts::askForOSpace() {
    cout << "It is O's Turn. Please enter the Desired space. \nUse the format row col:" << endl;
}

void Prompts::askToPlayAgain() {
    cout << "Would you like to play Again? Y/N:" << endl;
}
