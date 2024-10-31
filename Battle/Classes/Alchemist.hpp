#pragma once
#include "Player.hpp"
#include "../BBoard.hpp"
using namespace std;

class Alchemist : public Player {
    public:
        Alchemist(char m);
        void move() override;
        string desc() override;
        array<int, 2> skill(BBoard *board) override;
        void prompt() override;
        char get_mark() const override;
    private:
        BBoard *board;
        char mark;
};