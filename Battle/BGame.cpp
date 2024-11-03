#include <iostream>
#include "BBoard.hpp"
#include "BCharMenu.hpp"
#include "BClassMenu.hpp"
#include "BRules.hpp"
#include "Classes/Alchemist.hpp"
#include "Classes/Paladin.hpp"
#include "Classes/Player.hpp"
#include "BGame.hpp"
using namespace std;

BGame::BGame() {
    rules = new BRules(&board);
    player1 = nullptr; 
    player2 = nullptr;
}

void BGame::startGame() {
    cout << "At any point when asked for an input use \"q\" or \"Q\" to quit.\n";
    int turn = 0;
    createPlayers();
    rules->addPlayers(player1, player2);
    while (rules->gameInProgress()) {
        if (turn % 2 == 0) {
            rules->player1Turn();
        }
        else if (turn % 2 != 0) {
            rules->player2Turn();
        }
        turn++;
    }
}

void BGame::createPlayers() {
    BClassMenu classMenu = BClassMenu();
    BCharMenu charMenu = BCharMenu();
    array<char, 2> marks = charMenu.player_chars();
    array<int, 2> classes = classMenu.player_classes();
    for (int x = 0; x < 2; x++) {
        if (x == 0) {
            if (classes[x] == 1) {
                player1 = new Paladin(&board, marks[x]);
            }
            if (classes[x] == 2) {
                player1 = new Alchemist(&board, marks[x]);
            }
        }
        else if (x == 1) {
            if (classes[x] == 1) {
                player2 = new Paladin(&board, marks[x]);
            }
            if (classes[x] == 2) {
                player2 = new Alchemist(&board, marks[x]);
            }
        }
    }
}