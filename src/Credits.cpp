#include <SFML/Graphics.hpp>
#include <iostream>
#include <string>

// Class to handle the opening crawl animation
class CreditsCrawl {
public:
    CreditsCrawl(sf::RenderWindow& window) : window(window), text(font), coinsText(font) {
        // Initialize font
        if (!font.openFromFile("../resources/Fonts/Blacknorthdemo-mLE25.otf")) {
            std::cerr << "Error: Could not load font.\n";
            exit(1);
        }

        coinsText.setString("Coins: " + std::to_string(coins));
        coinsText.setCharacterSize(36);
        coinsText.setFillColor(sf::Color(255, 255, 0));
        coinsText.setStyle(sf::Text::Bold);


        
        // Initialize text
        text.setString(
            "\t\t\t\t\t\t\t\t\t\t\"You need to know, What\'s most reliable is your own strength.\n\n\n"
            "\t\t\t\t\t\t\t\t\t\t\t\t\tAnd without strength, freedom is just an illusion.\"\n\n\n\n\n\n\n\n\n"
            "Team Lead / Lead Dev : \tAly Muhammad Rahim Kazani \n\n\n\n"
            "Character and FrontEnd Dev : \tSyed Abrar Shah\n\n\n\n"
            "Enemy Handling : \tIzaan Khan\n\n\n\n\n\n\n\n\n\n\n\n\n\n"
            "Note from the developers : \n\n\n\n"
            "\"Hey! This is the Final Standoff development team, and we wanted\n\n"
            "to take a moment to thank you for playing! \n\n"
            "We poured our hearts into this game and we will always\n\n"
            "be working on making it even better.\n\n"
            "Keep an eye out for future updates and feel free to share your thoughts with us!\"\n\n\n\n\n\n"
            "This game is a practice project for Object Oriented Programming at FAST-NUCES, Karachi\n\n"
            "and is not intended for commercial use.\n"
        );
        text.setCharacterSize(28);
        text.setFillColor(sf::Color(255, 255, 0)); 
        text.setStyle(sf::Text::Bold);
        
        // Position text at bottom
        sf::FloatRect textRect = text.getGlobalBounds();
        text.setOrigin(sf::Vector2f(textRect.position.x + textRect.size.x / 2.0f, textRect.position.y + textRect.size.y / 2.0f));
        text.setPosition(sf::Vector2f(window.getView().getSize().x / 2.0f, window.getView().getSize().y + textRect.size.y / 2));
        text.setScale(sf::Vector2f(1.0f, 0.8f));

        sf::FloatRect coinsBounds = coinsText.getGlobalBounds();
        coinsText.setOrigin({coinsBounds.position.x + coinsBounds.size.x / 2.0f, coinsBounds.position.y + coinsBounds.size.y / 2.0f});
        coinsText.setPosition(sf::Vector2f(window.getView().getSize().x / 2, textRect.position.y - 50));
        coinsText.setScale({1, 0.8f});
    }

    void load(){
        clock.restart();

        sf::FloatRect textRect = text.getLocalBounds();
        text.setOrigin(sf::Vector2f(textRect.position.x + textRect.size.x / 2.0f, textRect.position.y + textRect.size.y / 2.0f));
        text.setPosition(sf::Vector2f(window.getView().getSize().x / 2.0f, window.getView().getSize().y + textRect.size.y / 2));
        text.setScale(sf::Vector2f(1.0f, 0.8f));

        sf::FloatRect coinsBounds = coinsText.getLocalBounds();
        coinsText.setOrigin({coinsBounds.position.x + coinsBounds.size.x / 2.0f, coinsBounds.position.y + coinsBounds.size.y / 2.0f});
        coinsText.setPosition(sf::Vector2f(window.getView().getSize().x / 2, window.getView().getSize().y / 2));
        coinsText.setScale({1, 0.8f});
    }

    bool update(float deltaTime) {
        sf::Vector2f position = text.getPosition();
        sf::Vector2f coinsposition = coinsText.getPosition();
        position.y -= (speed * 0.6) * deltaTime;
        coinsposition.y -= (speed * 0.6) * deltaTime;
        text.setPosition(position);
        coinsText.setPosition(coinsposition);
        if (clock.getElapsedTime().asSeconds() > 36){
            return true;
        }
        return false;
    }

    void saveCoins(int val){
        coins += val;
        coinsText.setString("Coins: " + std::to_string(coins));

        sf::FloatRect coinsBounds = coinsText.getLocalBounds();
        coinsText.setOrigin({coinsBounds.position.x + coinsBounds.size.x / 2.0f, coinsBounds.position.y + coinsBounds.size.y / 2.0f});
    }

    void draw() {
        window.draw(text);
        if(coins > 0){
            window.draw(coinsText);
        }
    }

private:
    sf::Clock clock;
    sf::RenderWindow& window;
    sf::Font font;
    sf::Text text;
    const float speed = 100.0f; // Speed of the crawl in pixels per second
    int coins = 0;
    sf::Text coinsText;
};
