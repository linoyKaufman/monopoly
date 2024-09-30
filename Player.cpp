#include <iostream>
#include <vector>
#include <string>
#include "Property.hpp" 

using namespace std;

class Player {
private:
    string name;                   // The name of the player
    int money;                     // The amount of money the player has
    int position;                  // The player's position on the board (0 to 39)
    bool inJail;                   // Flag indicating if the player is in jail
    int jailTurns;                 // Number of turns the player has been in jail
    vector<Property*> properties;  // List of properties the player owns

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

    // Pay rent to another player (assuming the property is owned by someone else)
    void payRent(Property* property) {
        Player* owner = property->getOwner();
        int rent = property->getRent();
        if (owner != this) {
            deductMoney(rent);
            owner->addMoney(rent);
            cout << name << " paid " << rent << " in rent to " << owner->getName() << endl;
        }
    }

    // Go to jail (sets inJail flag and moves the player to the jail position)
    void goToJail() {
        inJail = true;
        position = 10;  // Jail is typically at position 10 on the board
        jailTurns = 0;  // Reset jail turn counter
        cout << name << " has been sent to jail!" << endl;
    }

    // Try to leave jail (e.g., by paying, rolling doubles, etc.)
    void attemptToLeaveJail() {
        if (jailTurns < 3) {
            jailTurns++;
            cout << name << " is still in jail for " << jailTurns << " turns." << endl;
        } else {
            payJailFine();
            inJail = false;
            cout << name << " has paid the fine and left jail." << endl;
        }
    }

    // Pay the fine to get out of jail
    void payJailFine() {
        if (money >= 50) {
            deductMoney(50);  // Jail fine is typically 50 units
            inJail = false;
            jailTurns = 0;
            cout << name << " paid the jail fine and is now free." << endl;
        } else {
            cout << name << " cannot afford the jail fine!" << endl;
        }
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

    // Check if the player has enough money to continue in the game
    bool isBankrupt() const {
        return money <= 0;
    }
};
