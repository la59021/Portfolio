#include "BGame.hpp"
#include "CharMenu.hpp"
#include "ClassMenu.hpp"
using namespace std;

void BGame::startGame() {
    int i = 0;
    while (!rules.wasThereAWinner()) {
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
    ClassMenu classMenu = ClassMenu();
    CharMenu charMenu = CharMenu();
    array<char, 2> marks = charMenu.player_chars();
    array<int, 2> classes = classMenu.player_classes();
    for (int x = 0; x < 2; x++) {
        if (x == 0) {
            if (classes[x] == 1) {
                player1 = new Paladin(&rules, marks[x]);
            }
            if (classes[x] == 2) {
                player1 = new Alchemist(&rules, marks[x]);
            }
        }
        else if (x == 1) {
            if (classes[x] == 1) {
                player2 = new Paladin(&rules, marks[x]);
            }
            if (classes[x] == 2) {
                player2 = new Alchemist(&rules, marks[x]);
            }
        }
    }
}