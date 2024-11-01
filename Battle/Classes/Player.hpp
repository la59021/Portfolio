#pragma once
#include "../BBoard.hpp"
#include <string>
using namespace std;

class Player {
    public:
        virtual string desc() = 0;
        virtual void skill() = 0; 
        virtual void move() = 0;
        virtual void prompt() = 0;
        virtual char get_mark() const = 0;
        bool checkValidity(const char rowChar, const char colChar) {
            array <char, 6> colRange = {'A', 'B', 'C', 'a', 'b', 'c'};
            array <char, 3> rowRange = {'1', '2', '3'};
            for (unsigned i = 0; i < rowRange.size(); i++) {
                if (rowChar == rowRange[i]) {
                    for (unsigned x = 0; x < colRange.size(); x++) {
                        if (colChar == colRange[x]) {
                            return true;
                        }
                    }
                }
            }
            return false;
        }
        bool checkEmpty(const char rowChar, const char colChar) {
            int index = changeToIndex(rowChar, colChar);
            if (this->board->getSpaceStatus(index) == 0) {
                return true;
            }
            return false;
        }
        int changeToIndex(const char rowChar, const char colChar) {
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
    private:
        BBoard *board = 0;
};