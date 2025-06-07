#pragma once

#include <SFML/Graphics.hpp>
#include <algorithm>
#include "../Constants/constants.hpp"

class Timer
{
    private:
        sf::FloatRect rect; // timer bounds
        sf::RectangleShape bar; // timer bar
        sf::Clock clock; // clock to track time
        float totalTime; // in seconds
        int levelNumber; // current level
    public:
        Timer();

        /// @brief function to initialize timer for a level
        /// @param window window to set timer according to
        /// @param level level number to set timer for
        void loadTimer(sf::RenderWindow& window,int level);

        /// @brief function that updates timer bar
        /// @param window window size required
        void update(sf::RenderWindow& window);
        
        /// @brief function to draw timer bar
        /// @param window window to draw timer on
        void render(sf::RenderWindow& window);


        /// @brief function to reset the timer
        void reset(); // reset timer 
        
        /// @brief function to check if time is up
        /// @return returns true if time up, false otherwise
        bool isTimeUp();

        /// @brief function for pausing timer
        void pause();

        /// @brief function for unpausing timer
        void unpause();
};