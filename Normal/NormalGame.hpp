#include "Rules.hpp"
using namespace std;

class NormalGame {
    public:
        NormalGame();
        void startGame();

    private:
        Rules rules;
        bool isXsTurn;
        void takeTurn();
};
