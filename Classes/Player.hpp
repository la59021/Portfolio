#pragma once
#include "../Common/Board.hpp"
#include <string>
using namespace std;

class Player {
    public:
        virtual void move() = 0;
        virtual void prompt() = 0;
        virtual char get_mark() = 0;
        virtual ~Player() = default;
};