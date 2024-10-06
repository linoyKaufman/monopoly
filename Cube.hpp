//kaufmanlinoy@gmail.com / 206971962

class Cube {
private:
    int die1;  // First die
    int die2;  // Second die

public:
    // Constructor
    Cube();

    // Roll two six-sided dice and return the total
    int roll();

    // Roll a single six-sided die
    int rollSingle();

    // Check if the last roll was a double
    bool isDouble() const;
};


