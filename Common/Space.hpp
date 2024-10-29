#pragma once

class Space {
    public:
        Space();
        char getStatus();
        void setStatus(char newState);
    private:
        char state;
};