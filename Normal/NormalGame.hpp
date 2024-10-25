#include "NormalRules.hpp"
using namespace std;

class NormalGame {
    public:
        NormalGame();
        void startGame();

    private:
        NormalRules rules;
        bool isXsTurn;
        void takeTurn();
};
