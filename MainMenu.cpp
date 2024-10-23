#include "quitCut.hpp"
#include "MainMenu.hpp"
using namespace std;

string quitExpination = "Note\n At any time when asked for an input respond with \"q\" to quit the game.";
string normalModeDesc = "Normal TicTacToe\nThe game is a normal game of TicTacToe. To select specify the desired row followed by a space then the desired colum, for example 2 B";
string battleModeDesc = "Battle TicTacToe\nThe win conditions are the same as normal TicTacToe. The space selection is the same as with normal TicTacToe, but the skills have special space selection methods that are explained in the description for that class. Each player picks a class before the game, classes provide skills that consume a turn but in return are game breaking.";
string validMenuOptions[] = {"1", "2", "3", "4"};
string reply;
bool validSelection;

void MainMenu::start_menu() {
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
        cout << "Start a Normal Game.\n\n";
        NormalGame game = NormalGame();
        game.startGame();
    }
    if (validSelection && reply == "2") {
        cout << "Start a Battle Game.";
    }
    if (validSelection && reply == "3") {
        cout << endl << endl << quitExpination << endl << endl << normalModeDesc << endl << endl << battleModeDesc << endl << endl;
        goto prompt;
    }
    if (validSelection && reply == "4") {
        quitCut('q');
    }
}