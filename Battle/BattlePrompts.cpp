#include "BattlePrompts.hpp"
using namespace std;

BattlePrompts::BattlePrompts() {
    //ctor
}

void BattlePrompts::ask_for_player_1_space() {
    cout << "It is player 1's Turn. Please enter the Desired space. \nUse the format row col:" << endl;
}

void BattlePrompts::ask_for_player_2_space() {
    cout << "It is player 2's Turn. Please enter the Desired space. \nUse the format row col:" << endl;
}

void BattlePrompts::ask_to_play_again() {
    cout << "Would you like to play Again? Y/N:" << endl;
}
