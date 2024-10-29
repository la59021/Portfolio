#pragma once
class BSpace {
    public:
        BSpace();
        int getStatus();
        void setStatus(int newState);

    private:
        int state = 0;
};