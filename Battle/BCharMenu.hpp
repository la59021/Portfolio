#pragma once
#include <array>
using namespace std;
class BCharMenu {
    public:
        BCharMenu();
        array<char, 2> player_chars();
    private:
        void ask_for_char(int player);
        void input_char(int player);
        char player1mark;
        char player2mark;
};