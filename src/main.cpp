#include <SFML/Graphics.hpp>
#include "levels.cpp"
#include "constants.cpp"

int main(){

    // INITIALIZE GAME

    sf::RenderWindow window(sf::VideoMode(sf::Vector2u(LEVEL_WIDTH * TILE_SIZE * SCALE, LEVEL_HEIGHT * TILE_SIZE * SCALE)), "Final Standoff");
    Floor floor;
    Map map;
    // Prop props;  
    floor.LoadFloor(0);    // Game Starts at Level 0, then 1, then finally, 2
    map.LoadMap();         // Walls

    sf::Clock clock;
    int framecounter = 0;
    window.setFramerateLimit(60);  // Max FrameRate set to 60 

    while (window.isOpen()){
        // INITIALIZE (LOOP)
        framecounter++; // count frames...


        while (const std::optional event = window.pollEvent()){
            if (event->is<sf::Event::Closed>()){        // if the user closes the window
                window.close();
            }
        }
        
        // UPDATE
        sf::Time timer = clock.restart();
        float deltaTime = timer.asMilliseconds(); // get the time since last frame in milliseconds


        // DRAW
        window.clear();     // clearing the window each frame
        floor.Render(window); // rendering the level
        map.Render(window); // rendering the map
        // render characters here
        

        window.display();   // displaying the window (important)
    }
        // DEINITIALIZE GAME


        return 0;
}