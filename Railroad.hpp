//kaufmanlinoy@gmail.com / 206971962

#ifndef RAILROAD_HPP
#define RAILROAD_HPP

#include <string>
#include "Space.hpp"
#include "Player.hpp"

class Railroad : public Space {
private:
    int price;              // Purchase price of the railroad
    int baseRent;           // Base rent for one owned railroad
    Player* owner;          // Pointer to the player who owns the railroad

public:
    // Constructor
    Railroad(std::string name, int price);

    // Getter functions
    std::string getName() const;  // Inherited from Space
    
    int getPrice() const;

    // Calculate rent based on how many railroads the owner has
    int getRent(int ownedRailroads) const;

    // Set the owner of the railroad
    void setOwner(Player* newOwner);

    // Get the current owner
    Player* getOwner() const;

    // What happens when a player lands on this railroad
    void landOn(Player* player) ;  
};


#endif  
