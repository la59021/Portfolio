#pragma once
#include <array>
using namespace std;
class ClassMenu {
    public:
        ClassMenu();
        array<int, 2> player_classes();
    private:
        int player1class;
        int player2class;
        void ask_for_class(int player);
        void ask_for_class();
};