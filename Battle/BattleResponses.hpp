#pragma once
#include "BattleBoard.hpp"
#include <iostream>
#include <string>
using namespace std;
class BattleResponses {
    public:
        BattleResponses(BattleBoard *board);
        void print_board();
        void is_invalid_space();
        void winner_is_player_1();
        void winner_is_player_2();
        void game_was_tie();
    private:
        BattleBoard *board;
        string status_to_mark(int index);
};