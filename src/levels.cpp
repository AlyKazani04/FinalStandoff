#include <SFML/Graphics.hpp>
#include <iostream>
#include "constants.cpp"

class Level {
    private:
        sf::Texture tileTexture; // tile texture
        const int (*currentLevel)[LEVEL_WIDTH]; // Pointer to the current level array
        int LevelNumber; // current level number

    public:
        Level() {
            // Load the tile texture
            if (!tileTexture.loadFromFile("../resources/Mini_Dungeon_Tileset/FREE/1_MiniDungeon_Tileset_Background1.png")) {
                std::cout << "Texture didn't load successfully!\n";
            } else{ std::cout << "Texture loaded successfully!\n"; }
            tileTexture.setSmooth(false);
            // tileTexture[1].setSmooth(false);

            currentLevel = LEVELS[0];
        }

        void LoadLevel(const int level) { //    takes the level number and loads the corresponding level
            if (level >= 0 && level < NUMBER_OF_LEVELS) {
                LevelNumber = level;
                if ( level == 0) {
                    if (!tileTexture.loadFromFile("../resources/Mini_Dungeon_Tileset/FREE/1_MiniDungeon_Tileset_Background1.png")) {
                        std::cout << "Texture didn't load successfully!\n";
                    } 
                    else { 
                        std::cout << "Texture loaded successfully!\n"; 
                    }
                }
                if ( level == 1) {
                    if (!tileTexture.loadFromFile("../resources/Dungeon_16x16_asset_pack/tileset.png")) {
                        std::cout << "Texture didn't load successfully!\n";
                    } 
                    else { 
                        std::cout << "Texture loaded successfully!\n";
                    }
                }
                if ( level == 2) {

                }
                currentLevel = LEVELS[level];
            }
        }

        void render(sf::RenderWindow& window) {

            sf::Sprite tileSprite(tileTexture);

            for (int y = 0; y < LEVEL_HEIGHT; ++y) {
                for (int x = 0; x < LEVEL_WIDTH; ++x) {
                    int tiletype = currentLevel[y][x];

                    // Calculate row and column in the tileset
                    int tileX = (tiletype % tilesetColumns[LevelNumber]) * TILE_SIZE;
                    int tileY = (tiletype / tilesetColumns[LevelNumber]) * TILE_SIZE;
                    sf::IntRect tilerect({tileX, tileY}, {TILE_SIZE, TILE_SIZE});
                    tileSprite.setTextureRect(tilerect);
                    tileSprite.setScale({SCALE, SCALE});
                    tileSprite.setPosition(sf::Vector2f((float)(x * TILE_SIZE * SCALE), (float)(y * TILE_SIZE * SCALE)));
                    window.draw(tileSprite);
                }
            }
        }
        ~Level(){}
};

