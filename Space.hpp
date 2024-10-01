// Space.hpp
#pragma once
#include <string>
#include "Player.hpp"

class Space {
protected:
    std::string name;  // The name of the space 
public:
    // Constructor that initializes the space with its name
    Space(const std::string& spaceName) : name(spaceName) {}

    // Pure virtual function that must be implemented by derived classes.
    // Defines the behavior when a player lands on the space.
    virtual void landOn(Player* player) = 0;

    // Getter for the name of the space
    std::string getName() const {
        return name;
    }

    // Virtual destructor to ensure proper cleanup of derived classes
    virtual ~Space() {}
};
