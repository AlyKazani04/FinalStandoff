#include <SFML/Graphics.hpp>
#include "constants.cpp"

sf::RenderWindow window;
sf::Vector2u baseresolution = sf::Vector2u(LEVEL_WIDTH * TILE_SIZE * SCALE, LEVEL_HEIGHT * TILE_SIZE * SCALE);
sf::Vector2f baseresolutionbutfloat = sf::Vector2f(LEVEL_WIDTH * TILE_SIZE * SCALE, LEVEL_HEIGHT * TILE_SIZE * SCALE);

void createWindow(bool fullscreen) {
    if (fullscreen) {
        sf::VideoMode desktop = sf::VideoMode::getDesktopMode();
        window.create(desktop, "Final Standoff", sf::Style::None); // Borderless fullscreen
    } else {
        window.create(sf::VideoMode(baseresolution), "Final Standoff", sf::Style::Default);
    }

    // Set view if needed
    sf::View view(sf::FloatRect(sf::Vector2f(0, 0), baseresolutionbutfloat));
    view.setViewport(sf::FloatRect({0.f, 0.f}, {1.f, 1.f})); // Stretch
    window.setView(view);
}