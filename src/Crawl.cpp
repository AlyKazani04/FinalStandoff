#include <SFML/Graphics.hpp>
#include <iostream>
#include <string>
#include "constants.cpp"

// Class to handle the opening crawl animation
class OpeningCrawl {
public:
    OpeningCrawl(sf::RenderWindow& window) : window(window), text(font){
        clock.start();
        // Initialize font
        if (!font.openFromFile(FONT_PATH)) {
            std::cerr << "Error: Could not load font.\n";
            exit(1);
        }
        
        // Initialize text
        text.setString(
            "If you shall call me to shake hands with you in hell I shan't dissapoint you...\n\n"
            "Prisoner Name : Dante Alighieri \n\n"
            "Prisoner Number : 666\n\n"
            "Reason for detention : Mockery of the devil\n\n"
            "Hearing date : He who wishes to make fun of the devil shall find his way to himself\n\n\n\n"
            "Dragged into hell\n\n"
            "Dare you point towards the heavens\n\n"
            "For all there is to point is nothing but burning ashes of those that dared before him\n\n\n"
            "Now suffer and suffer\n\n"
            "For there is no destination but only the journey of suffering\n\n\n"
            "A dance with the devil is what you have brought upon yourself\n\n"
            "A tango shall be performed\n\n"
            "To death we shall go\n\n"
            "Hand in hand, from one accursed to another\n\n\n"
            "Shall we?\n\n"
            "A final standoff with the devil himself"
        );
        text.setCharacterSize(28);
        text.setFillColor(sf::Color(255, 255, 0)); // Yellow color
        text.setStyle(sf::Text::Bold);
        
        // Position text at bottom and rotate
        sf::FloatRect textRect = text.getGlobalBounds();
        text.setOrigin(sf::Vector2f(textRect.position.x + textRect.size.x / 2.0f, textRect.position.y + textRect.size.y / 2.0f));
        text.setPosition(sf::Vector2f(window.getView().getSize().x / 2.0f, window.getView().getSize().y + textRect.size.y / 2.0f));
        text.setScale(sf::Vector2f(1.0f, 0.8f));
    }

    bool update(float deltaTime) {
        sf::Vector2f position = text.getPosition();
        position.y -= (speed * 0.5f) * deltaTime;
        text.setPosition(position);
        // std::cout<<"Time: "<<clock.getElapsedTime().asSeconds()<<"seconds"<<std::endl;  // debugging viewing time
        if (clock.getElapsedTime().asSeconds() > 38.5f){
            return true;
        }
        return false;
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
