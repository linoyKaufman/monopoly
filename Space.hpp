#ifndef SPACE_HPP  // If SPACE_HPP is not defined
#define SPACE_HPP  // Define SPACE_HPP


#include <string>
#include "Player.hpp"
#include "Property.hpp"
#include "Board.hpp"

class Player;

class Space {
private:
    std::string name;

public:
    // Constructor that initializes the name of the space
    Space(const std::string& spaceName) : name(spaceName) {}

    // Virtual function for when a player lands on the space
    virtual void landOn(Player* player) = 0;

    // Getter for the name of the space
    std::string getName() const {
        return name;
    }

    // Virtual destructor
    virtual ~Space() {}
};
#endif // SPACE_HPP
