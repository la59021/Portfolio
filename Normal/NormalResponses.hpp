#pragma once
#include "../Common/Board.hpp"
#include <iostream>
#include <string>
using namespace std;
class NormalResponses {
    public:
        NormalResponses(Board *board);
        void print_board();
        void is_invalid_space();
        void winner_is_X();
        void winner_is_O();
        void game_was_tie();
    private:
        Board *board;
        string status_to_mark(int index);
};