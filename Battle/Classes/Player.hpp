#pragma once
#include "../BBoard.hpp"
#include <string>
using namespace std;

class Player {
    public:
        virtual string desc() = 0;
        virtual void skill() = 0; 
        virtual void prompt() = 0;
        virtual char get_mark() = 0;
        virtual bool isValid(const char rowChar, const char colChar) = 0;
        virtual bool isEmpty(const char rowChar, const char colChar) = 0;
        virtual int changeToIndex(char rowChar, char colChar) = 0;
    private:
        BBoard *board = 0;
};