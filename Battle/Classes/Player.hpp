#pragma once
#include <string>
#include "../BBoard.hpp"
using namespace std;

class Player {
    public:
        virtual string desc() = 0;
        virtual array<int, 2> skill(BBoard *board) = 0; 
        virtual void move() = 0;
        virtual void prompt() = 0;
        virtual char get_mark() const = 0;
        virtual int changeToIndex(const char rowChar, const char colChar) {
            int index;
            if (rowChar == '1') {
                index = 1;
            }
            else if (rowChar == '2') {
                index = 4;
            }
            else if (rowChar == '3') {
                index = 7;
            }
            else {
                index = 10;
            }

            if (colChar == 'A' || colChar == 'a') {
                index += 0;
            }
            else if (colChar == 'B' || colChar == 'b') {
                index += 1;
            }
            else if (colChar == 'C' || colChar == 'c') {
                index += 2;
            }
            return index;
        }
};