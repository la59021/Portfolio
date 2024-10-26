#ifndef BATTLELOOP_HPP
#define BATTLELOOP_HPP
#include "BattleRules.hpp"
#include "BattleBoard.hpp"
#include "BattlePrompts.hpp"
#include "BattleResponses.hpp"
#include "Classes/Player.hpp"
#include "Classes/Paladin.hpp"
#include "Classes/Alchemist.hpp"
using namespace std;
class BattleLoop {
    public:
        void start();
    private:
        void create_players();
        void take_player_1_turn();
        void take_player_2_turn();
        BattleBoard *board;
        BattleRules *rules;
        BattlePrompts *prompts;
        BattleResponses *responses;
        Player *player1;
        Player *player2;
        bool gameInProgress;
};
#endif