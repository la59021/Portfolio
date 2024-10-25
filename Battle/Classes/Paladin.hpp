#include "../BattleBoard.hpp"

#include "Player.hpp"
using namespace std;

class Paladin : public Player {
    private:
    public:
        Paladin(BattleBoard *board, char m);
        void move() override;
        void prompt() override;
        char mark;
};