#pragma once
#include "BattlePrompts.hpp"
#include "BattleResponses.hpp"
#include "../Common/Board.hpp"
using namespace std;

class BattleRules{
    public:
        BattleRules();
        BattleRules(Board *board);
        bool follows_rules(char rowChar, char colChar);
        bool was_there_a_winner();
        bool check_for_tie();
        bool play_again();
        int get_last_winner();
    private:
        Board *board;
        BattlePrompts prompts = BattlePrompts();
        BattleResponses responses = BattleResponses(this->board);
        bool won = false;
        string check_for_win();
};