// local libraries
//#include "BattleLoop.hpp"
//#include "NormalLoop.hpp"

// standard libraries
#include <iostream>
using namespace std;

class Menu {
    private:
        int gamemode_select();
        int character_select();
        
    public:
        void new_game();
};