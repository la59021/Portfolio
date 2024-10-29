#pragma once
#include "NormalRules.hpp"
#include "../Common/Board.hpp"
#include "NormalResponses.hpp"
#include "../Classes/Player.hpp"
#include "../Classes/Human.hpp"
using namespace std;
class NormalLoop {
    public:
        void start();
    private:
        void create_players();
        bool play_again();
        Board *board;
        NormalRules *rules;
        NormalResponses *responses;
        Player *player1;
        Player *player2;
        bool gameInProgress;
};