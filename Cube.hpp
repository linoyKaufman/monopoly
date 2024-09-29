#include <cstdlib>

class Dice {
public:
    int roll() {
        return (std::rand() % 6) + 1;
    }
};