#include "../Battle/BBoard.hpp"
#include "../Battle/BBoardPrinter.hpp"
#include <string>
#include <iostream>
#include <sstream>
#include <cassert>
using namespace std;

int main() {
    BBoard board;
    board.setSpaceStatus(1, 2);
    board.setSpaceStatus(2, 1);
    board.setSpaceStatus(3, 1);
    board.setSpaceStatus(4, 2);
    board.setSpaceStatus(5, 2);
    board.setSpaceStatus(6, 1);
    board.setSpaceStatus(7, 1);
    board.setSpaceStatus(8, 2);
    board.setSpaceStatus(9, 2);
    string expected;
    expected = "  |  A  |  B  |  C  |  \n";
    expected += "--|-----|-----|-----|--\n";
    expected += "1 |  P  |  ~  |  ~  |  \n";
    expected += "--|-----|-----|-----|--\n";
    expected += "2 |  P  |  P  |  ~  |  \n";
    expected += "--|-----|-----|-----|--\n";
    expected += "3 |  ~  |  P  |  P  |  \n";
    stringstream buffer;
    streambuf* prevcoutbuf = cout.rdbuf(buffer.rdbuf());
    BBoardPrinter printer(&board);
    printer.setMarks('~', 'P');
    printer.printBoard();
    string text = buffer.str();
    cout.rdbuf(prevcoutbuf);
    assert(text == expected);
    return 0;
    return 0;
}