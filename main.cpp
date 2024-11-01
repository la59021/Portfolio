#include "Terminate.cpp"
#include "MainMenu.hpp"
using namespace std;


int main() {
    MainMenu menu;
    try {
        menu.new_game();
    } catch (stop_now_t& stop) {
        return 0;
    }
    return 0;
}