#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include "levels.cpp"
#include "constants.cpp"
#include "sounds.cpp"
#include "fullscreen.cpp"
#include "timer.cpp"
#include "Character.cpp"

enum GameScreen{MENU, LEVEL1, LEVEL2, LEVEL3, DEATHMATCH, PAUSE, GAMEOVER, CREDITS};

int main(){

    // INITIALIZE GAME
    GameScreen currentScreen = MENU; // Show Menu first
    Floor floor;
    Map map;
    Props prop;
    Character player;
    BackGroundMusic bgm;
    Timer timer;
    sf::Clock clock;

    int LevelNumber = 1;
    bool isFullScreen = true;

    createWindow(isFullScreen); // Create window in fullscreen mode
    floor.LoadFloor(LevelNumber);       // Game Starts at Level 0, then 1, then finally, 2
    map.LoadMap(LevelNumber);            // Walls
    prop.LoadProps(LevelNumber);          // Props
    bgm.LoadMusic(LevelNumber);            // Music
    timer.LoadTimer(window, LevelNumber);   // Timer
    player.Load(LevelNumber);                // Player
    
    window.setFramerateLimit(60);  // Max FrameRate set to 60 
    int framecounter = 0;
    bgm.play();


    while (window.isOpen()){
        // INITIALIZE (LOOP)
        framecounter++; // count frames...
        while (const std::optional event = window.pollEvent()){
            if (event->is<sf::Event::Closed>()){ 
                bgm.stop(); // stop the music

                window.close();
            }
            if(event->is<sf::Event::KeyPressed>() && event->getIf<sf::Event::KeyPressed>()->code == sf::Keyboard::Key::Escape && isFullScreen == true){ // toggle windowed mode
                isFullScreen = false;
                createWindow(isFullScreen);
            }
            if(event->is<sf::Event::KeyPressed>() && event->getIf<sf::Event::KeyPressed>()->code == sf::Keyboard::Key::F11 && isFullScreen == false){ // toggle fullscreen mode
                isFullScreen = true;
                createWindow(isFullScreen);
            }
        }
        
        // UPDATE
        float deltaTime = clock.restart().asSeconds(); // get the time since last frame in seconds
        timer.update(window);
        if(timer.isTimeUp()){
            timer.reset();
        }
        player.update(deltaTime, map.GetMapCollisionRects(), prop);
        
        
        // DRAW
        window.clear();     // clearing the window each frame

        floor.Render(window); // rendering the level
        map.Render(window); // rendering the map
        prop.Render(window); // rendering the props
        timer.render(window); // render the timer
        player.draw(window); // rendering the player
        

        window.display();   // displaying the window (important)


        // DEINITIALIZE (LOOP), if needed

    }
    // DEINITIALIZE GAME


        return 0;
}