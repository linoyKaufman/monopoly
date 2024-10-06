//kaufmanlinoy@gmail.com / 206971962

#include "Cube.hpp"
#include <cstdlib>  // For random


// Constructor - Optionally initialize random seed once 
Cube::Cube() {
}

// Roll two six-sided cube and return the total
int Cube::roll() {
    die1 = rollSingle();  // Roll the first 
    die2 = rollSingle();  // Roll the second 
    return die1 + die2;   // Return the sum of both 
}

// Roll a single six-sided cube and return the resolte
int Cube::rollSingle() {
    return (std::rand() % 6) + 1;  // Generate a random number between 1 and 6
}

// Check if the last roll was a double (both cubes has the same value)
bool Cube::isDouble() const {
    return die1 == die2;
}
