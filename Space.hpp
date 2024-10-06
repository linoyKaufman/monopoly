//kaufmanlinoy@gmail.com / 206971962

#ifndef SPACE_HPP
#define SPACE_HPP

#include <string>


class Player;

//  class for all board spaces
class Space {
protected:
    std::string name;  

public:
    // Constructor
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

#endif
