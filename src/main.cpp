#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>

#include "Constants/constants.hpp"

#include "Sound/sound.hpp"

#include "UI/timer.hpp"
#include "UI/ScreenManager.hpp"
#include "UI/fullscreen.hpp"
#include "UI/Instructions.hpp"
#include "UI/GameOver.hpp"

#include "UI/Crawls/OpeningCrawl.hpp"
#include "UI/Crawls/Credits.hpp"

#include "Levels/levels.hpp"

#include "Character/Character.hpp"
#include "Enemy/enemy.hpp"

enum GameScreen{NARRATIVE, MENU, SETTINGS, INSTRUCTIONS, LEVEL1, LEVEL2, LEVEL3, DEATHMATCH, PAUSE, GAMEOVER, CREDITS};

int main(){

    // INITIALIZE GAME
    sf::RenderWindow window;

    GameScreen currentScreen = NARRATIVE; // Show Narrative first
    GameScreen prevScreen = currentScreen;
    Floor floor;
    Map map;
    Prop prop;
    Character player;
    BackGroundMusic bgm;
    Timer timer;
    sf::Clock clock;
    std::vector<Enemy> Enemies;
    sf::Clock inputCooldown;
    std::fstream file(coinsFile, std::ios::out); // file to save coins
    if(!file.is_open()){
        std::cerr << "Error opening file" << std::endl;
        return 1;
    }
    bool inputBlocked = false;
    
    int LevelNumber = 0;
    bool isFullScreen = true;
    bool isPause = false;
    
    createWindow(window, isFullScreen); // Create window in fullscreen mode
    OpeningCrawl crawl(window);
    CreditsCrawl credits(window);
    Instructions instructions(window);
    GameOver gameOver(window);
    ScreenManager screenHandle;
    screenHandle.initialize(window);

    sf::Image Menu_BG(MENU_IMAGE);
    sf::Texture Menu_Texture;
    sf::RectangleShape windowRect;
    sf::Image GameOver_BG(GAMEOVER_IMAGE);
    sf::Texture GameOver_Texture;
    sf::RectangleShape GameOver_Rect;
    if(!Menu_Texture.loadFromImage(Menu_BG)){
        std::cerr << "Menu Image didn't load" << std::endl;
    }
    if(!GameOver_Texture.loadFromImage(GameOver_BG)){
    std::cerr << "Game Over Image didn't load" << std::endl;
    }
    windowRect.setTexture(&Menu_Texture);
    GameOver_Rect.setTexture(&GameOver_Texture);
    
    window.setFramerateLimit(60);  // Max FrameRate set to 60 
    bgm.LoadMenuMusic();
    bgm.play();
    srand(4);

    while (window.isOpen()){
        // INITIALIZE (LOOP)
        while (const std::optional event = window.pollEvent()){
            if (event->is<sf::Event::Closed>()){ 
                bgm.stop(); // stop the music
                file << player; // save coins to file
                file.close();
                window.close();
            }
            if(event->is<sf::Event::KeyPressed>() && event->getIf<sf::Event::KeyPressed>()->code == sf::Keyboard::Key::Escape && isFullScreen == true){ // toggle windowed mode
                isFullScreen = false;
                createWindow(window, isFullScreen);
            }
            if(event->is<sf::Event::KeyPressed>() && event->getIf<sf::Event::KeyPressed>()->code == sf::Keyboard::Key::F11 && isFullScreen == false){ // toggle fullscreen mode
                isFullScreen = true;
                createWindow(window, isFullScreen);
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
                    if(crawl.update(clock.restart().asSeconds())){
                        window.clear(sf::Color::Black);
                        screenHandle.initialize(window);
                        currentScreen = MENU;
                    }
                }
                    break;
                case MENU: // process menu events here
                {
                    windowRect.setSize(window.getView().getSize());
                    window.setMouseCursorVisible(true);

                    prevScreen = MENU;
                    if (inputBlocked && inputCooldown.getElapsedTime().asSeconds() < 0.3f)
                        break; // Skip handling input if cooldown is active
                    inputBlocked = false; // Reset after cooldown passes

                    bool startgame = false, iscredits = false, exitgame = false;
                    screenHandle.handleStartScreenInput(window, startgame, iscredits, exitgame);
                    if(startgame){
                        instructions.instructionClockRestart();
                        currentScreen = INSTRUCTIONS;
                    }
                    if(iscredits){
                        credits.load();
                        clock.restart();
                        currentScreen = CREDITS;
                    }
                    if(exitgame){
                        file << player; // save coins to file
                        file.close();
                        window.close();
                    }  
                }
                break;
                case INSTRUCTIONS:
                {
                    if(instructions.update()){
                        bgm.stop();
                        floor.Load(LevelNumber);       // Levels
                        map.Load(LevelNumber);            // Walls
                        prop.Load(LevelNumber);          // Props
                        bgm.LoadGameMusic(LevelNumber);            // Music
                        timer.loadTimer(window, LevelNumber);   // Timer
                        player.Load(LevelNumber);                // Player
                        Enemies = spawnEnemiesForLevel(LevelNumber, map.GetMapCollisionRects()); // Enemies

                        currentScreen = LEVEL1;
                        bgm.play();                        
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
                            bgm.LoadMenuMusic();
                            bgm.play();
                            file << player;
                            gameOver.saveCoins(player.getCoinCount());
                            currentScreen = GAMEOVER;
                        }
                    } else{
                        LevelNumber = 1;
                        floor.Load(LevelNumber);       
                        map.Load(LevelNumber);           
                        prop.Load(LevelNumber);        
                        timer.loadTimer(window, LevelNumber);
                        player.Load(LevelNumber);
                        Enemies.clear();
                        Enemies = spawnEnemiesForLevel(LevelNumber, map.GetMapCollisionRects());
                        gameOver.saveCoins(player.getCoinCount());
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
                            bgm.LoadMenuMusic();
                            bgm.play();
                            file << player;
                            gameOver.saveCoins(player.getCoinCount());
                            currentScreen = GAMEOVER;
                        }
                    } else{
                        LevelNumber = 2;
                        bgm.stop();
                        floor.Load(LevelNumber);       
                        map.Load(LevelNumber);           
                        prop.Load(LevelNumber);        
                        bgm.LoadGameMusic(LevelNumber);         
                        timer.loadTimer(window, LevelNumber);
                        player.Load(LevelNumber);
                        Enemies.clear();
                        Enemies = spawnEnemiesForLevel(LevelNumber, map.GetMapCollisionRects());
                        gameOver.saveCoins(player.getCoinCount());
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
                            bgm.LoadMenuMusic();
                            bgm.play();
                            file << player;
                            gameOver.saveCoins(player.getCoinCount());
                            currentScreen = GAMEOVER;
                        }
                    } else{
                        LevelNumber = 0;
                        bgm.stop();
                        bgm.LoadMenuMusic();
                        bgm.play();
                        credits.load();
                        file << player;
                        credits.saveCoins(player.getCoinCount());
                        clock.restart();
                        currentScreen = CREDITS;
                    }
                    break;
                case PAUSE:
                {
                    bool resumegame = false, backtomenu = false;
                    screenHandle.handlePauseScreenInput(window, resumegame,backtomenu);
                    if(resumegame){
                        isPause = false;
                        timer.unpause();
                        currentScreen = prevScreen;
                    } else if(backtomenu){
                        Enemies.clear();
                        bgm.stop();
                        bgm.LoadMenuMusic(); // load menu music
                        bgm.play();

                        inputBlocked = true; // block input for a small time to prevent multiple calls to exit
                        inputCooldown.restart();
                        isPause = false;
                        currentScreen = MENU;
                        prevScreen = MENU;
                    }
                }
                    break;
                case DEATHMATCH: // optional at this point
                    break;
                case GAMEOVER:
                    GameOver_Rect.setSize(window.getView().getSize());
                    if(gameOver.update(window)){
                        inputBlocked = true; // block input for a small time to prevent multiple calls to exit
                        inputCooldown.restart();
                        currentScreen = MENU;
                        prevScreen = MENU;
                    }                
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
                    bgm.LoadMenuMusic(); // load menu music
                    bgm.play();
                    currentScreen = MENU;
                    file << player;
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
                    window.draw(windowRect);
                    screenHandle.renderStartScreen(window);
                    break;
                case INSTRUCTIONS:
                    instructions.draw();
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
                    break;
                case PAUSE:
                    if(prevScreen == LEVEL1 || prevScreen == LEVEL2 || prevScreen == LEVEL3) {
                        floor.Render(window); // rendering the level
                        map.Render(window); // rendering the map
                        prop.Render(window); // rendering the props
                        timer.render(window); // render the timer
                        player.draw(window); // rendering the player
                        for (auto& enemy : Enemies) { // rendering enemies
                            enemy.draw(window);
                        }
                    }
                    screenHandle.renderPauseScreen(window);
                    break;
                case DEATHMATCH:
                    break;
                case GAMEOVER:
                    window.draw(GameOver_Rect);
                    gameOver.draw(window);
                    break;
                case CREDITS:
                    credits.draw();
                    break; 
            }
            window.display();   // displaying the window (important)
        }

        // DEINITIALIZE (LOOP), if needed

    }
    // DEINITIALIZE GAME

    file.close();
    return 0;
}