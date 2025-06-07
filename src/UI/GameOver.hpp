#pragma once

#include <SFML/Graphics.hpp>
#include <string>
#include <iostream>
#include "../Constants/constants.hpp"

class GameOver{
    private:
        sf::Font font;                  // text font
        sf::Text gameOverText;          // text to display
        sf::Text coinsText;             // "Coins: "
        sf::Text buttonText;            // Text On Button: "Back To Menu"
        sf::Texture buttonTexture;      // Button Texture 
        sf::Sprite buttonSprite;        // Sprite for the Button
        int coins = 0;                  // Variable To store Coins collected

    public:

        /// @brief Constructor to initialise Game Over Screen
        /// @param window main window to render on
        GameOver(sf::RenderWindow& window);

        /// @brief Function to check whether button has been clicked
        /// @param window window to check mouse input on
        /// @return returns true if button has been clicked
        bool update(sf::RenderWindow& window);
        
        /// @brief Function to draw Game Over Screen to window
        /// @param window window to draw Game Over Screen on
        void draw(sf::RenderWindow& window);

        /// @brief Function to Save Coins Collected
        /// @param val Coins Collected
        void saveCoins(int val);

};