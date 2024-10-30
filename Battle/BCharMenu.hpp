#pragma once
#include <array>
using namespace std;
class BCharMenu {
    public:
        BCharMenu();
        array<char, 2> player_chars();
    private:
        char player1mark;
        char player2mark;
        void ask_for_char(int player);
        void input_char(int player);
};