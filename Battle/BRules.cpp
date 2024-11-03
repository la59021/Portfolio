#include "BBoard.hpp"
#include "../Terminate.cpp"
#include <array>
#include "BRules.hpp"
using namespace std;

BRules::BRules(BBoard *newboard) {
    this->board = newboard;
    printer = new BBoardPrinter(this->board);
}

void BRules::addPlayers(Player *player1, Player *player2) {
    this->player1 = player1;
    this->player2 = player2;
    printer->setMarks(player1->get_mark(), player2->get_mark());
}

bool BRules::checkForTie() {
    bool allFull = true;
    for (int i = 1; i <= board->getLength(); i++) {
        if (board->getSpaceStatus(i) == 0) {
            allFull = false;
        }
    }
    if (allFull && !checkForWin()) {
        printer->printBoard();
        cout << "The game was a tie!" << endl;
        return true;
    }
    return false;
}

bool BRules::followsRules(const char rowChar, const char colChar) {
    array <char, 6> colRange = {'A', 'B', 'C', 'a', 'b', 'c'};
    array <char, 3> rowRange = {'1', '2', '3'};
    for (unsigned i = 0; i < rowRange.size(); i++) {
        if (rowChar == rowRange[i]) {
            for (unsigned x = 0; x < colRange.size(); x++) {
                if (colChar == colRange[x]) {
                    int index = changeToIndex(rowChar, colChar);
                    if (this->board->getSpaceStatus(index) == 0) {
                        return true;
                    }
                }
            }
        }
    }
    return false;
}

int BRules::gameInProgress() {
    return !won;
}

void BRules::player1Turn() {
    char validMenuOptions[] = {'1', '2', '3', '4'};
    char reply;
    bool validSelection;
    prompt:
    validSelection = false;
    printer->printBoard();
    player1->prompt();
    cin >> reply;
    if (reply == 'q' || reply == 'Q') {
        throw stop_now_t();
    }
    for(unsigned i = 0; i < sizeof(validMenuOptions); i++) {
        if (reply == validMenuOptions[i]) {
            validSelection = true;
        }
    }
    if (!validSelection) {
        cout << "That was not a valid option. Try again." << endl;
        goto prompt;
    }
    if (validSelection && reply == '1') {
        player1Move();
    }
    if (validSelection && reply == '2') {
        bool boardIsEmpty = true;
        for (int i = 1; i < 10; i++) {
            if (board->getSpaceStatus(i) != 0) {
                boardIsEmpty = false;
            }
        }  
        if (boardIsEmpty) {
            cout << "The board is empty you can't use your skill now" << endl;
            player1Move();
        }
        else player1->skill();
    }   
    if (validSelection && reply == '3') {
        cout << player1->desc();
        goto prompt;
    }
    if (validSelection && reply == '4') {
        throw stop_now_t();
    }
}

void BRules::player2Turn() {
    char validMenuOptions[] = {'1', '2', '3', '4'};
    char reply;
    bool validSelection;
    prompt:
    validSelection = false;
    printer->printBoard();
    player2->prompt();
    cin >> reply;
    if (reply == 'q' || reply == 'Q') {
        throw stop_now_t();
    }
    for(unsigned i = 0; i < sizeof(validMenuOptions); i++) {
        if (reply == validMenuOptions[i]) {
            validSelection = true;
        }
    }
    if (!validSelection) {
        cout << "That was not a valid option. Try again." << endl;
        goto prompt;
    }
    if (validSelection && reply == '1') {
        player2Move();
    }
    if (validSelection && reply == '2') {
        bool boardIsEmpty = true;
        for (int i = 0; i < board->getLength(); i++) {
            if (board->getSpaceStatus(i) != 0) {
                boardIsEmpty = false;
            }
        }  
        if (boardIsEmpty) {
            cout << "The board is empty you can't use your skill now" << endl;
            player2Move();
        }
        else player2->skill();
    }   
    if (validSelection && reply == '3') {
        cout << player2->desc();
        goto prompt;
    }
    if (validSelection && reply == '4') {
        throw stop_now_t();
    }
}

int BRules::changeToIndex(const char rowChar, const char colChar) {
    int index;
    if (rowChar == '1') {
        index = 0;
    }
    else if (rowChar == '2') {
        index = 3;
    }
    else {
        index = 6;
    }

    if (colChar == 'A' || colChar == 'a') {
        index += 0;
    }
    else if (colChar == 'B' || colChar == 'b') {
        index += 1;
    }
    else if (colChar == 'C' || colChar == 'c') {
        index += 2;
    }
    return index;
}

bool BRules::checkForWin() {
    if (board->getSpaceStatus(0) == board->getSpaceStatus(1) && board->getSpaceStatus(0) == board->getSpaceStatus(2) && board->getSpaceStatus(0) != 0) {
        return true;
    }
    if (board->getSpaceStatus(0) == board->getSpaceStatus(3) && board->getSpaceStatus(0) == board->getSpaceStatus(6) && board->getSpaceStatus(0) != 0) {
        return true;
    }
    if (board->getSpaceStatus(0) == board->getSpaceStatus(4) && board->getSpaceStatus(0) == board->getSpaceStatus(8) && board->getSpaceStatus(0) != 0) {
        return true;
    }
    if (board->getSpaceStatus(1) == board->getSpaceStatus(4) && board->getSpaceStatus(1) == board->getSpaceStatus(7) && board->getSpaceStatus(1) != 0) {
        return true;
    }
    if (board->getSpaceStatus(2) == board->getSpaceStatus(4) && board->getSpaceStatus(2) == board->getSpaceStatus(6) && board->getSpaceStatus(2) != 0) {
        return true;
    }
    if (board->getSpaceStatus(2) == board->getSpaceStatus(5) && board->getSpaceStatus(2) == board->getSpaceStatus(8) && board->getSpaceStatus(2) != 0) {
        return true;
    }
    if (board->getSpaceStatus(3) == board->getSpaceStatus(4) && board->getSpaceStatus(3) == board->getSpaceStatus(5) && board->getSpaceStatus(3) != 0) {
        return true;
    }
    if (board->getSpaceStatus(6) == board->getSpaceStatus(7) && board->getSpaceStatus(6) == board->getSpaceStatus(8) && board->getSpaceStatus(6) != 0) {
        return true;
    }
    return false;
}

void BRules::player1Move() {
    int index = 10;
    char rowChar, colChar;
    if (checkForWin()) {
        won = true;
        goto leave;
    }
    if (!checkForWin()) {
        goto start;
    }
    start:
        printer->printBoard();
        cout << "It is " << player1->get_mark() << "'s Turn. Please enter the Desired space. \nUse the format row col:" << endl;
        cin >> rowChar;
        cin >> colChar;
        cout << endl;
        goto checkValidity;

    checkValidity:
        if ((followsRules(rowChar, colChar))) {
            index = changeToIndex(rowChar, colChar);
            goto valid;
        }
        else {
            cout << "The entered space was invalid" << endl;
            cout << "Try Again" << endl;
            goto start;

        }

    valid:
        board->setSpaceStatus(index, 1);
        if (!won && checkForWin()) {
            printer->printBoard();
            cout << player1->get_mark() << " is the winner!" << endl;
            cout << winningCombo() << endl;
            won = true;
        }
        else {
        }

    leave:
    index = 0; // just to get the compiler to shutup about the label at the end
}

void BRules::player2Move() {
    int index = 10;
    char rowChar, colChar;
    if (checkForWin()) {
        won = true;
        goto leave;
    }
    if (!checkForWin()) {
        goto start;
    }
    start:
        printer->printBoard();
        cout << "It is " << player2->get_mark() << "'s Turn. Please enter the Desired space. \nUse the format row col:" << endl;
        cin >> rowChar;
        cin >> colChar;
        cout << endl;
        goto checkValidity;

    checkValidity:
        if ((followsRules(rowChar, colChar))) {
            index = changeToIndex(rowChar, colChar);
            goto valid;
        }
        else {
            cout << "The entered space was invalid" << endl;
            cout << "Try Again" << endl;
            goto start;

        }

    valid:
        board->setSpaceStatus(index, 2);
        if (!won && checkForWin()) {
            printer->printBoard();
            cout << player2->get_mark() << " is the winner!" << endl;
            cout << winningCombo() << endl;
            won = true;
        }
        else {
        }

    leave:
    index = 0; // just to get the compiler to shutup about the label at the end
}

string BRules::winningCombo() {
    string reply = "";
    if (board->getSpaceStatus(1) == board->getSpaceStatus(2) && board->getSpaceStatus(1) == board->getSpaceStatus(3) && board->getSpaceStatus(1) != 0) {
        if (board->getSpaceStatus(1) == 1) {
            reply = "The winner was Player1.\n"; 
        }
        if (board->getSpaceStatus(1) == 2) {
            reply = "The winner was Player2.\n"; 
        }
        reply += "The Winning combo was (1, A), (1, B), (1, C).";
    }
    if (board->getSpaceStatus(1) == board->getSpaceStatus(4) && board->getSpaceStatus(1) == board->getSpaceStatus(7) && board->getSpaceStatus(1) != 0) {
        if (board->getSpaceStatus(1) == 1) {
            reply = "The winner was Player1.\n"; 
        }
        if (board->getSpaceStatus(1) == 2) {
            reply = "The winner was Player2.\n"; 
        }
        reply += "The Winning combo was (1, A), (2, A), (3, A).";
    }
    if (board->getSpaceStatus(1) == board->getSpaceStatus(5) && board->getSpaceStatus(1) == board->getSpaceStatus(9) && board->getSpaceStatus(1) != 0) {
        if (board->getSpaceStatus(1) == 1) {
            reply = "The winner was Player1.\n"; 
        }
        if (board->getSpaceStatus(1) == 2) {
            reply = "The winner was Player2.\n"; 
        }
        reply += "The Winning combo was (1, A), (2, B), (3, C).";
    }
    if (board->getSpaceStatus(2) == board->getSpaceStatus(5) && board->getSpaceStatus(2) == board->getSpaceStatus(8) && board->getSpaceStatus(2) != 0) {
        if (board->getSpaceStatus(2) == 1) {
            reply = "The winner was Player1.\n"; 
        }
        if (board->getSpaceStatus(2) == 2) {
            reply = "The winner was Player2.\n"; 
        }
        reply += "The Winning combo was (1, B), (2, B), (3, B).";
    }
    if (board->getSpaceStatus(3) == board->getSpaceStatus(5) && board->getSpaceStatus(3) == board->getSpaceStatus(7) && board->getSpaceStatus(3) != 0) {
        if (board->getSpaceStatus(3) == 1) {
            reply = "The winner was Player1.\n"; 
        }
        if (board->getSpaceStatus(3) == 2) {
            reply = "The winner was Player2.\n"; 
        }
        reply += "The Winning combo was (1, C), (2, B), (3, A).";
    }
    if (board->getSpaceStatus(3) == board->getSpaceStatus(6) && board->getSpaceStatus(3) == board->getSpaceStatus(9) && board->getSpaceStatus(3) != 0) {
        if (board->getSpaceStatus(3) == 1) {
            reply = "The winner was Player1.\n"; 
        }
        if (board->getSpaceStatus(3) == 2) {
            reply = "The winner was Player2.\n"; 
        }
        reply += "The Winning combo was (1, C), (2, C), (3, C).";
    }
    if (board->getSpaceStatus(4) == board->getSpaceStatus(5) && board->getSpaceStatus(4) == board->getSpaceStatus(6) && board->getSpaceStatus(4) != 0) {
        if (board->getSpaceStatus(4) == 1) {
            reply = "The winner was Player1.\n"; 
        }
        if (board->getSpaceStatus(4) == 2) {
            reply = "The winner was Player2.\n"; 
        }
        reply += "The Winning combo was (2, A), (2, B), (2, C).";
    }
    if (board->getSpaceStatus(7) == board->getSpaceStatus(8) && board->getSpaceStatus(7) == board->getSpaceStatus(9) && board->getSpaceStatus(7) != 0) {
        if (board->getSpaceStatus(7) == 1) {
            reply = "The winner was Player1.\n"; 
        }
        if (board->getSpaceStatus(7) == 2) {
            reply = "The winner was Player2.\n"; 
        }
        reply += "The Winning combo was (3, A), (3, B), (3, C).";
    }
    return reply;
}