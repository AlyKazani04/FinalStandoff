#include <SFML/Graphics.hpp>
#include <cmath>
#include <iostream>
#include <vector>
#include <algorithm>
#include "constants.cpp"
// Constants
const float CHARACTER_SPEED = 5.0f;
const float ENEMY_SPEED = 3.0f;
const float FOLLOW_DISTANCE = 200.0f; // Distance at which enemy starts following
const float ATTACK_DISTANCE = 50.0f;  // Distance at which enemy can attack
const float OBSTACLE_AVOIDANCE_DISTANCE = 50.0f; // Distance at which enemy starts avoiding obstacles
const int MAP_WIDTH = 22;  // Width of the map (in tiles)
const int MAP_HEIGHT = 15; // Height of the map (in tiles)
const float WINDOW_WIDTH = MAP_WIDTH * TILE_SIZE * SCALE;
const float WINDOW_HEIGHT = MAP_HEIGHT * TILE_SIZE * SCALE;
int map[MAP_WIDTH][MAP_HEIGHT];

void initializeMap() {
    for (int i = 0; i < MAP_WIDTH; i++) {
        for (int j = 0; j < MAP_HEIGHT; j++) {
            map[i][j] = FLOORS[0][j][i]; // Assigning data from the first floor
        }
    }
}

// Obstacle class
class Obstacle {
public:
    Obstacle(float x, float y, float width, float height)
        : position(x, y)
        , size(width, height)
    {
        shape.setSize(size);
        shape.setFillColor(sf::Color(100, 100, 100));
        shape.setPosition(position);
    }

    void draw(sf::RenderWindow& window) {
        window.draw(shape);
    }

    sf::FloatRect getBounds() const {
        return shape.getGlobalBounds();
    }

    sf::Vector2f getPosition() const {
        return position;
    }

    sf::Vector2f getSize() const {
        return size;
    }

private:
    sf::Vector2f position;
    sf::Vector2f size;
    sf::RectangleShape shape;
};

// Character class
class Character {
public:
    Character(float x, float y) 
        : position(x, y)
        , size(40.0f, 40.0f)
        , health(100)
        , isAlive(true)
    {
        shape.setSize(size);
        shape.setFillColor(sf::Color::Blue);
        shape.setPosition(position);
    }

    void move(const sf::Vector2f& direction) {
        if (!isAlive) return;
        
        position += direction * CHARACTER_SPEED;
        
        // Keep character within window bounds
        if (position.x < 0) position.x = 0;
        if (position.y < 0) position.y = 0;
        if (position.x > WINDOW_WIDTH - size.x) position.x = WINDOW_WIDTH - size.x;
        if (position.y > WINDOW_HEIGHT - size.y) position.y = WINDOW_HEIGHT - size.y;
        
        shape.setPosition(position);
    }

    void takeDamage(int amount) {
        if (!isAlive) return;
        
        health -= amount;
        if (health <= 0) {
            health = 0;
            isAlive = false;
            shape.setFillColor(sf::Color::Red);
        }
    }

    void draw(sf::RenderWindow& window) {
        window.draw(shape);
        
        // Draw health bar
        sf::RectangleShape healthBar;
        healthBar.setSize(sf::Vector2f(size.x, 5.0f));
        healthBar.setPosition(sf::Vector2f(position.x, position.y - 10.0f));
        healthBar.setFillColor(sf::Color::Red);
        
        sf::RectangleShape healthFill;
        healthFill.setSize(sf::Vector2f(size.x * (health / 100.0f), 5.0f));
        healthFill.setPosition(sf::Vector2f(position.x, position.y - 10.0f));
        healthFill.setFillColor(sf::Color::Green);
        
        window.draw(healthBar);
        window.draw(healthFill);
    }

    sf::Vector2f getPosition() const { return position; }
    bool isCharacterAlive() const { return isAlive; }
    sf::FloatRect getBounds() const { return shape.getGlobalBounds(); }

private:
    sf::Vector2f position;
    sf::Vector2f size;
    sf::RectangleShape shape;
    int health;
    bool isAlive;
};

// Enemy class
class Enemy {
public:
    Enemy(float x, float y) 
        : position(x, y)
        , size(30.0f, 30.0f)
        , health(50)
        , isAlive(true)
        , attackCooldown(0)
    {
        shape.setSize(size);
        shape.setFillColor(sf::Color::Red);
        shape.setPosition(position);
    }

    void update(Character& character, const std::vector<Obstacle>& obstacles) {
        if (!isAlive || !character.isCharacterAlive()) return;
        
        // Calculate distance to character
        sf::Vector2f characterPos = character.getPosition();
        float dx = characterPos.x - position.x;
        float dy = characterPos.y - position.y;
        float distance = std::sqrt(dx * dx + dy * dy);
        
        // If within follow distance, move towards character
        if (distance < FOLLOW_DISTANCE) {
            // Calculate direction to character
            sf::Vector2f direction(0, 0);
            if (distance > 0) {
                direction.x = dx / distance;
                direction.y = dy / distance;
            }
            
            // Check for obstacles and adjust direction
            sf::Vector2f adjustedDirection = avoidObstacles(direction, obstacles);
            
            // Move towards character with adjusted direction
            position.x += adjustedDirection.x * ENEMY_SPEED;
            position.y += adjustedDirection.y * ENEMY_SPEED;
            shape.setPosition(position);
            
            // Attack if close enough and cooldown is ready
            if (distance < ATTACK_DISTANCE && attackCooldown <= 0) {
                attack(character);
                attackCooldown = 60; // 1 second at 60 FPS
            }
        }
        
        // Update attack cooldown
        if (attackCooldown > 0) {
            attackCooldown--;
        }
    }

    sf::Vector2f avoidObstacles(const sf::Vector2f& direction, const std::vector<Obstacle>& obstacles) {
        sf::Vector2f adjustedDirection = direction;
        
        // Check each obstacle
        for (const auto& obstacle : obstacles) {
            sf::FloatRect obstacleBounds = obstacle.getBounds();
            
            // Calculate distance to obstacle
            float obstacleCenterX = obstacleBounds.position.x + obstacleBounds.size.x / 2;
            float obstacleCenterY = obstacleBounds.position.y + obstacleBounds.size.y / 2;
            
            float dx = obstacleCenterX - position.x;
            float dy = obstacleCenterY - position.y;
            float distance = std::sqrt(dx * dx + dy * dy);
            
            // If obstacle is within avoidance distance
            if (distance < OBSTACLE_AVOIDANCE_DISTANCE) {
                // Calculate avoidance direction (away from obstacle)
                sf::Vector2f avoidanceDir;
                if (distance > 0) {
                    avoidanceDir.x = -dx / distance;
                    avoidanceDir.y = -dy / distance;
                } else {
                    avoidanceDir = sf::Vector2f(1, 0); // Default direction if distance is 0
                }
                
                // Blend original direction with avoidance direction
                // The closer to the obstacle, the stronger the avoidance
                float avoidanceStrength = 1.0f - (distance / OBSTACLE_AVOIDANCE_DISTANCE);
                avoidanceStrength = std::pow(avoidanceStrength, 2); // Square it for more aggressive avoidance
                
                adjustedDirection.x = adjustedDirection.x * (1.0f - avoidanceStrength) + avoidanceDir.x * avoidanceStrength;
                adjustedDirection.y = adjustedDirection.y * (1.0f - avoidanceStrength) + avoidanceDir.y * avoidanceStrength;
                
                // Normalize the adjusted direction
                float length = std::sqrt(adjustedDirection.x * adjustedDirection.x + adjustedDirection.y * adjustedDirection.y);
                if (length > 0) {
                    adjustedDirection.x /= length;
                    adjustedDirection.y /= length;
                }
            }
        }
        
        return adjustedDirection;
    }

    void takeDamage(int amount) {
        if (!isAlive) return;
        
        health -= amount;
        if (health <= 0) {
            health = 0;
            isAlive = false;
            shape.setFillColor(sf::Color(100, 100, 100)); // Gray when dead
        }
    }

    void draw(sf::RenderWindow& window) {
        window.draw(shape);
        
        // Draw health bar
        sf::RectangleShape healthBar;
        healthBar.setSize(sf::Vector2f(size.x, 5.0f));
        healthBar.setPosition(sf::Vector2f(position.x, position.y - 10.0f));
        healthBar.setFillColor(sf::Color::Red);
        
        sf::RectangleShape healthFill;
        healthFill.setSize(sf::Vector2f(size.x * (health / 50.0f), 5.0f));
        healthFill.setPosition(sf::Vector2f(position.x, position.y - 10.0f));
        healthFill.setFillColor(sf::Color::Yellow);
        
        window.draw(healthBar);
        window.draw(healthFill);
    }

    bool isEnemyAlive() const { return isAlive; }
    sf::FloatRect getBounds() const { return shape.getGlobalBounds(); }

private:
    void attack(Character& character) {
        character.takeDamage(10);
    }

    sf::Vector2f position;
    sf::Vector2f size;
    sf::RectangleShape shape;
    int health;
    bool isAlive;
    int attackCooldown;
};

std::vector<Obstacle> generateObstaclesFromMap() {
    std::vector<Obstacle> obstacles;
    for (int i = 0; i < MAP_WIDTH; ++i) {
        for (int j = 0; j < MAP_HEIGHT; ++j) {
            // Check if the tile is a wall or obstacle (non-zero values in FLOORS array)
            if (FLOORS[0][j][i] >= 1) { // Using first floor (index 0)
                obstacles.push_back(Obstacle(i * TILE_SIZE * SCALE, j * TILE_SIZE * SCALE, 
                                          TILE_SIZE * SCALE, TILE_SIZE * SCALE));
            }
        }
    }
    return obstacles;
}

int main() {

    initializeMap();

    // Create window
    sf::RenderWindow window(sf::VideoMode({800, 600}), "Character and Enemy Interaction");
    window.setFramerateLimit(60);
    
    // Create character and enemy
    Character character(WINDOW_WIDTH / 2, WINDOW_HEIGHT / 2);
    Enemy enemy(100, 100);
    
    // Create obstacles
    std::vector<Obstacle> obstacles = generateObstaclesFromMap();
    
    // Game loop
    while (window.isOpen()) {
        while (const auto event = window.pollEvent()) {
            if (event->is<sf::Event::Closed>()) {
                window.close();
            }
        }
        
        // Handle input
        sf::Vector2f movement(0, 0);
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Scancode::W)) movement.y -= 1;
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Scancode::S)) movement.y += 1;
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Scancode::A)) movement.x -= 1;
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Scancode::D)) movement.x += 1;
        
        // Normalize diagonal movement
        if (movement.x != 0 && movement.y != 0) {
            float length = std::sqrt(movement.x * movement.x + movement.y * movement.y);
            movement.x /= length;
            movement.y /= length;
        }
        
        // Move character
        character.move(movement);
        
        // Update enemy with obstacles
        enemy.update(character, obstacles);
        
        // Render
        window.clear(sf::Color(50, 50, 50));
        
        // Draw obstacles
        for (auto& obstacle : obstacles) {
            obstacle.draw(window);
        }
        
        // Draw character and enemy
        character.draw(window);
        enemy.draw(window);
        
        // Draw instructions
        sf::Font font;
        if (font.openFromFile("../resources/Fonts/Blacknorthdemo-mLE25.otf")) {
            sf::Text instructions(font, "WASD to move, Enemy follows when close");
            instructions.setCharacterSize(20);
            instructions.setFillColor(sf::Color::White);
            instructions.setPosition(sf::Vector2f(10, 10));
            window.draw(instructions);
        }
        
        window.display();
    }
    
    return 0;
}