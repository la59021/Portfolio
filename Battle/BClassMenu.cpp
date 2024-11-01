#include "../Terminate.cpp"
#include <iostream>
#include "BClassMenu.hpp"
using namespace std;

BClassMenu::BClassMenu() {
    ask_for_class(1);
    cout << endl;
    ask_for_class(2);
    cout << endl;
}

array<int, 2> BClassMenu::player_classes() {
    return {player1class, player2class};
}

void BClassMenu::ask_for_class(int player) {
    string paladinDesc = "Paladin\n You are able to use your sheild to protect yourself while moving one of the marks.\nBut be aware that you can't move more than 1 piece";
    string alchemistDec = "Alchemist\nYou are able to use you alchemy to transmute one mark into another.\n Beware the law of equviant exchange as you will have to change one of the oposite marks aswell.";
    char validMenuOptions[] = {'1','2','3','4'};
    char reply;
    bool validSelection;
    prompt:
    validSelection = false;
    cout << "Player " << player << endl;
    cout << "[1] Paladin" << endl;
    cout << "[2] Alchemist" << endl;
    cout << "[3] Explain the classes" << endl;
    cout << "[4] Quit" << endl;
    cout << "Your Choice: ";
    cin >> reply;
    if (reply == 'q' || reply == 'Q') {
        throw stop_now_t();
    }
    for(unsigned i = 0; i < sizeof(validMenuOptions); i++) {
        if (reply == validMenuOptions[i]) {
            validSelection = true;
        }
    }
    if (!validSelection) {
        cout << "That was not a valid option. Try again." << endl;
        goto prompt;
    }
    if (validSelection && reply == '1') {
        if (player == 1) {
            player1class = 1;
        }
        if (player == 2) {
            player2class = 1;
        }      
    }
    if (validSelection && reply == '2') {
        if (player == 1) {
            player1class = 2;
        }
        if (player == 2) {
            player2class = 2;
        }     
    }
    if (validSelection && reply == '3') {
        cout << endl << endl << paladinDesc << endl << endl << alchemistDec << endl << endl;
        goto prompt;
    }
    if (validSelection && reply == '4') {
        throw stop_now_t();
    }
}