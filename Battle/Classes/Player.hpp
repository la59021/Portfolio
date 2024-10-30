#pragma once
#include <string>
using namespace std;

class Player {
    public:
        virtual void turn() = 0;
        virtual void move() = 0;
        virtual void prompt() = 0;
        virtual char get_mark() const = 0;
};