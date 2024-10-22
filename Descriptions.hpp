#include <iostream>
using namespace std;

void gamemode_descriptions() {
    string NormalMode = "Normal TicTacToe\nThe game is a normal game of TicTacToe. To select specify the desired row followed by a space then the desired colum, for example 2 B";
    string BattleMode = "Battle TicTacToe\nThe win conditions are the same as normal TicTacToe. The space selection is the same as with normal TicTacToe, but the skills have special space selection methods that are explained in the description for that class. Each player picks a class before the game, classes provide skills that consume a turn but in return are game breaking.";
    cout << endl << endl << NormalMode << endl << endl << BattleMode << endl << endl;
}