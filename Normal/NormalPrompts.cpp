#include "NormalPrompts.hpp"
using namespace std;

NormalPrompts::NormalPrompts() {
    //ctor
}

void NormalPrompts::askForXSpace() {
    cout << "It is X's Turn. Please enter the Desired space. \nUse the format row col:" << endl;
}

void NormalPrompts::askForOSpace() {
    cout << "It is O's Turn. Please enter the Desired space. \nUse the format row col:" << endl;
}

void NormalPrompts::askToPlayAgain() {
    cout << "Would you like to play Again? Y/N:" << endl;
}
