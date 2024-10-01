#include <iostream>
#include <vector>
#include <string>
#include "Property.hpp" 
#include "Utility.hpp"

using namespace std;

class Player {
private:
    string name;                   // The name of the player
    int money;                     // The amount of money the player has
    int position;                  // The player's position on the board (0 to 39)
    bool inJail;                   // Flag indicating if the player is in jail
    int jailTurns;                 // Number of turns the player has been in jail
    vector<Property*> properties;  // List of properties the player owns
    vector<Utility*> utilities;    // List of utilities the player owns <--- ADD THIS

public:
    // Constructor - Initializes a new player with a name, starting money, and position
    Player(string playerName) : name(playerName), money(1500), position(0), inJail(false), jailTurns(0) {}

    // Get the player's name
    string getName() const {
        return name;
    }

    // Get the player's position on the board
    int getPosition() const {
        return position;
    }

    // Get the amount of money the player currently has
    int getMoney() const {
        return money;
    }

    // Check if the player is in jail
    bool isInJail() const {
        return inJail;
    }

    // Move the player by a specified number of steps (wrap around the board if necessary)
    void move(int steps) {
        position = (position + steps) % 40; // Ensure position stays within 0 to 39 (circular board)
        cout << name << " moved to position " << position << endl;
    }

    // Deduct money from the player (used for paying rent, taxes, etc.)
    void deductMoney(int amount) {
        if (money >= amount) {
            money -= amount;
            cout << name << " has paid " << amount << " and now has " << money << " left." << endl;
        } else {
            cout << name << " doesn't have enough money!" << endl;
            // Handle bankruptcy or other game rules if needed
        }
    }

    // Add money to the player (used for collecting rent, passing GO, etc.)
    void addMoney(int amount) {
        money += amount;
        cout << name << " received " << amount << " and now has " << money << endl;
    }

    // Buy a property (if affordable), and add it to the player's list of owned properties
    void buyProperty(Property* property) {
        if (money >= property->getPrice()) {
            money -= property->getPrice();
            properties.push_back(property);
            property->setOwner(this);
            cout << name << " bought " << property->getName() << " for " << property->getPrice() << endl;
        } else {
            cout << name << " doesn't have enough money to buy " << property->getName() << endl;
        }
    }

    // Buy a utility and add it to the player's list of owned utilities
    void buyUtility(Utility* utility) {
        if (money >= utility->getPrice()) {
            money -= utility->getPrice();
            utilities.push_back(utility);
            utility->setOwner(this);
            cout << name << " bought the utility: " << utility->getName() << endl;
        } else {
            cout << name << " doesn't have enough money to buy " << utility->getName() << endl;
        }
    }

    // Get the number of utilities owned by the player
    int getNumberOfUtilities() const {
        return utilities.size();  // Return the size of the utilities vector
    }

    // Display the list of properties owned by the player
    void displayProperties() const {
        if (properties.empty()) {
            cout << name << " owns no properties." << endl;
        } else {
            cout << name << " owns the following properties:" << endl;
            for (auto* property : properties) {
                cout << " - " << property->getName() << endl;
            }
        }
    }

    // Display the list of utilities owned by the player
    void displayUtilities() const {
        if (utilities.empty()) {
            cout << name << " owns no utilities." << endl;
        } else {
            cout << name << " owns the following utilities:" << endl;
            for (auto* utility : utilities) {
                cout << " - " << utility->getName() << endl;
            }
        }
    }

    // Check if the player has enough money to continue in the game
    bool isBankrupt() const {
        return money <= 0;
    }
};
