#include "Board.hpp"
#include "Player.hpp"
#include "Cube.hpp"
#include "Property.hpp"
#include "Railroad.hpp"
#include "Utility.hpp"
#include <cassert>
#include <iostream>

void testGameFlow() {
    Board board;
    Cube cube;
    Player player1("Alice");
    Player player2("Bob");

    // Player 1 rolls and moves
    int roll1 = cube.roll();
    std::cout << player1.getName() << " rolled " << roll1 << std::endl;
    player1.move(roll1);
    Space* space1 = board.getSpace(player1.getPosition());
    std::cout << player1.getName() << " moved to position " << player1.getPosition() << std::endl;
    std::cout << player1.getName() << " landed on " << space1->getName() << std::endl;

    // Player 2 rolls and moves
    int roll2 = cube.roll();
    std::cout << player2.getName() << " rolled " << roll2 << std::endl;
    player2.move(roll2);
    Space* space2 = board.getSpace(player2.getPosition());
    std::cout << player2.getName() << " moved to position " << player2.getPosition() << std::endl;
    std::cout << player2.getName() << " landed on " << space2->getName() << std::endl;

    // Check if the space is a property and Bob buys it
    Property* property = dynamic_cast<Property*>(space2);
    if (property && !property->isOwned()) {
        player2.buyProperty(property);  // Bob buys the property
        assert(player2.getMoney() == 1500 - property->getPrice());
    }

    // Now Alice lands on the same property and pays rent to Bob
    player1.move(roll2);  // Simulate Alice landing on the same property as Bob
    space1 = board.getSpace(player1.getPosition());
    property = dynamic_cast<Property*>(space1);  // Reuse the variable 'property' here
    
    if (property && property->isOwned() && property->getOwner() == &player2) {
        player1.payRent(property);  // Alice pays rent to Bob
        assert(player1.getMoney() == 1500 - property->getRent());
        assert(player2.getMoney() == 1500 - property->getPrice() + property->getRent());
    }

}
    int main() {
    testGameFlow();
    std::cout << "All tests passed!" << std::endl;
    return 0;
}

