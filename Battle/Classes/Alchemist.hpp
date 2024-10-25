#include "../BattleBoard.hpp"

#include "Player.hpp"
using namespace std;

class Alchemist : public Player {
    private:
    public:
        Alchemist(BattleBoard *board, char m);
        void move() override;
        void prompt() override;
        char mark;
};