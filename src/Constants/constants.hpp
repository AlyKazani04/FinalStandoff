#pragma once

#include <string>
#include <SFML/Graphics.hpp>

// Window Icon Path
inline const std::filesystem::path windowIconPath = "../resources/icon.png";

// tile constants

constexpr int TILE_SIZE = 16;           // Using 16 x 16 tiles for simplicity
constexpr int floortilesetColumns = 8;  // Number of tiles in a row of the floor PNG
constexpr int lavatilesetColumns = 7;   // Number of tiles in a row of the lava PNG
constexpr int maptilesetColumns = 6;    // Number of tiles in a row of the map PNG
constexpr int LEVEL_WIDTH = 22;         // Number of tiles in width
constexpr int LEVEL_HEIGHT = 15;        // Number of tiles in height
constexpr float SCALE = 4;              //scaling the window 
constexpr int NUMBER_OF_LEVELS = 3;     // Number of levels in the game

// sound paths

inline const std::filesystem::path MENU_MUSICPATH = "../resources/MainMenu.mp3";    // main menu music path
extern std::filesystem::path gamebgmpath[3];                                        // game background music paths for each level

// tile arrays

extern int FLOORS[NUMBER_OF_LEVELS][LEVEL_HEIGHT][LEVEL_WIDTH]; // floor tiles for each level
extern int LAVA[LEVEL_HEIGHT][LEVEL_WIDTH];                     // lava tiles for each level
extern int MAPS[NUMBER_OF_LEVELS][LEVEL_HEIGHT][LEVEL_WIDTH];   // map tiles for each level
extern int PROPS[NUMBER_OF_LEVELS][LEVEL_HEIGHT][LEVEL_WIDTH];  // prop tiles for each level (24 = coin, 26 = door, 33 = torch(sides), 32 = torch(front), 31 = key)

// Timer Constants

extern const sf::Time timers[3]; // Timers for each level (in seconds)

// Character Constants

inline const std::string coinsFile = "../resources/Coins.txt";  // file to save coins
constexpr float MAX_HEALTH = 100;                               // Max Health for Character & Enemies
constexpr int FRAME_WIDTH = 48;                                 // Using 48 x 48 frames for character sprites, ew
constexpr int FRAME_HEIGHT = 48;                                // Using 48 x 48 frames for character sprites, ew
constexpr int FRAMES_PER_ROW = 6;                               // Number of frames in each row
constexpr float character_SCALE = 4;                            // Scale of the character sprite

extern const sf::Vector2f characterSpawns[3];

// Enemy Constants

constexpr int ENEMY_FRAMES_PER_ROW = 9;                         // Number of frames in each row for enemy sprites
extern const sf::FloatRect EnemySpawns[NUMBER_OF_LEVELS][3];    // Areas where Enemy Spawn

// Menu Constants

inline const std::string MENU_IMAGE = "../resources/MainMenu.jpg";
inline const std::string GAMEOVER_IMAGE = "../resources/GameOver.jpg";
inline const std::string FONT_PATH = "../resources/Fonts/Blacknorthdemo-mLE25.otf";
inline const std::string TITLE_BOX_PATH = "../resources/MainMenuAssets/MenusBox_34x34.png";
inline const std::string BUTTON_PATH = "../resources/MainMenuAssets/Button_52x14.png";