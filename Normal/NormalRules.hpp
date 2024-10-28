#pragma once
#include "NormalPrompts.hpp"
#include "NormalResponses.hpp"
using namespace std;
class NormalRules {
    public:
        NormalRules();
        bool follows_rules(char rowChar, char colChar);
        bool was_there_a_winner();
        void take_X_turn();
        void take_O_turn();
        bool check_for_tie();
        bool play_again();
        int get_last_winner();
    private:
        NormalPrompts prompts;
        NormalResponses responses;
        Board board;
        int index, winner;
        char rowChar, colChar;
        bool won = false;
        bool input_is_in_range();
        bool space_is_open();
        string check_for_win(bool checkingX);
        void change_to_index();
};