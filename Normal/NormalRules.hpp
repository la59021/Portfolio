#pragma once
#include "NormalResponses.hpp"
using namespace std;
class NormalRules {
    public:
        NormalRules(Board *board);
        bool follows_rules(char rowChar, char colChar);
        bool game_in_progress();
        bool check_for_tie();
        int get_last_winner();
    private:
        NormalResponses responses = NULL;
        Board *board;
        int winner;
        bool won = false;
        bool input_is_in_range(char rowChar, char colChar);
        bool space_is_open(int index);
        string check_for_win(bool checkingX);
        int change_to_index(char rowChar, char colChar);
};