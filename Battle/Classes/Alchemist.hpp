#pragma once
#include "../BBoard.hpp"
#include <string>
#include "Player.hpp"
using namespace std;

class Alchemist : public Player {
    public:
        Alchemist(BBoard *board, char m);
        bool allowedSpace(int index1, int index2);
        string desc() override;
        void skill() override;
        void prompt() override;
        char get_mark() override;
        int changeToIndex(char rowChar, char colChar) override;
        bool isValid(char rowChar, char colChar) override;
        bool isEmpty(char rowChar, char colChar) override;
    private:
        BBoard *board;
        char mark;
};