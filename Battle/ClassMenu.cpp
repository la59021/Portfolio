#include "ClassMenu.hpp"
#include <iostream>
using namespace std;

/*
BattleGame game = BattleGame();
game.startGame();
*/


string paladinDesc = "Paladin\n";
string alchemistDesc = "Alchemist\n";
string validMenuOptions[] = {"1", "2", "3", "4"};
string reply;
bool validSelection;

ClassMenu::ClassMenu() {
    Ask_For_Class(1);
    Ask_For_Class(2);
    CharMenu charMenu = CharMenu();
}

int ClassMenu::Ask_For_Class(int player) {
    prompt:
    validSelection = false;
    cout << "Player" << player << " make a desision" << endl;
    cout << "[1] Paladin" << endl;
    cout << "[2] Alchemist" << endl;
    cout << "[3] Class Descriptions" << endl;
    cout << "[4] Quit" << endl;
    cout << "Your Choice: ";
    cin >> reply;
    for(int i = 0; i < 4; i++) {
        if (reply == validMenuOptions[i]) {
            validSelection = true;
        }
    }
    if (!validSelection) {
        cout << "That was not a valid option. Try again." << endl;
        goto prompt;
    }
    if (validSelection && reply == "1") {
        if (player == 1) {
            player1class = 1;
        }
        else {
            player2class = 1;
        }
    }
    if (validSelection && reply == "2") {
        if (player == 1) {
            player1class = 2;
        }
        else {
            player2class = 2;
        }
    }
    if (validSelection && reply == "3") {
        cout << endl << endl << paladinDesc << endl << endl << alchemistDesc << endl << endl;
        goto prompt;
    }
    if (validSelection && reply == "4") {
        abort;
    }
}