#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include "levels.cpp"
#include "constants.cpp"
#include "sounds.cpp"

int main(){

    // INITIALIZE GAME

    sf::RenderWindow window(sf::VideoMode(sf::Vector2u(LEVEL_WIDTH * TILE_SIZE * SCALE, LEVEL_HEIGHT * TILE_SIZE * SCALE)), "Final Standoff");
    Floor floor;
    Map map;
    Props prop;
    BackGroundMusic bgm;

    floor.LoadFloor(0);    // Game Starts at Level 0, then 1, then finally, 2
    map.LoadMap(0);         // Walls
    prop.LoadProps(0);       // Props

    window.setFramerateLimit(60);  // Max FrameRate set to 60 
    int framecounter = 0;
    bgm.setVolume(70);
    bgm.play();

    sf::Clock clock;

    while (window.isOpen()){
        // INITIALIZE (LOOP)
        framecounter++; // count frames...


        while (const std::optional event = window.pollEvent()){
            if (event->is<sf::Event::Closed>()){        // if the user closes the window
                bgm.stop(); // stop the music
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
        prop.Render(window); // rendering the props
        // render characters here
        

        window.display();   // displaying the window (important)
    }
        // DEINITIALIZE GAME


        return 0;
}