#include "Instructions.hpp"


Instructions::Instructions(sf::RenderWindow& window) : window(window), text(font), heading(font)
{
    clock.start();
    // Initialize font
    if (!font.openFromFile("../resources/Fonts/Blacknorthdemo-mLE25.otf")) {
        std::cerr << "Error: Could not load font.\n";
        exit(1);
    }
    
    // Initialize text
    heading.setString(
        "Instructions:\n\n\n"
    );
    text.setString(
        "W , A , S , D  keys to move the player.\n\n\n"
        "\t\t\t\tSPACEBAR to Attack.\n\n\n"
        "\t\t\t\t\t\t\tP to Pause"
    );

    heading.setCharacterSize(42);
    heading.setFillColor(sf::Color(255, 170, 43)); // Orange color
    heading.setStyle(sf::Text::Underlined);
    text.setCharacterSize(30);
    text.setFillColor(sf::Color(255, 170, 43)); // Orange color
    text.setStyle(sf::Text::Bold);
    
    sf::FloatRect headingRect = heading.getGlobalBounds();
    heading.setOrigin(sf::Vector2f(headingRect.position.x + headingRect.size.x / 2.0f, headingRect.position.y + headingRect.size.y / 2.0f));
    
    sf::FloatRect textRect = text.getGlobalBounds();
    text.setOrigin(sf::Vector2f(textRect.position.x + textRect.size.x / 2.0f, textRect.position.y + textRect.size.y / 2.0f));
    text.setPosition(sf::Vector2f(window.getView().getSize().x / 2.0f, window.getView().getSize().y / 2.0f + textRect.size.y / 2));

    heading.setPosition(sf::Vector2f( text.getPosition().x , text.getPosition().y - textRect.size.y));

    heading.setScale(sf::Vector2f(1.0f, 1.0f));
    text.setScale(sf::Vector2f(1.0f, 1.0f));
}

bool Instructions::update()
{
    if (clock.getElapsedTime().asSeconds() > 8){
        return true;
    }
    return false;
}

void Instructions::instructionClockRestart()
{
    clock.restart();
}   

void Instructions::draw() 
{
    window.draw(heading);
    window.draw(text);
}
