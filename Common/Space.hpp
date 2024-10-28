#pragma once

// State Explinations 
// state = 0 => empty space
// state = 1 => marked by player 1
// state = 2 => marked by player 2

class Space {
    public:
        Space();
        int getStatus();
        void setStatus(int newState);
    private:
        int state;
};