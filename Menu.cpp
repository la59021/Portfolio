#include "Menu.hpp"
#include "Descriptions.hpp"
using namespace std;

void Menu::new_game() {
    string validMenuOptions[] = {"1", "2", "3", "4"};
    string reply;
    bool validSelection;
    prompt:
        validSelection = false;
        cout << "Which game mode would you like to play?" << endl;
        cout << "[1] Normal TicTacToe" << endl;
        cout << "[2] Battle TicTacToe" << endl;
        cout << "[3] What is the diffrence?" << endl;
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
        NormalLoop normalloop;
        normalloop.start();
    }
    if (validSelection && reply == "2") {
        BattleLoop battleloop;
        battleloop.start();
    }
    
    if (validSelection && reply == "3") {
        gamemode_descriptions();
        goto prompt;
    }
    if (validSelection && reply == "4") {
        system("exit");
    }

}

int Menu::gamemode_select() {

}

int Menu::character_select() {

}