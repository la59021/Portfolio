#include "BGame.hpp"
#include "BCharMenu.hpp"
#include "BClassMenu.hpp"
using namespace std;

void BGame::startGame() {
    int i = 0;
    createPlayers();
    rules.addPlayers(player1, player2);
    while (rules.gameInProgress()) {
        if (i % 2 == 0) {
            rules.takeXTurn();
        }
        else {
            rules.takeOTurn();
        }
        i++;
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
                player1 = new Paladin(marks[x]);
            }
            if (classes[x] == 2) {
                player1 = new Alchemist(marks[x]);
            }
        }
        else if (x == 1) {
            if (classes[x] == 1) {
                player2 = new Paladin(marks[x]);
            }
            if (classes[x] == 2) {
                player2 = new Alchemist(marks[x]);
            }
        }
    }
}