#include "NormalResponses.hpp"
using namespace std;

NormalResponses::NormalResponses(Board *board) {
    this->board = board;
}

void NormalResponses::print_board() {
    string row1 = "_| A | B | C |_";
    string row2 = "1| " + status_to_mark(1) + " | " + status_to_mark(2) + " | " +status_to_mark(3) + " |_";
    string row3 = "2| " + status_to_mark(4) + " | " + status_to_mark(5) + " | " +status_to_mark(6) + " |_";
    string row4 = "3| " + status_to_mark(7) + " | " + status_to_mark(8) + " | " +status_to_mark(9) + " |_";
    cout << row1 << endl << row2 << endl << row3 << endl << row4 << endl << endl;
}

void NormalResponses::is_invalid_space() {
    cout << "The entered space was invalid" << endl;
}

void NormalResponses::winner_is_X() {
    cout << "X is the winner!" << endl;
}

void NormalResponses::winner_is_O() {
    cout << "O is the winner!" << endl;
}

void NormalResponses::game_was_tie() {
    cout << "The game was a tie!" << endl;
}

string NormalResponses::status_to_mark(int index) {
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

