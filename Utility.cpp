#include "Utility.hpp"
#include <iostream>

using namespace std;

// Constructor to initialize the utility with a name and price
Utility::Utility(string name, int price) : name(name), price(price), owner(nullptr) {}

// Get the name of the utility
string Utility::getName() const {
    return name;
}

// Get the price of the utility
int Utility::getPrice() const {
    return price;
}

// Set the owner of the utility
void Utility::setOwner(Player* newOwner) {
    owner = newOwner;
}

// Get the owner of the utility
Player* Utility::getOwner() const {
    return owner;
}

// Calculate the rent based on the number of utilities owned and the dice roll
int Utility::getRent(int diceRoll, int ownedUtilities) const {
    // If the player owns both utilities, the rent is 10 times the dice roll
    // If the player owns only one utility, the rent is 4 times the dice roll
    if (ownedUtilities == 2) {
        return 10 * diceRoll;
    } else {
        return 4 * diceRoll;
    }
}

// Handle the event when a player lands on the utility
void Utility::landOn(Player* player) {
    if (owner == nullptr) {
        // No owner: offer the player the option to buy
        cout << player->getName() << " landed on " << name << ". It's available for purchase for $" << price << "." << endl;
        // Logic to offer the player the option to buy the utility can be added here
    } else if (owner == player) {
        // Player owns this utility: no rent due
        cout << player->getName() << " landed on their own utility." << endl;
    } else {
        // Another player owns the utility: pay rent
        int diceRoll = rand() % 6 + 1 + rand() % 6 + 1;  // Simulate a dice roll
        int rent = getRent(diceRoll, owner->getNumberOfUtilities());
        player->deductMoney(rent);  // Deduct rent from the player landing on the utility
        owner->addMoney(rent);      // Give rent to the owner
        cout << player->getName() << " rolled a " << diceRoll << " and paid $" << rent << " to " << owner->getName() << " for landing on " << name << "." << endl;
    }
}
