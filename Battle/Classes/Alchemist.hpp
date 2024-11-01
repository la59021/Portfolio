#pragma once
#include "../BBoard.hpp"
#include <string>
#include "Player.hpp"
using namespace std;

class Alchemist : public Player {
    public:
        Alchemist(BBoard *board, char m);
        bool allowedSpace(int index1, int index2);
        void move() override;
        string desc() override;
        void skill() override;
        void prompt() override;
        char get_mark() const override;
    private:
        BBoard *board;
        char mark;
};