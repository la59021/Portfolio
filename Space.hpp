#ifndef SPACE_HPP
#define SPACE_HPP
class Space {
    public:
        Space();
        int getStatus();
        void setStatus(int newState);
    private:
        int state = 0;
};
#endif
