//kaufmanlinoy@gmail.com / 206971962

#include "SpecialSpace.hpp"
#include <iostream>

using namespace std;

// Constructor 
SpecialSpace::SpecialSpace(const std::string& name) : Space(name) {}

// Override the landOn method for when a player lands on the special space
void SpecialSpace::landOn(Player* player) {
    cout << player->getName() << " landed on " << name << "." << endl;

    // Define behavior based on the type of special space
    if (name == "Go") {
        cout << player->getName() << " collects $200 for passing Go!" << endl;
        player->addMoney(200);
    } else if (name == "Income Tax") {
        cout << player->getName() << " must pay $200 in income tax." << endl;
        player->deductMoney(200);
    } else if (name == "Luxury Tax") {
        cout << player->getName() << " must pay $100 in luxury tax." << endl;
        player->deductMoney(100);
    } else if (name == "Go to Jail") {
        cout << player->getName() << " must go directly to jail!" << endl;
        player->goToJail();
    } else {
        // Other special spaces 
        cout << "Special space action for " << name << " is not defined yet." << endl;
    }
}


// Handle the Community Chest space
void SpecialSpace::handleCommunityChest(Player* player) {
    // Example: Randomize an event from Community Chest
    int event = rand() % 2;  // Generates a random number between 0 and 1
    if (event == 0) {
        cout << player->getName() << " won $100 from the Community Chest!" << endl;
        player->addMoney(100);
    } else {
        cout << player->getName() << " must pay $50 in hospital fees." << endl;
        player->deductMoney(50);
    }
}

// Handle the Chance space
void SpecialSpace::handleChance(Player* player) {
    // Example: Randomize an event from Chance
    int event = rand() % 2;  // Generates a random number between 0 and 1
    if (event == 0) {
        cout << player->getName() << " must pay $15 for speeding fine." << endl;
        player->deductMoney(15);}
    else{
        cout << player->getName() << " receives $150 in bank dividends." << endl;
        player->addMoney(150);
    }
}
