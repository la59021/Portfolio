#include <string>
using namespace std;

static void quitCut(string check) {
    if (check == "q") {
        system("exit");
    }
}

static void quitCut(char c) {
    if (c == 'q') {
        system("exit");
    }
}