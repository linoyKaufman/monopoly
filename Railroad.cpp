//kaufmanlinoy@gmail.com / 206971962

#include "Railroad.hpp"
#include "Property.hpp"
#include "Player.hpp"
#include "Space.hpp"
#include "Board.hpp"
#include <iostream>

using namespace std;

// Constructor 
Railroad::Railroad(std::string name, int price) : Space(name), price(price), owner(nullptr) {
    
}

// Get the name of the railroad
string Railroad::getName() const {
    return name;
}

// Get the purchase price of the railroad
int Railroad::getPrice() const {
    return price;
}

// Calculate rent based on the number of owned railroads
int Railroad::getRent(int ownedRailroads) const {
    if (owner == nullptr) {
        return 0;  // No rent if no owner
    }
    return baseRent * (1 << (ownedRailroads - 1));  // Rent doubles for each additional railroad
}

// Set the owner of the railroad
void Railroad::setOwner(Player* newOwner) {
    owner = newOwner;
}

// Get the owner of the railroad
Player* Railroad::getOwner() const {
    return owner;
}

// Handle the event when a player lands on the railroad
void Railroad::landOn(Player* player) {
    if (owner == nullptr) {
        cout << player->getName() << " landed on " << name << ". It's available for purchase for $" << price << "." << endl;
        // Add logic to offer the player the option to buy the railroad
    } else if (owner == player) {
        cout << player->getName() << " landed on their own railroad." << endl;
    } 
}
