#include "fullscreen.hpp"

sf::Vector2u baseresolution = sf::Vector2u(LEVEL_WIDTH * TILE_SIZE * SCALE, LEVEL_HEIGHT * TILE_SIZE * SCALE);
sf::Vector2f baseresolutionbutfloat = sf::Vector2f(LEVEL_WIDTH * TILE_SIZE * SCALE, LEVEL_HEIGHT * TILE_SIZE * SCALE);

void createWindow(sf::RenderWindow& window, bool fullscreen) 
{

    if (fullscreen) 
    {
        sf::VideoMode desktop = sf::VideoMode::getDesktopMode();
        window.create(desktop, "Final Standoff", sf::Style::None);

    } 
    else{
        sf::Image icon(windowIconPath);

        window.create(sf::VideoMode(baseresolution), "Final Standoff", sf::Style::Default);

        window.setIcon(icon.getSize(), icon.getPixelsPtr());
    }

    // Setting view
    sf::View view(sf::FloatRect(sf::Vector2f(0, 0), baseresolutionbutfloat));
    
    view.setViewport(sf::FloatRect({0.f, 0.f}, {1.f, 1.f})); // Stretch
    window.setView(view);
    
    // Ensure cursor is visible after window creation
    window.setMouseCursorVisible(true);
}