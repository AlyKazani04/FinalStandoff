#pragma once

#include <SFML/Graphics.hpp>
#include <iostream>
#include "../Constants/constants.hpp"
#include <string>

class ScreenManager
{
    public:
        // Constructor and destructor
        ScreenManager();
        ~ScreenManager();

        // Initialize the screen manager with the window
        bool initialize(sf::RenderWindow& window);
        
        // Load screens
        bool loadStartScreen(sf::RenderWindow& window);
        bool loadPauseScreen(sf::RenderWindow& window);

        // Render screens
        void renderStartScreen(sf::RenderWindow& window);
        void renderPauseScreen(sf::RenderWindow& window);
        
        // Handle input
        bool handleStartScreenInput(sf::RenderWindow& window, bool& startGame, bool& credits, bool& exitGame);
        bool handlePauseScreenInput(sf::RenderWindow& window, bool& resumeGame, bool& exitGame);

    private:
        // Resources
        sf::Font m_font;
        sf::Texture m_titleBoxTexture;
        sf::Texture m_buttonTexture;
        
        // Start screen elements
        sf::Text m_startTitle;
        sf::Sprite m_startTitleBox;
        sf::RectangleShape m_startPlayButton;
        sf::RectangleShape m_startExitButton;
        sf::Text m_startPlayText;
        sf::Text m_startExitText;
        sf::RectangleShape m_startCreditsButton;
        sf::Text m_startCreditsText;

        // Pause screen elements
        sf::RectangleShape darkbg;
        sf::Text m_pauseTitle;
        sf::Sprite m_pauseTitleBox;
        sf::RectangleShape m_pauseResumeButton;
        sf::RectangleShape m_pauseExitButton;
        sf::Text m_pauseResumeText;
        sf::Text m_pauseExitText;

        // Helper methods
        bool loadResources();
        bool setupStartScreen(sf::RenderWindow& window);
        bool setupPauseScreen(sf::RenderWindow& window);
}; 
