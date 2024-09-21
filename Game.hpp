#include "Rules.hpp"
using namespace std;

class Game {
    public:
        Game();
        void startGame();

    private:
        Rules rules;
        bool isXsTurn;
        void takeTurn();
};
