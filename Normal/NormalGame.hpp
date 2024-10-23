#include "NormalRules.hpp"
using namespace std;

class Game {
    public:
        void start();

    private:
        Rules rules;
        bool isXsTurn;
        void takeTurn();
};
