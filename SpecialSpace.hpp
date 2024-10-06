// kaufmanlinoy@gmail.com / 206971962
#ifndef SPECIALSPACE_HPP
#define SPECIALSPACE_HPP

#include <string>
#include "Space.hpp"
#include "Player.hpp"

class SpecialSpace : public Space {
public:
    // Constructor to initialize the special space with its name
    SpecialSpace(const std::string& name);

    // Override the landOn method to when a player lands on the special space
    void landOn(Player* player) override;

    // Handle Community Chest space
    void handleCommunityChest(Player* player);

    // Handle Chance space
    void handleChance(Player* player);
};

#endif // SPECIALSPACE_HPP
