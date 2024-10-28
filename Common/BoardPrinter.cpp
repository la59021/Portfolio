#include <iostream>
#include "Board.hpp"

#include "BoardPrinter.hpp"
using namespace std;

BoardPrinter::BoardPrinter(Board *board, Player *player1, Player *player2) {
    this->board = board;
    this->player1 = player1;
    this->player2 = player2;
}

void BoardPrinter::print_board() {
    string row1 = "_| A | B | C |_";
    string row2 = "1| " + status_to_mark(1) + " | " + status_to_mark(2) + " | " +status_to_mark(3) + " |_";
    string row3 = "2| " + status_to_mark(4) + " | " + status_to_mark(5) + " | " +status_to_mark(6) + " |_";
    string row4 = "3| " + status_to_mark(7) + " | " + status_to_mark(8) + " | " +status_to_mark(9) + " |_";
    cout << row1 << endl << row2 << endl << row3 << endl << row4 << endl << endl;
}

string BoardPrinter::status_to_mark(int index) {
    string mark;
    if (board->get_space_status(index) == 0) {
        mark = " ";
    }
    else if (board->get_space_status(index) == 1) {
        mark = to_string(player1->get_mark());
    }
    else if (board->get_space_status(index) == 2) {
        mark = to_string(player2->get_mark());
    }
    else return "-1";
    return mark;
}