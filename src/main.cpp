#include <SFML/Graphics.hpp>
#include "levels.cpp"
#include "constants.cpp"

int main(){

    Level level;
    level.LoadLevel(LEVEL_1);

    // INITIALIZE
    sf::RenderWindow window(sf::VideoMode(sf::Vector2u(LEVEL_WIDTH * TILE_SIZE * scale, LEVEL_HEIGHT * TILE_SIZE * scale)), "Final Standoff");
    sf::Clock clock;
    window.setFramerateLimit(60);
    window.setVerticalSyncEnabled(true);

    while (window.isOpen()){
        // INITIALIZE (LOOP)
        window.clear();     // clearing the window each frame
        level.render(window); // rendering the level

        while (const std::optional event = window.pollEvent()){
            if (event->is<sf::Event::Closed>()){
                window.close();
            }
        }
        
        // UPDATE
        sf::Time timer = clock.restart();
        float deltaTime = timer.asMilliseconds();

        // DRAW

        // DEINITIALIZE
        
        window.display();   // displaying the window (important)
        
     
    }
}