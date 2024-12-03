#include "Terminate.cpp"
#include "Battle/BGame.hpp"
#include "Normal/NGame.hpp"
#include <iostream>
#include "MainMenu.hpp"
using namespace std;

string create_stats(int winners[3]) {
    int games = winners[0] + winners[1] + winners[2];
    string stats;
    stats += "These are the stats for this session of tic-tac-toe.\n";
    stats += "Player 1 wins: " + to_string(winners[0]) + "\n";
    stats += "Player 2 wins: " + to_string(winners[2]) + "\n"; 
    stats += "Tie games: " + to_string(winners[3]) + "\n";
    stats += "Total games: " + to_string(games) + "\n";
    return stats;
}

void write_stats(string stats) {
    
}

bool play_again(){
    char reply;
    cout << "would you like to play again? [Y/n]" << endl;
    cin >> reply;
    if (reply == ('y' || 'Y')) {
        return true;
    }
    return false;
}

void MainMenu::new_game() {
    int winners[3] = {0, 0, 0};
    string normalModeDesc = "Normal TicTacToe\nThe game is a normal game of TicTacToe. To select specify the desired row followed by a space then the desired colum, for example 2 B";
    string battleModeDesc = "Battle TicTacToe\nThe win conditions are the same as normal TicTacToe. The space selection is the same as with normal TicTacToe, but the skills have special space selection methods that are explained in the description for that class. Each player picks a class before the game, classes provide skills that consume a turn but in return are game breaking.";
    char validMenuOptions[] = {'1','2','3','4'};
    char reply;
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
        NGame nGame;
        int winner = nGame.startGame();
        if (winner == 1) {
            winners[0]++;
        }
        else if (winner == 2) {
            winners[1]++;
        }
        else {
            winners[2]++;
        }
        if (play_again()) {
            goto prompt;
        }
    }
    if (validSelection && reply == '2') {
        BGame bGame;
        int winner = bGame.startGame();
        if (winner == 1) {
            winners[0]++;
        }
        else if (winner == 2) {
            winners[1]++;
        }
        else {
            winners[2]++;
        }
        if (play_again()) {
            goto prompt;
        }
    }   
    if (validSelection && reply == '3') {
        cout << endl << endl << normalModeDesc << endl << endl << battleModeDesc << endl << endl;
        goto prompt;
    }
    if (validSelection && reply == '4') {
        throw stop_now_t();
    }
    string stats = create_stats(winners);
    write_stats(stats);
}