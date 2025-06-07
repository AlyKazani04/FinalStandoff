#pragma once

#include <SFML/Graphics.hpp>
#include <iostream>
#include <string>

class Instructions
{
    private:
        sf::Clock clock; // Clock to track time that instructions are displayed for
        sf::RenderWindow& window; // reference to the main window 
        sf::Font font; // text font 
        sf::Text text; // instructions to display
        sf::Text heading; // Instructions Heading
    public:

        /// @brief Constructor to intitialize Instructions
        /// @param window main window to render instructions on
        Instructions(sf::RenderWindow& window);

        /// @brief Function to check if time is up, yeah dont question the naming
        /// @return returns true if credits have passed
        bool update();

        /// @brief For restarting the clock 
        void instructionClockRestart();

        /// @brief Display Instructions Heading and Text
        void draw();
};