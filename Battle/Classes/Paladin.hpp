#pragma once
#include "Player.hpp"
using namespace std;

class Paladin : public Player {
    public:
        Paladin(char m);
        void move() override;
        string desc() override;
        array<int, 2> skill(BBoard *board) override;
        void prompt() override;
        char get_mark() const override;
    private:
        char mark;
};