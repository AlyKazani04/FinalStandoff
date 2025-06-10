#pragma once

#include <SFML/Graphics.hpp>
#include <iostream>
#include "../Constants/constants.hpp"

class Layout
{
    protected:
        sf::Texture texture;
        int (*layout)[LEVEL_WIDTH];// pointer to tile ids
        int LevelNumber = 0;
    public:
        Layout() = default;

        // getter
        int getTileID(int x, int y);

        virtual void Load(const int level) =0;
        virtual void Render(sf::RenderWindow& window) =0;

        ~Layout(){}
};


class Prop : public Layout
{
    private:
        sf::FloatRect propsprites[LEVEL_WIDTH][LEVEL_HEIGHT] = {sf::FloatRect({0,0},{TILE_SIZE, TILE_SIZE})}; // for each props, size and position, to calc collision 
        sf::RectangleShape door_hitbox; // door bounds for collision
        
    public:
        Prop();

        /// @brief checks if the tile is collidable
        /// @param tile tile ID to check
        /// @return returns true if tile ID is collidable (coin, key or door)
        bool isCollidable(int tile) const;

        /// @brief sets tile to an empty tile
        /// @param x x position of the tile
        /// @param y y position of the tile
        void collectTile(int x, int y);

        /// @brief checks if player rectangle intersects witht the door
        /// @param rect player rectangle
        /// @return returns true if rectangle intersects with door hitbox
        bool isDoor(sf::FloatRect rect) const;

        /// @brief function to get all collidable prop tiles
        /// @return returns a vector of float rects (bounds of collidable props)
        std::vector<sf::FloatRect> GetPropCollisionRects() const;

        /// @brief function to initialise props for the level
        /// @param level level number
        virtual void Load(const int level) override;

        /// @brief function to display props on the screen
        /// @param window window to render props on
        virtual void Render(sf::RenderWindow& window) override;
};

class Map : public Layout
{
    private:
        sf::FloatRect mapsprites[LEVEL_WIDTH][LEVEL_HEIGHT];  // Array of map sprite bounds for wall collisions
    public:

    Map();

    /// @brief function to get all collidable map tiles aka walls 
    /// @return vector of wall bounds
    std::vector<sf::FloatRect> GetMapCollisionRects() const;

    /// @brief takes the level number and loads the corresponding map
    /// @param level Level number
    void Load(const int level) override;

    /// @brief function to display map on the screen
    /// @param window window to display map on
    void Render(sf::RenderWindow& window) override;
};

class Floor : public Layout
{
    private:
        sf::Texture lavaTexture; // lava tile texture
        const int (*LavaPointer)[LEVEL_WIDTH]; // Pointer to the Lava array

        // Animated Lava variables
        sf::Clock lavaAnimClock; // clock for lava animation
        sf::Time lavaFrameDuration = sf::milliseconds(200); // 5 fps
        int currentlavaframe = 0; // current lava frame
        
        /// @brief updates the lava animation frames
        void LavaAnimUpdate();
        
    public:
        Floor();

        /// @brief takes the level number and loads the corresponding level
        /// @param level level number
        void Load(const int level) override;

        /// @brief function to display floor to the screen
        /// @param window window to display the floor on
        /// @note this function also displays animated lava if the level is 2
        void Render(sf::RenderWindow& window) override;

};