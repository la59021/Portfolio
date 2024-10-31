#pragma once
#include "../BBoard.hpp"
#include "Player.hpp"
using namespace std;

class Paladin : public Player {
    public:
        Paladin(BBoard *board, char m);
        void move() override;
        string desc() override;
        array<int, 2> skill(BBoard *board) override;
        void prompt() override;
        char get_mark() const override;
    private:
        BBoard *board;
        char mark;
};