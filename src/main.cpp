#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include "levels.cpp"
#include "constants.cpp"
#include "sounds.cpp"
#include "fullscreen.cpp"
#include "timer.cpp"
#include "Character.cpp"
#include "ScreenManager.hpp"
#include "ScreenManager.cpp"
#include "Crawl.cpp"
#include "Credits.cpp"

enum GameScreen{NARRATIVE, MENU, LEVEL1, LEVEL2, LEVEL3, DEATHMATCH, PAUSE, GAMEOVER, CREDITS};

int main(){

    // INITIALIZE GAME
    GameScreen currentScreen = NARRATIVE; // Show OpeningCrawl first
    GameScreen prevScreen = currentScreen;
    Floor floor;
    Map map;
    Prop prop;
    Character player;
    Character player2; // for deathmatch
    MenuMusic menubgm;
    BackGroundMusic bgm;
    Timer timer;
    sf::Clock clock;
    std::vector<Enemy> Enemies;
    
    int LevelNumber = 0;
    bool isFullScreen = true;
    bool isPause = false;
    
    createWindow(isFullScreen); // Create window in fullscreen mode
    OpeningCrawl crawl(window);
    CreditsCrawl credits(window);
    ScreenManager screenHandle;
    screenHandle.initialize(window);
    
    window.setFramerateLimit(60);  // Max FrameRate set to 60 
    int framecounter = 0;
    menubgm.LoadMusic();
    menubgm.play();
    sf::RectangleShape testenemyspawn;
    testenemyspawn.setSize(EnemySpawns[2][0].size);
    testenemyspawn.setFillColor(sf::Color::Blue);
    testenemyspawn.setPosition(EnemySpawns[2][0].position);

    std::cout<<"Size: "<<testenemyspawn.getSize().x<<", "<<testenemyspawn.getSize().y<<std::endl;
    std::cout<<"Position: "<<testenemyspawn.getPosition().x<<", "<<testenemyspawn.getPosition().y<<std::endl;

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
            if(event->is<sf::Event::KeyPressed>() && event->getIf<sf::Event::KeyPressed>()->code == sf::Keyboard::Key::P){
                if(currentScreen == LEVEL1 || currentScreen == LEVEL2 || currentScreen == LEVEL3){
                    if(!isPause){
                        isPause = true;
                        timer.pause();
                        prevScreen = currentScreen;
                        currentScreen = PAUSE;
                    }
                }
            }
        }
        
        { // UPDATE
            switch(currentScreen){
                case NARRATIVE:
                {
                    if(crawl.update(clock.restart().asSeconds()) || sf::Keyboard::isKeyPressed(sf::Keyboard::Scancode::Enter)){
                        window.clear(sf::Color::Black);
                        screenHandle.initialize(window);
                        currentScreen = MENU;
                    }
                }
                    break;
                case MENU: // process menu events here
                {
                    bool startgame = false, exitgame = false;
                    screenHandle.handleStartScreenInput(window, startgame, exitgame);
                    if(startgame){
                        menubgm.stop();
                        floor.Load(LevelNumber);       // Levels
                        map.Load(LevelNumber);            // Walls
                        prop.Load(LevelNumber);          // Props
                        bgm.LoadMusic(LevelNumber);            // Music
                        timer.LoadTimer(window, LevelNumber);   // Timer
                        player.Load(LevelNumber);                // Player
                        Enemies = spawnEnemiesForLevel(LevelNumber, map.GetMapCollisionRects()); // Enemies

                        bgm.play();
                        currentScreen = LEVEL1;
                    } else if(exitgame){
                        window.close();
                    }  
                }
                    break;
                case LEVEL1:
                    if(player.movetoNextLevel() == false){
                        float deltaTime = 0.f;
                        deltaTime = clock.restart().asSeconds(); // get the time since last frame in seconds
                        timer.update(window);
                        player.update(deltaTime, map.GetMapCollisionRects(), prop, window, Enemies);
                        for(auto& enemy : Enemies){
                            enemy.update(deltaTime, map.GetMapCollisionRects(), player.getHitboxBounds());
                        }
                        if(player.isPlayerDead() || timer.isTimeUp()){
                            Enemies.clear();
                            bgm.stop();
                            // load gameover screen here
                            currentScreen = GAMEOVER;
                        }
                    } else{
                        LevelNumber = 1;
                        floor.Load(LevelNumber);       
                        map.Load(LevelNumber);           
                        prop.Load(LevelNumber);        
                        timer.LoadTimer(window, LevelNumber);
                        player.Load(LevelNumber);
                        Enemies.clear();
                        Enemies = spawnEnemiesForLevel(LevelNumber, map.GetMapCollisionRects());
                        currentScreen = LEVEL2;
                    }
                    break;
                case LEVEL2:
                    if(player.movetoNextLevel() == false){
                        float deltaTime = clock.restart().asSeconds(); // get the time since last frame in seconds
                        timer.update(window);
                        player.update(deltaTime, map.GetMapCollisionRects(), prop, window, Enemies);
                        for(auto& enemy : Enemies){
                            enemy.update(deltaTime, map.GetMapCollisionRects(), player.getHitboxBounds());
                        }
                        if(player.isPlayerDead() || timer.isTimeUp()){
                            Enemies.clear();
                            bgm.stop();
                            // load gameover screen here
                            currentScreen = GAMEOVER;
                        }
                    } else{
                        LevelNumber = 2;
                        bgm.stop();
                        floor.Load(LevelNumber);       
                        map.Load(LevelNumber);           
                        prop.Load(LevelNumber);        
                        bgm.LoadMusic(LevelNumber);         
                        timer.LoadTimer(window, LevelNumber);
                        player.Load(LevelNumber);
                        Enemies.clear();
                        Enemies = spawnEnemiesForLevel(LevelNumber, map.GetMapCollisionRects());
                        bgm.play();
                        currentScreen = LEVEL3;
                    }
                    break;
                case LEVEL3:
                    if(player.movetoNextLevel() == false){
                        float deltaTime = clock.restart().asSeconds(); // get the time since last frame in seconds
                        timer.update(window);
                        player.update(deltaTime, map.GetMapCollisionRects(), prop, window, Enemies);
                        for(auto& enemy : Enemies){
                            enemy.update(deltaTime, map.GetMapCollisionRects(), player.getHitboxBounds());
                        }
                        if(player.isPlayerDead() || timer.isTimeUp() ){
                            Enemies.clear();
                            bgm.stop();
                            // load gameover screen here
                            currentScreen = GAMEOVER;
                        }
                    } else{
                        LevelNumber = 0;
                        bgm.stop();
                        menubgm.play();
                        currentScreen = CREDITS;
                    }
                    break;
                case PAUSE:
                {
                    bool resumegame = false, exitgame = false;
                    screenHandle.handlePauseScreenInput(window, resumegame,exitgame);
                    if(resumegame){
                        isPause = false;
                        timer.unpause();
                        currentScreen = prevScreen;
                    } else if(exitgame){
                        Enemies.clear();
                        bgm.stop();
                        isPause = false;
                        menubgm.play();
                        currentScreen = MENU;
                        prevScreen = MENU;
                    }
                }
                    break;
                case DEATHMATCH: // optional at this point
                    break;
                case GAMEOVER:
                    break;
                case CREDITS:
                    if(credits.update(clock.restart().asSeconds())){
                        window.clear(sf::Color::Black);
                        screenHandle.initialize(window);
                        currentScreen = MENU;
                    }
                    break;
                default:
                    bgm.stop();
                    menubgm.play();
                    currentScreen = MENU;
                    return 0;
            }
        }
        
        {// DRAW
            window.clear(sf::Color::Black);     // clearing the window each frame
            switch(currentScreen){
                case NARRATIVE:
                    crawl.draw();
                    break;
                case MENU: // draw menu stuff here
                    screenHandle.renderStartScreen(window);
                    break;
                case LEVEL1:
                    floor.Render(window); // rendering the level
                    map.Render(window); // rendering the map
                    prop.Render(window); // rendering the props
                    timer.render(window); // render the timer
                    player.draw(window); // rendering the player
                    for (auto& enemy : Enemies) { // rendering enemies
                        enemy.draw(window);
                    }
                    break;
                case LEVEL2:
                    floor.Render(window); // rendering the level
                    map.Render(window); // rendering the map
                    prop.Render(window); // rendering the props
                    timer.render(window); // render the timer
                    player.draw(window); // rendering the player
                    for (auto& enemy : Enemies) { // rendering enemies
                        enemy.draw(window);
                    }
                    break;
                case LEVEL3:
                    floor.Render(window); // rendering the level
                    map.Render(window); // rendering the map
                    prop.Render(window); // rendering the props
                    timer.render(window); // render the timer
                    player.draw(window); // rendering the player
                    for (auto& enemy : Enemies) { // rendering enemies
                        enemy.draw(window);
                    }
                    window.draw(testenemyspawn);
                    break;
                case PAUSE:
                    if(prevScreen == LEVEL1 || prevScreen == LEVEL2 || prevScreen == LEVEL3) {
                        floor.Render(window); // rendering the level
                        map.Render(window); // rendering the map
                        prop.Render(window); // rendering the props
                        timer.render(window); // render the timer
                        player.draw(window); // rendering the player
                    }
                    screenHandle.renderPauseScreen(window);
                    break;
                case DEATHMATCH:
                    break;
                case GAMEOVER:
                    break;
                case CREDITS:
                    credits.draw();
                    break; 
            }
            testenemyspawn.setOutlineColor(sf::Color::Red);
            testenemyspawn.setOutlineThickness(2.f);
            window.display();   // displaying the window (important)
        }

        // DEINITIALIZE (LOOP), if needed

    }
    // DEINITIALIZE GAME


        return 0;
}