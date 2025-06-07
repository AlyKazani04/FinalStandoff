#pragma once

#include <SFML/Graphics.hpp>
#include <iostream>
#include <string>
#include "../../Constants/constants.hpp"

class OpeningCrawl{
    private:
        sf::Clock clock; // Clock to manage crawl speed
        sf::RenderWindow& window; // reference to main window
        sf::Font font; // text font
        sf::Text text; // text to display
        const float speed = 100.0f; // Speed of the crawl in pixels per second
    public:

        /// @brief Constructor to initialise OpeningCrawl
        /// @param window window for rendering Opening Crawl on
        OpeningCrawl(sf::RenderWindow& window);

        /// @brief Updates position of the Crawl text
        /// @param deltaTime for consistent movement speed
        /// @return returns true if credits finished scrolling
        bool update(float deltaTime);

        /// @brief Draw the Crawl
        void draw();
};