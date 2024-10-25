#include "ClassMenu.hpp"
#include "CharMenu.hpp"
#include <array>

#include "BattleLoop.hpp"
using namespace std;

void BattleLoop::start() {
    this->board = new BattleBoard();
    create_players();
    int turncount = 0;
    while(this->board->unfilled_spaces() == true && this->rules->wasThereAWinner() == false) {
        if (turncount % 2 == 0) {
            take_player_1_turn();
        }
        else if (turncount % 2 != 0) {
            take_player_2_turn();
        }
    }        
}

void BattleLoop::create_players() {
    ClassMenu classMenu = ClassMenu();
    CharMenu charMenu = CharMenu();
    array<int, 2> classes = classMenu.player_classes();
    array<char, 2> marks = charMenu.player_chars();
    for (int x = 0; x < 2; x++) {
        if (x == 0) {
            if (classes[x] == 1) {
                player1 = new Paladin(this->board, marks[x]);
            }
            if (classes[x] == 2) {
                player1 = new Alchemist(this->board, marks[x]);
            }
        }
        else if (x == 1) {
            if (classes[x] == 1) {
                player2 = new Paladin(this->board, marks[x]);
            }
            if (classes[x] == 2) {
                player2 = new Alchemist(this->board, marks[x]);
            }
        }
    }
}

void BattleLoop::takeP1Turn() {
    int index = 10;
    char rowChar = 'R';
    char colChar = 'C';
    if (checkForWin(true) != "" || checkForWin(false) != "") {
        won = true;
    }
    if (checkForWin(true) == "" && checkForWin(false) == "") {
        goto start;
    }
    else {
        goto leave;
    }
    start:
        responses.printBoard(board);
        prompts.askForXSpace();
        cin >> rowChar;
        cin >> colChar;
        cout << endl;
        goto checkValidity;

    checkValidity:
        if ((followsRules())) {
            changeToIndex();
            goto valid;
        }
        else {
            responses.isInvalidSpace();
            responses.printBoard(board);
            goto start;

        }

    valid:
        board.setSpaceStatus(index, 1);
        if (!won && checkForWin(true) != "") {
            responses.winnerIsX();
            cout << checkForWin(true) << endl;
            won = true;
        }
        else {
        }

    leave:
}

void BattleLoop::takeP2Turn() {
    index = 10;
    rowChar = 'R';
    colChar = 'C';
    if (checkForWin(true) != "" || checkForWin(false) != "") {
        won = true;
    }
    if (checkForWin(true) == "" && checkForWin(false) == "") {
        goto start;
    }
    else {
        goto leave;
    }
    start:
        responses.printBoard(board);
        prompts.askForXSpace();
        cin >> rowChar;
        cin >> colChar;
        cout << endl;
        goto checkValidity;

    checkValidity:
        if ((followsRules())) {
            changeToIndex();
            goto valid;
        }
        else {
            responses.isInvalidSpace();
            responses.printBoard(board);
            goto start;

        }

    valid:
        board.setSpaceStatus(index, 1);
        if (!won && checkForWin(true) != "") {
            responses.winnerIsX();
            cout << checkForWin(true) << endl;
            won = true;
        }
        else {
        }

    leave:
}