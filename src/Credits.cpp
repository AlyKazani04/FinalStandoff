#include <SFML/Graphics.hpp>
#include <iostream>
#include <string>

// Class to handle the opening crawl animation
class CreditsCrawl {
public:
    CreditsCrawl(sf::RenderWindow& window) : window(window), text(font){
        clock.start();
        // Initialize font
        if (!font.openFromFile("../resources/Fonts/Blacknorthdemo-mLE25.otf")) {
            std::cerr << "Error: Could not load font.\n";
            exit(1);
        }
        
        // Initialize text
        text.setString(
            "\t\t\t\t\t\t\t\t\t\t\"You need to know, What\'s most reliable is your own strength.\n\n\n"
            "\t\t\t\t\t\t\t\t\t\t\t\t\tAnd without strength, freedom is just an illusion.\"\n\n\n\n\n\n\n\n\n"
            "Team Lead / Lead Dev : Aly Muhammad Rahim Kazani \n\n\n\n"
            "Character and FrontEnd Dev / Second in lead : Syed Abrar Shah\n\n\n\n"
            "Enemy Handling : Izaan Khan\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n"
            "Note from the developers : \n\n\n\n"
            "This game is a practice project for Object Oriented Programming at FAST-NUCES, Karachi\n\n"
            "and is not intended for commercial use.\n"
        );
        text.setCharacterSize(28);
        text.setFillColor(sf::Color(255, 255, 0)); 
        text.setStyle(sf::Text::Bold);
        
        // Position text at bottom and rotate
        sf::FloatRect textRect = text.getGlobalBounds();
        text.setOrigin(sf::Vector2f(textRect.position.x + textRect.size.x / 2.0f, textRect.position.y + textRect.size.y / 2.0f));
        text.setPosition(sf::Vector2f(window.getView().getSize().x / 2.0f, window.getView().getSize().y + textRect.size.y / 2.5f));
        text.setScale(sf::Vector2f(1.0f, 0.8f));
    }

    bool update(float deltaTime) {
        sf::Vector2f position = text.getPosition();
        position.y -= (speed * 0.6) * deltaTime;
        text.setPosition(position);
        if (clock.getElapsedTime().asSeconds() > 32){
            return true;
        }
        return false;
    }
    void creditsClockRestart(){
        clock.restart();
    }
    void draw() {
        window.draw(text);
    }

private:
    sf::Clock clock;
    sf::RenderWindow& window;
    sf::Font font;
    sf::Text text;
    const float speed = 100.0f; // Speed of the crawl in pixels per second
};
