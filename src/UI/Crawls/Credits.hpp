#pragma once

#include <SFML/Graphics.hpp>
#include <iostream>
#include <string>

class CreditsCrawl 
{
    private:
        sf::Clock clock;            // clock to manage the crawl speed
        sf::RenderWindow& window;   // reference to main window
        sf::Font font;              // text font
        sf::Text text;              // text to display
        const float speed = 100.0f; // Speed of the crawl in pixels per second
        int coins = 0;              // coins collected
        sf::Text coinsText;         // text to display coins collected
        
    public:

        /// @brief Constructor to intialise CreditsCrawl
        /// @param window window for rendering credits on
        CreditsCrawl(sf::RenderWindow& window);

        /// @brief Loading the credits
        void load();

        /// @brief Updates position of the credits text
        /// @param deltaTime for consistent movement speed
        /// @return returns true if credits finished scrolling
        bool update(float deltaTime);

        /// @brief Saves coins collected
        /// @param val coins collected
        void saveCoins(int val);

        /// @brief Draws the credits
        void draw();

};