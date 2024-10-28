#pragma once
#include "BattleBoard.hpp"
#include <iostream>
#include <string>
using namespace std;
class BattlePrompts {
    public:
        BattlePrompts();
        void ask_for_player_1_space();
        void ask_for_player_2_space();
        void ask_to_play_again();
};