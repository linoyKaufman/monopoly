
#include <string>
#include "Player.hpp"

class Space {
protected:
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
