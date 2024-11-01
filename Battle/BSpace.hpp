#pragma once

class BSpace {
    public:
        BSpace();
        int getStatus() const;
        void setStatus(int newState);
    private:
        int state;
};