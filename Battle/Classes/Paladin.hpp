#pragma once
#include "Player.hpp"
using namespace std;

class Paladin : public Player {
    public:
        Paladin(char m);
        void turn() override;
        void move() override;
        void skill();
        void prompt() override;
        int prompt_selection();
        char get_mark() override;
    private:
        char mark;
};