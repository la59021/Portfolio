#pragma once
#include <string>
using namespace std;

class Player {
    public:
        char playerMark;
        virtual void move() = 0;
        virtual void prompt() = 0;
        virtual ~Player() = default;
};