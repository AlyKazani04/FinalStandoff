#pragma once

#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include <vector>
#include <string>
#include <fstream>
#include <iostream>
#include "../Constants/constants.hpp"
#include "../Enemy/enemy.hpp"

class Character
{
    private:
        sf::Sprite sprite;
        sf::Texture spriteSheet;
        std::vector<sf::IntRect> idleFrontFrames;
        std::vector<sf::IntRect> idleRightFrames;
        std::vector<sf::IntRect> idleBackFrames;
        std::vector<sf::IntRect> moveFrontFrames;
        std::vector<sf::IntRect> moveRightFrames;
        std::vector<sf::IntRect> moveBackFrames;
        std::vector<sf::IntRect> attackFrontFrames;
        std::vector<sf::IntRect> attackRightFrames;
        std::vector<sf::IntRect> attackBackFrames;
        std::vector<sf::IntRect> deathFrames;
        sf::Clock clock;
        sf::RectangleShape hitbox;
        sf::RectangleShape attack_hitbox;
        sf::RectangleShape front_hitbox;
        sf::RectangleShape side_hitbox;
        bool hasHit = false;

        //sound variables
        std::vector<sf::SoundBuffer> attackBuffers;
        sf::SoundBuffer deathBuffer;
        std::vector<sf::SoundBuffer> walkBuffers;
        std::vector<sf::SoundBuffer> damageBuffers;
        sf::SoundBuffer coinBuffer;
        std::vector<sf::Sound> attackSound;
        std::vector<sf::Sound> deathSound;
        std::vector<sf::Sound> walkSound;
        std::vector<sf::Sound> damageSound;
        std::vector<sf::Sound> coinSound;
        sf::Clock walkSoundClock;
        sf::Time walkSoundCooldown = sf::milliseconds(300);
        int lastWalkSoundIndex = -1;

        // animation variables
        sf::Time frameDuration = sf::seconds(0.1f); // in seconds, 0.1secs; 10fps
        int currentFrame;
        int currentAnimation;
        int currentDirection;  // 0: front, 1: right, 2: back
        bool isFacingRight;
        bool isDead = false;
        bool isAttacking = false;
        
        int LevelNumber;

        // Health bar shapes
        sf::RectangleShape healthBarBackground;
        sf::RectangleShape healthBarFill;

        // logic variables
        float Health = MAX_HEALTH;
        int Coins = 0;
        const float attackDamage = 20;
        bool KeyCollected = false;
        bool movetonextlevel = false;
        sf::Clock deathTimer;
        bool deathAnimationFinished = false;
        sf::Color spritecolor;
        sf::Clock damageCooldownClock;
        sf::Time damageCooldown = sf::milliseconds(500); // 0.5 second invulnerability after hit
        // text variables
        sf::Clock doorTextTimer;
        sf::Text doorClosedText;
        sf::Font font;
        bool showDoorClosedText = false;
        sf::Time timeSinceTextShown;
        bool gameRestarted = false;
        
    public:

        enum AnimationState
        {
            IDLE = 0,
            MOVE = 1,
            ATTACK = 2,
            DEATH = 3
        };

        enum Direction
        {
            FRONT = 0,
            RIGHT = 1,
            BACK = 2
        };

        /// @brief friend function to overload << operator to save coins to file
        /// @param file 
        /// @param player 
        /// @return 
        friend std::fstream& operator<<(std::fstream& file, Character& player);

        Character();

        void Load(int level);

        void update(float deltaTime, const std::vector<sf::FloatRect>& mapRects, Prop& prop, sf::RenderWindow& window, std::vector<Enemy>& enemies);

        void updateHealthBar();

        void move(float x, float y);

        void draw(sf::RenderWindow& window);

        void playWalkSound();

        //getters
        float getCurrentHealth() const;

        int getCoinCount() const;
        
        sf::FloatRect getBounds() const;

        sf::FloatRect getHitboxBounds() const;

        void takeDamage(int dmg);

        sf::Vector2f getPosition() const;

        Direction getLastDirection() const;

        //return flags

        bool isPlayerDead();

        bool movetoNextLevel();

    private:
        Direction lastDirection = FRONT; // store last direction

        std::vector<sf::IntRect>& getCurrentAnimationFrames();

        void setAnimation(AnimationState animation, Direction direction);

        void setLastDirection(Direction dir);
};

inline std::fstream& operator<<(std::fstream& file, Character& player)
{ 
    file << "Coins: " << player.getCoinCount();
    return file;
}