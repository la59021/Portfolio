#include <iostream>
#include <array>
using namespace std;

class Prompts {
    public:
        Prompts(bool xStarts);
        void takeTurn(bool isOsTurn);
        //retakeTurn();
        //error();

    private:
        bool isXsTurn;
        bool inputInRange(string pickedSpace);
        int* changeToArrray(string pickedSpace);
        string promptToPickSpace();
};
