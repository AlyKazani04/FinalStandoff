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
            "Freedom is an illusion, Dantes shall return once again to hell\n\n\n\n\n\n\n\n\n\n"
            "Team Lead / Lead Developer : Aly Muhammad Rahim Kazani \n\n"
            "Animations and Character developer / Second in lead : Syed Abrar Shah\n\n"
            "Izaan Khan : Izaan Khan\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n"
            "Note from the developers : \n\n\n\n"
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
        position.y -= (speed * 0.5) * deltaTime;
        text.setPosition(position);
        // std::cout<<"Time: "<<clock.getElapsedTime().asSeconds()<<"seconds"<<std::endl;  // debugging viewing time
        if (clock.getElapsedTime().asSeconds() > 15){
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
