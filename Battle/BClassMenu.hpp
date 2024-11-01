#pragma once
#include <array>
using namespace std;

class BClassMenu {
    public:
        BClassMenu();
        array<int, 2> player_classes();
    private:
        void ask_for_class(int player);
        int player1class;
        int player2class;
};