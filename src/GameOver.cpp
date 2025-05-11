#include <SFML/Graphics.hpp>
#include <string>
#include <iostream>
#include "constants.cpp"

class GameOver{
    private:
        sf::Font font;
        sf::Text gameOverText;
        sf::Text coinsText;
        sf::Text buttonText;
        sf::Texture buttonTexture;
        sf::Sprite buttonSprite;
        int coins = 0;

    public:
        GameOver(sf::RenderWindow& window) : gameOverText(font), coinsText(font), buttonText(font), 
        buttonSprite([&]() -> sf::Texture& {
            if (!buttonTexture.loadFromFile(BUTTON_PATH)) {
                std::cerr << "Failed to load button image!\n";
                exit(1);
            }
            return buttonTexture;
        }())
      {

            if (!font.openFromFile(FONT_PATH)) {
                std::cerr << "Failed to load font!\n";
                exit(1);
            }

            gameOverText.setString("Game Over");
            gameOverText.setCharacterSize(72);
            gameOverText.setFillColor(sf::Color::Yellow);
            sf::FloatRect goBounds = gameOverText.getLocalBounds();
            gameOverText.setOrigin(sf::Vector2f(goBounds.position.x + goBounds.size.x / 2.0f, goBounds.position.y + goBounds.size.y / 2.0f));
            gameOverText.setPosition(sf::Vector2f(window.getView().getSize().x / 2.0f, window.getView().getSize().y / 2.0f - 100));


            coinsText.setString("Coins: " + std::to_string(coins));
            coinsText.setCharacterSize(36);
            coinsText.setFillColor(sf::Color::Red);
            sf::FloatRect coinsBounds = coinsText.getLocalBounds();
            coinsText.setOrigin(sf::Vector2f(coinsBounds.position.x + coinsBounds.size.x / 2.0f, coinsBounds.position.y + coinsBounds.size.y / 2.0f));
            coinsText.setPosition(sf::Vector2f(window.getView().getSize().x / 2.0f, window.getView().getSize().y / 2.0f));

            if (!buttonTexture.loadFromFile(BUTTON_PATH)) {
                std::cerr << "Failed to load button image!\n";
                exit(1);
            }

            buttonSprite.setTexture(buttonTexture);
            float buttonScale = 4.0f;
            buttonSprite.setScale(sf::Vector2f(buttonScale, buttonScale));
            sf::FloatRect buttonBounds = buttonSprite.getLocalBounds();
            buttonSprite.setOrigin(sf::Vector2f( buttonBounds.size.x / 2.0f, buttonBounds.size.y / 2.0f));
            buttonSprite.setPosition(sf::Vector2f(window.getView().getSize().x / 2.0f, window.getView().getSize().y / 2.0f + 100));

            buttonText.setFont(font);
            buttonText.setString("Menu");
            buttonText.setCharacterSize(32);
            buttonText.setFillColor(sf::Color::White);
            sf::FloatRect btBounds = buttonText.getLocalBounds();
            buttonText.setOrigin(sf::Vector2f(btBounds.position.x + btBounds.size.x / 2.0f, btBounds.position.y + btBounds.size.y / 2.0f));
            buttonText.setPosition(buttonSprite.getPosition());
        }

        bool update(sf::RenderWindow& window) {
            sf::Vector2f mousePos = window.mapPixelToCoords(sf::Mouse::getPosition(window));
            sf::FloatRect btnRect = buttonSprite.getGlobalBounds();
            if (btnRect.contains(mousePos) && sf::Mouse::isButtonPressed(sf::Mouse::Button::Left)) {
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

        void draw(sf::RenderWindow& window) {
                window.draw(gameOverText);
                window.draw(coinsText);
                window.draw(buttonSprite);
                window.draw(buttonText);
        }
};
