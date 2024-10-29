#include "../Common/Board.hpp"
#include "../Common/BoardPrinter.hpp"
#include "../Normal/NormalRules.hpp"

#include "Player.hpp"
using namespace std;

class Human : public Player {
    public:
        Human(Board *board, NormalRules *rules, char m);
        void turn() override;
        void move() override;
        void skill();
        void prompt() override;
        int prompt_selection();
        char get_mark() override;
    private:
        char mark;
        Board *board;
        BoardPrinter *printer;
        NormalRules *rules;
};