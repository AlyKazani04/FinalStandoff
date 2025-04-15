#include <SFML/Graphics.hpp>
#include <iostream>
#include "constants.cpp"

class Props{
    private:
        sf::Texture propTexture; // prop texture
        int (*currentProps)[LEVEL_WIDTH]; // Pointer to the prop layout
        sf::FloatRect propsprites[LEVEL_WIDTH][LEVEL_HEIGHT]; // for each props, size and position, to calc collision 
        int LevelNumber;
    public:
        Props() : LevelNumber(0) {
            currentProps = PROPS[0];
        }
        void LoadProps(const int level){  //    takes the level number and loads the corresponding props layout
            LevelNumber = level;

            if (!propTexture.loadFromFile("../resources/Dungeon_16x16_asset_pack/tileset.png")) {
                std::cout << "Props didn't load successfully!\n";
            } 
            else { 
                std::cout << "Props loaded successfully!\n";
            }
            propTexture.setSmooth(false);

            currentProps = PROPS[LevelNumber];
        }
        void Render(sf::RenderWindow& window){
            sf::Sprite tempSprite(propTexture);

            for (int y = 0; y < LEVEL_HEIGHT; ++y) {
                for (int x = 0; x < LEVEL_WIDTH; ++x) {
                    int proptile = abs(currentProps[y][x]);

                    if(PROPS[LevelNumber][y][x] != 0){
                        if(abs(PROPS[LevelNumber][y][x]) == 33){ // torch lateral wall
                            if(PROPS[LevelNumber][y][x] == 33){ // torch on the left
                                // calculate prop sprite used from tile set
                                int proptileX = (proptile % maptilesetColumns) * TILE_SIZE;
                                int proptileY = (proptile / maptilesetColumns) * TILE_SIZE;
        
                                sf::IntRect proptilerect({proptileX, proptileY}, {TILE_SIZE, TILE_SIZE});
        
                                tempSprite.setTextureRect(proptilerect);
                                tempSprite.setScale({SCALE, SCALE});
                                float posx = x * TILE_SIZE * SCALE + (TILE_SIZE * SCALE) / 3;
                                float posy = y * TILE_SIZE * SCALE;
                                tempSprite.setPosition(sf::Vector2f(posx, posy));
                            } else{ // torch on the right
                                // calculate prop sprite used from tile set
                                int proptileX = (proptile % maptilesetColumns) * TILE_SIZE;
                                int proptileY = (proptile / maptilesetColumns) * TILE_SIZE;

                                sf::IntRect proptilerect({proptileX, proptileY}, {TILE_SIZE, TILE_SIZE});
                                
                                tempSprite.setTextureRect(proptilerect);
                                tempSprite.setScale({-SCALE, SCALE});
                                float torchx_displacement = (LevelNumber == 1 || LevelNumber == 0) ? (TILE_SIZE * SCALE) / 3 : 0 ;
                                float posx = (x + 1) * TILE_SIZE * SCALE - torchx_displacement;
                                float posy = y * TILE_SIZE * SCALE;
                                tempSprite.setPosition(sf::Vector2f(posx, posy));
                            }
                        }
                        // if(PROPS[LevelNumber][y][x] == 24){
                        //     if()

                        // }
                         else{
                            if(PROPS[LevelNumber][y][x] == 26){ // door
                                // calculate prop sprite used from tile set
                                int proptileX = (proptile % maptilesetColumns) * TILE_SIZE;
                                int proptileY = (proptile / maptilesetColumns) * TILE_SIZE;

                                sf::IntRect proptilerect({proptileX, proptileY}, {TILE_SIZE, TILE_SIZE});

                                tempSprite.setTextureRect(proptilerect);
                                tempSprite.setScale({SCALE, SCALE-1});
                                float posx = x * TILE_SIZE * SCALE + (TILE_SIZE * SCALE);
                                float posy = y * TILE_SIZE * (SCALE + 1);
                                tempSprite.setPosition(sf::Vector2f(posx, posy));
                            } else{ // for a collidable prop
                                // calculate prop sprite used from tile set
                                int proptileX = (proptile % maptilesetColumns) * TILE_SIZE;
                                int proptileY = (proptile / maptilesetColumns) * TILE_SIZE;

                                sf::IntRect proptilerect({proptileX, proptileY}, {TILE_SIZE, TILE_SIZE});

                                tempSprite.setTextureRect(proptilerect);
                                tempSprite.setScale({SCALE, SCALE});
                                float posx = x * TILE_SIZE * SCALE + (TILE_SIZE * SCALE);
                                float posy = y * TILE_SIZE * SCALE;
                                tempSprite.setPosition(sf::Vector2f(posx, posy));  

                                propsprites[x][y].position = tempSprite.getGlobalBounds().position;
                                propsprites[x][y].size = tempSprite.getGlobalBounds().size;
                            }
                        }
                    } else{ continue; }

                    window.draw(tempSprite);
                }
            }            
        }
        ~Props(){}
};

class Map {
    private:
        sf::Texture mapTexture; // map tile texture
        int (*currentMap)[LEVEL_WIDTH]; // Pointer to the current map array
        int LevelNumber; // Current level number

        sf::FloatRect mapsprites[LEVEL_WIDTH][LEVEL_HEIGHT];  // Array of map sprite bounds for wall collisions

    public:
        Map() : LevelNumber(0) {
            currentMap = MAPS[0];
        }

        sf::FloatRect getMapTileSprite(int index_X , int index_Y){ // returns the sprite of the map tile at the given index
            return mapsprites[index_X][index_Y];  
        };

        void LoadMap(const int level){  //    takes the level number and loads the corresponding map
            LevelNumber = level;
            if (!mapTexture.loadFromFile("../resources/Dungeon_16x16_asset_pack/tileset.png")) {
                std::cout << "Map didn't load successfully!\n";
            } 
            else { 
                std::cout << "Map loaded successfully!\n";
            }
            mapTexture.setSmooth(false);

            currentMap = MAPS[LevelNumber];
        }

        void Render(sf::RenderWindow& window){
            sf::Sprite tempSprite(mapTexture);

            for (int y = 0; y < LEVEL_HEIGHT; ++y) {
                for (int x = 0; x < LEVEL_WIDTH; ++x) {
                    int maptile = currentMap[y][x];

                    int maptileX = (maptile % maptilesetColumns) * TILE_SIZE;
                    int maptileY = (maptile / maptilesetColumns) * TILE_SIZE;

                    sf::IntRect maptilerect({maptileX, maptileY}, {TILE_SIZE, TILE_SIZE});

                    tempSprite.setTextureRect(maptilerect);
                    tempSprite.setScale({SCALE, SCALE});
                    tempSprite.setPosition(sf::Vector2f((float)(x * TILE_SIZE * SCALE), (float)(y * TILE_SIZE * SCALE)));

                    mapsprites[x][y].position = tempSprite.getGlobalBounds().position;
                    mapsprites[x][y].size = tempSprite.getGlobalBounds().size;

                    window.draw(tempSprite);
                }
            }            
        }

        ~Map(){}
};

class Floor {
    private:
        sf::Texture floorTexture; // floor tile texture
        sf::Texture lavaTexture; // lava tile texture
        const int (*currentFloor)[LEVEL_WIDTH]; // Pointer to the current floor array
        const int (*LavaPointer)[LEVEL_WIDTH]; // Pointer to the Lava array
        int LevelNumber; // current level number

        // Animated Lava Functionality
        sf::Clock lavaAnimClock;
        sf::Time lavaFrameDuration = sf::milliseconds(200); // 10 fps
        int currentlavaframe = 0;


        void LavaAnimUpdate(){
            if (lavaAnimClock.getElapsedTime() > lavaFrameDuration) {
                currentlavaframe = (currentlavaframe + 1) % lavatilesetColumns;
                lavaAnimClock.restart();
            }
        }
    public:
        Floor() : LevelNumber(0) {
            currentFloor = FLOORS[0];
            lavaAnimClock.start();
        }

        void LoadFloor(const int level) { //    takes the level number and loads the corresponding level
            if (level == 0 || level == 1) {
                LevelNumber = level;

                if (!floorTexture.loadFromFile("../resources/Mini_Dungeon_Tileset/FREE/1_MiniDungeon_Tileset_Background1.png")) {
                    std::cout << "Floor didn't load successfully!\n";
                } 
                else { 
                    std::cout << "Floor loaded successfully!\n"; 
                }
            }
            if(level == 2) {
                LevelNumber = level;
                if (!floorTexture.loadFromFile("../resources/Mini_Dungeon_Tileset/FREE/1_MiniDungeon_Tileset_Background1.png")) {
                    std::cout << "Floor didn't load successfully!\n";
                } 
                else { 
                    std::cout << "Floor loaded successfully!\n"; 
                }
                if (!lavaTexture.loadFromFile("../resources/Top_Down_Lava_Tileset_16x16_Free/FREE_TILESET_FILES/Environment(With_Animations)/Burning_Lava/spritesheet-burninglava.png")) {
                    std::cout << "Lava didn't load successfully!\n";
                } 
                else { 
                    std::cout << "Lava loaded successfully!\n"; 
                }
                LavaPointer = LAVA;
                lavaTexture.setSmooth(false);
            }
            floorTexture.setSmooth(false);
            
            
            currentFloor = FLOORS[LevelNumber];
        }

        void Render(sf::RenderWindow& window) {

            sf::Sprite floorSprite(floorTexture);
            sf::Sprite lavaSprite(lavaTexture);

            if(LevelNumber == 0 || LevelNumber == 1) {
                for (int y = 0; y < LEVEL_HEIGHT; ++y) {
                    for (int x = 0; x < LEVEL_WIDTH; ++x) {

                        int floortile = currentFloor[y][x];

                        // Calculate row and column in the tileset
                        int floortileX = (floortile % floortilesetColumns) * TILE_SIZE;
                        int floortileY = (floortile / floortilesetColumns) * TILE_SIZE;

                        sf::IntRect floortilerect({floortileX, floortileY}, {TILE_SIZE, TILE_SIZE});

                        floorSprite.setTextureRect(floortilerect);
                        floorSprite.setScale({SCALE, SCALE});
                        floorSprite.setPosition(sf::Vector2f((float)(x * TILE_SIZE * SCALE), (float)(y * TILE_SIZE * SCALE)));

                        window.draw(floorSprite);
                    }
                }
            }
            if(LevelNumber == 2){
                LavaAnimUpdate();
                for (int y = 0; y < LEVEL_HEIGHT; ++y) {
                    for (int x = 0; x < LEVEL_WIDTH; ++x) {
                        
                        int floortile = currentFloor[y][x]; // Floor tileID
                        int lavatile = LavaPointer[y][x]; // Lava tileID

    
                        // Calculate row and column in the tileset
                        int floortileX = (floortile % floortilesetColumns) * TILE_SIZE;
                        int floortileY = (floortile / floortilesetColumns) * TILE_SIZE;
    
                        sf::IntRect floortilerect({floortileX, floortileY}, {TILE_SIZE, TILE_SIZE});
    
                        floorSprite.setTextureRect(floortilerect);
                        floorSprite.setScale({SCALE, SCALE});
                        floorSprite.setPosition(sf::Vector2f((x * TILE_SIZE * SCALE), (y * TILE_SIZE * SCALE)));
    
                        window.draw(floorSprite);

                        if (lavatile != 3) { // if theres lava, 3 is empty
                            // Calculate row and column in the tileset
                            int lavaFrameWidth = TILE_SIZE * lavatilesetColumns; 
                            
                            int lavatileX = ((currentlavaframe) * lavaFrameWidth) + ((lavatile % lavatilesetColumns) * TILE_SIZE);
                            int lavatileY = (lavatile / lavatilesetColumns) * TILE_SIZE; // if lavatile values range above 6
            
                            sf::IntRect lavatilerRect({lavatileX, lavatileY}, {TILE_SIZE, TILE_SIZE});

                            lavaSprite.setTextureRect(lavatilerRect);
                            lavaSprite.setScale({SCALE, SCALE});
                            lavaSprite.setPosition(sf::Vector2f(x * TILE_SIZE * SCALE, y * TILE_SIZE * SCALE));

                            window.draw(lavaSprite);
                        }
                    }
                }
            }
        }
        ~Floor(){}
};

