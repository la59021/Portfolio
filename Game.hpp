#include "Rules.hpp"
using namespace std;

class Game {
    public:
        Game();
        void startGame();

    private:
        Rules rules;
        void takeTurn(bool isXsTurn);
};
