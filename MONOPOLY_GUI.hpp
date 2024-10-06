#ifndef MONOPOLY_GUI_HPP
#define MONOPOLY_GUI_HPP

#include <SFML/Graphics.hpp>
#include <vector>
#include "Player.hpp"  // Make sure to include the Player class

class MONOPOLY_GUI {
public:
    MONOPOLY_GUI();  // Constructor to set up the GUI

     void movePlayer(int playerIndex, float newX, float newY);
    // Game loop that handles window events and rendering
    void gameLoop();

private:
    sf::RenderWindow window;        // The game window
    sf::Texture backgroundTexture;  // Texture for background image
    sf::Sprite backgroundSprite;    // Sprite to display the background image

    sf::RectangleShape boardShape;  // A placeholder for the Monopoly board
    sf::CircleShape playerTokens[2];  // Array of player tokens

    std::vector<sf::RectangleShape> boardSpaces;  // Vector to hold the shapes for board spaces

    std::vector<Player> players;  // Vector to hold the players in the game

    // Initialize the board and players
    void initializeBoard();
    void initializePlayers();

    // Function to render the GUI
    void render();
};

#endif
