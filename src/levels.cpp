#include <SFML/Graphics.hpp>
#include <iostream>
#include "constants.cpp"

class Level {
    private:
        sf::Texture tileTexture; // tile texture
        const int (*currentLevel)[LEVEL_WIDTH]; // Pointer to the current level array

    public:
        Level() {
            // Load the tile texture
            if (!tileTexture.loadFromFile("../resources/1_MiniDungeon_Tileset_Background1.png")) {
                std::cout << "Texture didn't load successfully!\n";
            } else{ std::cout << "Texture loaded successfully!\n"; }
            tileTexture.setSmooth(false);
            // tileTexture[1].setSmooth(false);

            currentLevel = LEVEL_1;
        }

        void LoadLevel(const int NewLevel[LEVEL_HEIGHT][LEVEL_WIDTH]) {
            currentLevel = NewLevel;
        }

        void render(sf::RenderWindow& window) {

            sf::Sprite tileSprite(tileTexture);
            int tilesetColumns = 8; // Number of tiles in a row of the PNG

            for (int y = 0; y < LEVEL_HEIGHT; ++y) {
                for (int x = 0; x < LEVEL_WIDTH; ++x) {
                    int tiletype = currentLevel[y][x];

                    // Compute row and column in the tileset
                    int tileX = (tiletype % tilesetColumns) * TILE_SIZE;
                    int tileY = (tiletype / tilesetColumns) * TILE_SIZE;
                    sf::IntRect tilerect({tileX, tileY}, {TILE_SIZE, TILE_SIZE});
                    tileSprite.setTextureRect(tilerect);
                    tileSprite.setScale({scale, scale});
                    tileSprite.setPosition(sf::Vector2f((float)(x * TILE_SIZE * scale), (float)(y * TILE_SIZE * scale)));
                    window.draw(tileSprite);
                }
            }
        }
        ~Level(){}
};

// int main() {
//     sf::RenderWindow window(sf::VideoMode(sf::Vector2u(LEVEL_WIDTH * TILE_SIZE * scale, LEVEL_HEIGHT * TILE_SIZE * scale)), "2D Top-Down Level");

//     Level level;

//     while (window.isOpen()) {
//         int framecounter = 0;
//         while (auto event = window.pollEvent()) { // Corrected SFML 3.0 event handling
//             if (event->is<sf::Event::Closed>())
//                 window.close();
//         }
//         framecounter++;
//         window.clear();
//         level.LoadLevel(LEVEL_1);
//         level.render(window);
//         window.display();
//     }

//     return 0;
// }
