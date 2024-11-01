#pragma once
#include "BBoard.hpp"
#include <iostream>
using namespace std;

class BBoardPrinter {
    public:
        BBoardPrinter(BBoard *board) {
            this->board = board;
        }
        void printBoard() {
            cout << "  |  A  |  B  |  C  |  " << "\n";
            cout << "--|-----|-----|-----|--" << "\n";
            cout << "1 |  " << statusToMark(1) << "  |  " + statusToMark(2) << "  |  " +statusToMark(3) << "  |  " << "\n";
            cout << "--|-----|-----|-----|--" << "\n";
            cout << "2 |  " << statusToMark(4) << "  |  " + statusToMark(5) << "  |  " +statusToMark(6) << "  |  " << "\n";
            cout << "--|-----|-----|-----|--" << "\n";
            cout << "3 |  " << statusToMark(7) << "  |  " + statusToMark(8) << "  |  " +statusToMark(9) << "  |  " << "\n";
        }
        void setMarks(char mark1, char mark2) {
            player1mark = mark1;
            player2mark = mark2;
        }
        string statusToMark(int index) {
            if (board->getSpaceStatus(index) == 0) {
                return " ";
            }
            if (board->getSpaceStatus(index) == 1) {
                return player1mark;
            }
            if (board->getSpaceStatus(index) == 2) {
                return player2mark;
            }
            return "-1";
        }
    private:
        string player1mark, player2mark;
        BBoard *board;
};