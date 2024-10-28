#include "BattleResponses.hpp"
using namespace std;

BattleResponses::BattleResponses(Board *board) {
    this->board = board;
}

void BattleResponses::is_invalid_space() {
    cout << "The entered space was invalid" << endl;
}

void BattleResponses::winner_is_player_1() {
    cout << "Player 1 is the winner!" << endl;
}

void BattleResponses::winner_is_player_2() {
    cout << "Player 2 is the winner!" << endl;
}

void BattleResponses::game_was_tie() {
    cout << "The game was a tie!" << endl;
}
