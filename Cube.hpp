// Cube.hpp
#pragma once

class Cube {
public:
    // Rolls two six-sided dice and returns the total
    int roll();
    
    // Rolls a single die and returns the result
    int rollSingle();

    // Checks if the last roll was a double (both dice rolled the same number)
    bool isDouble() const;

private:
    int die1;  // First die value
    int die2;  // Second die value
};
