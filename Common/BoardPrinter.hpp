#pragma once
#include "../Common/Board.hpp"
#include "../Classes/Player.hpp"
#include "../Classes/Paladin.hpp"
#include "../Classes/Alchemist.hpp"
using namespace std;

class BoardPrinter {
    public:
        BoardPrinter(Board *board, Player *player1, Player *player2);
        void print_board();
        string status_to_mark(int index);
    private:
        Board *board;
        Player *player1;
        Player *player2;
};