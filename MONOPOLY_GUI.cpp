#include "MONOPOLY_GUI.hpp"
#include <iostream>
#include "Player.hpp"


// Constructor to set up the window and initialize the game
MONOPOLY_GUI::MONOPOLY_GUI() {
    // Create the window
    window.create(sf::VideoMode(1000000, 10000), "Monopoly Game");

    // Load the background image
    if (!backgroundTexture.loadFromFile("/home/linoy/Downloads/monopoly-main/Background.jpg")) {
        std::cerr << "Error loading background image!" << std::endl;
    }

    // Set the texture for the background sprite
    backgroundSprite.setTexture(backgroundTexture);

    // Initialize other game elements
 
    initializePlayers();
}



// Initialize the board spaces (as rectangles)
void MONOPOLY_GUI::initializeBoard() {
    for (int i = 0; i < 40; ++i) {
        sf::RectangleShape space(sf::Vector2f(100.0f, 100.0f));
        space.setFillColor(sf::Color::White);
        space.setOutlineThickness(2.0f);
        space.setOutlineColor(sf::Color::Black);
        space.setPosition((i % 10) * 100, (i / 10) * 100);  // Adjust position on the grid
        boardSpaces.push_back(space);
    }
}

// Initialize players (as circles)
void MONOPOLY_GUI::initializePlayers() {
    playerTokens[0].setRadius(20.f);
    playerTokens[0].setPosition(0, 500);  // Set Player 1's token position
    playerTokens[0].setFillColor(sf::Color::Red);  // Set Player 1's token color

    playerTokens[1].setRadius(20.f);
    playerTokens[1].setPosition(60, 500);  // Set Player 2's token position
    playerTokens[1].setFillColor(sf::Color::Blue);  // Set Player 2's token color
}


// Render the board and players
void MONOPOLY_GUI::render() {
    // Load the background texture
    if (!backgroundTexture.loadFromFile("/home/linoy/Downloads/monopoly-main/Background.jpg")) {
        std::cerr << "Error loading background image!" << std::endl;
    }

    // Create a sprite for the background
    sf::Sprite backgroundSprite;
    backgroundSprite.setTexture(backgroundTexture);

    // Game loop for rendering
    while (window.isOpen()) {
        sf::Event event;
        while (window.pollEvent(event)) {
            if (event.type == sf::Event::Closed)
                window.close();
        }

        // Clear the window
        window.clear();

        // Draw the background sprite
        window.draw(backgroundSprite);

        // Draw other game elements like players, tokens, board, etc.

        // Display everything on the window
        window.display();
    }
}

// Game loop to handle events and rendering
void MONOPOLY_GUI::gameLoop() {
    while (window.isOpen()) {
        sf::Event event;
        while (window.pollEvent(event)) {
            if (event.type == sf::Event::Closed) {
                window.close();
            }
        }

        // Render the board and players
        render();
    }
}

// Function to move a player
void MONOPOLY_GUI::movePlayer(int playerIndex, float newX, float newY) {
    if (playerIndex >= 0 && playerIndex < 2) {  // Ensure valid player index
        playerTokens[playerIndex].setPosition(newX, newY);  // Move the player token
    } else {
        std::cerr << "Invalid player index: " << playerIndex << std::endl;
    }
}
int main() {
    // Create an instance of the Monopoly GUI
    MONOPOLY_GUI monopolyGui;

    // Start the game loop
    monopolyGui.gameLoop();

    return 0;
}
