#include <iostream>

#include "BCharMenu.hpp"
using namespace std;

BCharMenu::BCharMenu() {
    ask_for_char(1);
    ask_for_char(2);
}

array<char, 2> BCharMenu::player_chars() {
    return {player1mark, player2mark};
}

void BCharMenu::ask_for_char(int player) {
    string charRulesExpl = "Valid Characters\nThe valid characters are from A to Z, a to z. Also allowed are \"?\", \"!\", \"*\", \"~\", \"$\", \"%\", and \"#\".";
    char validMenuOptions[] = {'1','2','3'};
    char reply;
    bool validSelection;
    prompt:
    validSelection = false;
    cout << "Player " << player << " make a desision." << endl;
    cout << "[1] Enter a your character" << endl;
    cout << "[2] What are the rules for picking a character?" << endl;
    cout << "[3] Quit" << endl;
    cout << "Your Choice: ";
    cin >> reply;
    for(int i = 0; i < sizeof(validMenuOptions); i++) {
        if (reply == validMenuOptions[i]) {
            validSelection = true;
        }
    }
    if (!validSelection) {
        cout << "That was not a valid option. Try again." << endl;
        goto prompt;
    }
    if (validSelection && reply == '1') {
        input_char(player); 
    }
    if (validSelection && reply == '2') {
        cout << endl << endl << charRulesExpl << endl << endl;
        goto prompt;
    }
    if (validSelection && reply == '3') {
        system("exit");
    }
}

void BCharMenu::input_char(int player) {
    char allowedChars[] = {'A','B','C','D','E','F','G','H','I','J','K','L','M','N','O','P','Q','R','S','T','U','V','W','X','Y','Z','a','b','c','d','e','f','g','h','i','j','k','l','m','n','o','p','q','r','s','t','u','v','w','x','y','z','?','!','*','~','$','%','#'};
    char reply;
    bool validSelection;
    prompt:
    validSelection = false;
    cout << endl << endl <<"Player " << player << " pick a character: ";
    cin >> reply;
    for(int i = 0; i < sizeof(allowedChars); i++) {
        if (reply == allowedChars[i]) {
            validSelection = true;
        }
    }
    if (!validSelection) {
        cout << "That was not a valid option. Try again." << endl;
        goto prompt;
    }
    if (validSelection) {
        if (player == 1) {
            player1mark = reply;
        }
        if (player == 2) {
            player2mark = reply;
        }      
    } 
}