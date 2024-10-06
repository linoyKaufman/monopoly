//kaufmanlinoy@gmail.com / 206971962
#include "Board.hpp"
#include "Player.hpp"
#include "Cube.hpp"
#include "Property.hpp"
#include "Railroad.hpp"
#include "Utility.hpp"
#include "SpecialSpace.hpp"
#include <cassert>
#include <iostream>

void testPlayerMovement() {
    Player player("Charlie");

    // Move player within the board limits
    player.move(5);
    assert(player.getPosition() == 5);

    // Move player past the end of the board (simulating circular movement)
    player.move(37);
    assert(player.getPosition() == 2); // 5 + 37 wraps around the board

    std::cout << "Player movement test passed." << std::endl;
}

void testCube() {
    Cube cube;
    for (int i = 0; i < 100; ++i) {
        int roll = cube.roll();
        assert(roll >= 2 && roll <= 12);  // Rolls should be between 2 and 12 for two dice
    }
    std::cout << "Cube roll test passed." << std::endl;
}

void testBoardInitialization() {
    Board board;
    Space* spaceAt5 = board.getSpace(5);  // Assuming position 5 should be "Reading Railroad"
    
    // Cast to Railroad
    Railroad* railroad = dynamic_cast<Railroad*>(spaceAt5);
    
    // Check if the space at position 5 is a Railroad and named "Reading Railroad"
    if (railroad) {
        std::cout << "Space at position 5 is: \"" << railroad->getName() << "\"" << std::endl;  // Debug output
        
        // Debugging step: print the string lengths
        std::cout << "Length of railroad name: " << railroad->getName().length() << std::endl;
        std::cout << "Expected name: \"Reading Railroad\"" << std::endl;
        std::cout << "Length of expected name: " << std::string("Reading Railroad").length() << std::endl;

        // Use the string compare method instead of direct comparison
        assert(railroad->getName().compare("Reading Railroad") == 0);
    } else {
        std::cout << "Space at position 5 is not a railroad." << std::endl;  // Debug output for casting failure
        assert(false);  // Fail the test if it's not a Railroad
    }

    std::cout << "Board initialization test passed." << std::endl;
}







void testPropertyOwnership() {
    Player player1("Alice");
    Player player2("Bob");
    Property property("Baltic Avenue", 60, 4);

    // Player1 buys the property
    player1.buyProperty(&property);
    assert(property.isOwned());
    assert(property.getOwner() == &player1);

    // Player2 lands on the property and pays rent
    player2.deductMoney(property.getRent());
    player1.addMoney(property.getRent());
    assert(player2.getMoney() == 1500 - property.getRent());
    assert(player1.getMoney() == 1500 - property.getPrice() + property.getRent());

    std::cout << "Property ownership and rent test passed." << std::endl;
}

// void testRailroadOwnership() {
//     Player player("David");
//     Railroad railroad("Pennsylvania Railroad", 200);

// //     // Player buys the railroad
//     player.buyProperty(&railroad);
//     assert(railroad.isOwned());
//     assert(railroad.getOwner() == &player);

//     std::cout << "Railroad ownership test passed." << std::endl;
// }


void testSpecialSpaces() {
    Board board;

    // Go space
    Space* goSpace = board.getSpace(0);
    SpecialSpace* go = dynamic_cast<SpecialSpace*>(goSpace);
    assert(go != nullptr);
    assert(go->getName() == "Go");

    // Income Tax space
    Space* taxSpace = board.getSpace(4);
    SpecialSpace* incomeTax = dynamic_cast<SpecialSpace*>(taxSpace);
    assert(incomeTax != nullptr);
    assert(incomeTax->getName() == "Income Tax");

    std::cout << "Special spaces test passed." << std::endl;
}

int main() {
    testPlayerMovement();
    testCube();
    testBoardInitialization();
    testPropertyOwnership();
    //testRailroadOwnership();
    testSpecialSpaces();

    std::cout << "All tests passed!" << std::endl;
    return 0;
}
