#include "BattleResponses.hpp"
using namespace std;

BattleResponses::BattleResponses(BattleBoard *board) {
    this->board = board;
}

void BattleResponses::print_board() {
    string row1 = "_| A | B | C |_";
    string row2 = "1| " + status_to_mark(1) + " | " + status_to_mark(2) + " | " +status_to_mark(3) + " |_";
    string row3 = "2| " + status_to_mark(4) + " | " + status_to_mark(5) + " | " +status_to_mark(6) + " |_";
    string row4 = "3| " + status_to_mark(7) + " | " + status_to_mark(8) + " | " +status_to_mark(9) + " |_";
    cout << row1 << endl << row2 << endl << row3 << endl << row4 << endl << endl;
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

string BattleResponses::status_to_mark(int index) {
    if (board->get_space_status(index) == 0) {
        return " ";
    }
    if (board->get_space_status(index) == 1) {
        return "X";
    }
    if (board->get_space_status(index) == 2) {
        return "O";
    }
    return "-1";
}

