#pragma once

#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include <vector>
#include <cmath>
#include <iostream>
#include <random>
#include "../Constants/constants.hpp"
#include "../Levels/levels.hpp"

sf::Texture& getGlobalTexture();

class Enemy 
{
    private:
        sf::Sprite sprite;
        sf::Texture idleTexture;
        sf::Texture attackTexture;
        sf::Texture moveTexture;
        sf::Texture deathTexture;
        sf::Texture damageTexture;
        
        std::vector<sf::IntRect> idleFrames;
        std::vector<sf::IntRect> attackFrames;
        std::vector<sf::IntRect> moveFrames;
        std::vector<sf::IntRect> deathFrames;
        std::vector<sf::IntRect> damageFrames;
        
        //sound variables
        std::vector<sf::SoundBuffer> attackBuffers;
        std::vector<sf::Sound> attackSound;
        std::vector<sf::SoundBuffer> enemyDamageBuffers;
        std::vector<sf::Sound> enemyDamageSound;
        sf::SoundBuffer deathBuffer;
        std::vector<sf::Sound> deathSound;

        // Health bar shapes
        sf::RectangleShape healthBarBackground;
        sf::RectangleShape healthBarFill;
        float maxHealth;
        float currentHealth;

        //hitbox
        sf::RectangleShape hitbox;

        sf::Time frameDuration = sf::seconds(0.1f); // in seconds, 0.1secs; 10fps
        int currentFrame;
        int currentAnimation;
        bool isFacingRight;
        bool isDead;
        bool isAttacking;
        bool isTakingDamage;
        int LevelNumber;
        sf::Clock clock;
        sf::Clock deathTimer;
        bool deathAnimationFinished = false;

        std::vector<sf::IntRect>& getCurrentAnimationFrames();

        sf::Texture& getCurrentTexture();

    public:
        enum AnimationState 
        {
            IDLE = 0,
            MOVE = 1,
            ATTACK = 2,
            DEATH = 3,
            TAKE_DAMAGE = 4
        };

        Enemy();

        void load(int level);

        void update(float deltaTime, const std::vector<sf::FloatRect>& mapRects, sf::FloatRect target);

        void setAnimation(AnimationState animation);

        void move(float x, float y);

        void updateHealthBar();

        void takeDamage(float amount);

        void draw(sf::RenderWindow& window);

        float getDistancetoTarget(sf::Vector2f target);

        sf::Vector2f avoidWalls(const sf::Vector2f& directionToTarget, const std::vector<sf::FloatRect>& mapRects);

        sf::Vector2f getDirectiontoTarget(sf::Vector2f target);

        sf::FloatRect getBounds() const;

        sf::FloatRect getHitbox();

        sf::Vector2f getPosition() const;

        float getHealth() const;

        bool getisDead();

        bool getisAttacking();
};

/// @brief spawns enemies in random pre-specified areas
/// @param level 
/// @param mapRects 
/// @return returns a vector of enemies for a level 
std::vector<Enemy> spawnEnemiesForLevel(int level, const std::vector<sf::FloatRect>& mapRects);