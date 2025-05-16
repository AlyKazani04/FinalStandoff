#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include <vector>
#include <cmath>
#include <iostream>
#include <random>
#include "constants.cpp"
#include "levels.cpp"

sf::Texture& getGlobalTexture(){
    static sf::Texture texture;
    if(!texture.loadFromFile("../resources/player.png")){
        std::cerr << "Error loading texture" << std::endl;

    }
    texture.setSmooth(false);
    return texture;
}

class Enemy {
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
    public:
        enum AnimationState {
            IDLE = 0,
            MOVE = 1,
            ATTACK = 2,
            DEATH = 3,
            TAKE_DAMAGE = 4
        };

        Enemy() : currentFrame(0), currentAnimation(IDLE), 
                isFacingRight(true), isDead(false), isAttacking(false), isTakingDamage(false),
                sprite(getGlobalTexture()),
                maxHealth(100.f), currentHealth(100.f) {}

        void load(int level){


            // initialize enemy variables
            LevelNumber = level;
            currentHealth = MAX_HEALTH;
            isDead = false;
            isAttacking = false;
            currentFrame = 0;
            currentAnimation = IDLE;
            isFacingRight = true;

            // intialize sound buffers
            attackBuffers.resize(3);
            attackSound.clear();
            enemyDamageBuffers.resize(3);
            enemyDamageSound.clear();
            deathSound.clear();

            for (int i = 0; i < 3; ++i) {
                std::string path = "../resources/Minifantasy_Dungeon_SFX/17_orc_atk_sword_" + std::to_string(i + 1) + ".wav";
                if (attackBuffers[i].loadFromFile(path)) {
                    attackSound.emplace_back(attackBuffers[i]);
                    attackSound[i].setVolume(50);
                }
            }
            for (int i = 0; i < 3; ++i) {
                std::string path = "../resources/Minifantasy_Dungeon_SFX/21_orc_damage_" + std::to_string(i + 1) + ".wav";
                if (enemyDamageBuffers[i].loadFromFile(path)) {
                    enemyDamageSound.emplace_back(enemyDamageBuffers[i]);
                    enemyDamageSound[i].setVolume(60);
                }
            }
            if(deathBuffer.loadFromFile("../resources/Minifantasy_Dungeon_SFX/24_orc_death_spin.wav")){
                deathSound.emplace_back(deathBuffer);
                deathSound[0].setVolume(60);
            } else{
                std::cout << "Enemy death sound didnt load" << std::endl;
            }

            // Setup health bar
            float healthBarWidth = 50.f;
            float healthBarHeight = 5.f;
            
            healthBarBackground.setSize(sf::Vector2f(healthBarWidth, healthBarHeight));
            healthBarBackground.setFillColor(sf::Color(100, 100, 100)); // Dark gray background
            
            healthBarFill.setSize(sf::Vector2f(healthBarWidth, healthBarHeight));
            healthBarFill.setFillColor(sf::Color::Green);

            // Load all textures
            if (!idleTexture.loadFromFile("../resources/EnemyAnim/enemies-skeleton1_idle.png")) {
                std::cout << "Error loading enemy idle texture" << std::endl;
                return;
            }
            if (!attackTexture.loadFromFile("../resources/EnemyAnim/enemies-skeleton1_attack.png")) {
                std::cout << "Error loading enemy attack texture" << std::endl;
                return;
            }
            if (!moveTexture.loadFromFile("../resources/EnemyAnim/enemies-skeleton1_movement.png")) {
                std::cout << "Error loading enemy movement texture" << std::endl;
                return;
            }
            if (!deathTexture.loadFromFile("../resources/EnemyAnim/enemies-skeleton1_death.png")) {
                std::cout << "Error loading enemy death texture" << std::endl;
                return;
            }
            if (!damageTexture.loadFromFile("../resources/EnemyAnim/enemies-skeleton1_take_damage.png")) {
                std::cout << "Error loading enemy damage texture" << std::endl;
                return;
            }
            std::cout<<"Enemy Texture Loaded."<<std::endl;
            // Set initial texture
            sprite.setTexture(idleTexture);

            // Setup frame rectangles for each animation
            // These values might need adjustment based on your actual sprite sheet dimensions
            const int FRAME_WIDTH = 32;  // Adjust based on your sprite sheet
            const int FRAME_HEIGHT = 32; // Adjust based on your sprite sheet

            // Setup idle animation frames
            for (int i = 0; i < 6; i++) { // Adjust frame count as needed
                idleFrames.push_back(sf::IntRect(sf::Vector2i(i * FRAME_WIDTH, 0), sf::Vector2i(FRAME_WIDTH, FRAME_HEIGHT)));
            }

            // Setup attack animation frames
            for (int i = 0; i < 9; i++) { // Adjust frame count as needed
                attackFrames.push_back(sf::IntRect(sf::Vector2i(i * FRAME_WIDTH, 0), sf::Vector2i(FRAME_WIDTH, FRAME_HEIGHT)));
            }

            // Setup movement animation frames
            for (int i = 0; i < 10; i++) { // Adjust frame count as needed
                moveFrames.push_back(sf::IntRect(sf::Vector2i(i * FRAME_WIDTH, 0), sf::Vector2i(FRAME_WIDTH, FRAME_HEIGHT)));
            }

            // Setup death animation frames
            for (int i = 0; i < 17; i++) { // Adjust frame count as needed
                deathFrames.push_back(sf::IntRect(sf::Vector2i(i * FRAME_WIDTH, 0), sf::Vector2i(FRAME_WIDTH, FRAME_HEIGHT)));
            }

            // Setup damage animation frames
            for (int i = 0; i < 5; i++) { // Adjust frame count as needed
                damageFrames.push_back(sf::IntRect(sf::Vector2i(i * FRAME_WIDTH, 0), sf::Vector2i(FRAME_WIDTH, FRAME_HEIGHT)));
            }
            hitbox.setFillColor(sf::Color::Transparent);
            hitbox.setOutlineColor(sf::Color::Red);
            hitbox.setOutlineThickness(1.f);

            sprite.setOrigin(sf::Vector2f(FRAME_WIDTH/2, FRAME_HEIGHT/2));
            sprite.setScale(sf::Vector2f(character_SCALE, character_SCALE));
            sprite.setPosition({200, 200});

            sf::Vector2f spritePos = sprite.getPosition();

            float hbWidth = FRAME_WIDTH * character_SCALE * 0.3f;
            float hbHeight = FRAME_HEIGHT * character_SCALE * 0.3f;

            float hitboxyoffset = 20.f;
            float hitboxxoffset = -10.f;
            hitbox.setSize({hbWidth, hbHeight});
            hitbox.setOrigin({hbWidth / 2.f, hbHeight / 2.f});
            hitbox.setPosition({spritePos.x + hitboxxoffset, spritePos.y + hitboxyoffset});

            clock.restart();
        }

        void update(float deltaTime, const std::vector<sf::FloatRect>& mapRects, sf::FloatRect target) {

            if (isDead) { // dont attack while dead
                setAnimation(DEATH);
                isAttacking = false;
            }

            // Update animation frame
            if(clock.getElapsedTime() >= frameDuration) {
                std::vector<sf::IntRect>& currentFrames = getCurrentAnimationFrames();
                
                if(currentFrames.empty()) {
                    // If no frames are available, reset the clock and return
                    clock.restart();
                    return;
                }

                if(isDead && currentAnimation == DEATH) {
                    if(currentFrame < currentFrames.size() - 1) {
                        currentFrame++;
                    }
                    else if(!deathAnimationFinished) {
                        deathAnimationFinished = true;
                        deathTimer.restart();
                    }
                }
                else {
                    // Make sure we don't exceed the frame count
                    currentFrame = (currentFrame + 1) % currentFrames.size();
                }
                
                clock.restart();
            }
            
            sf::Vector2f movement = {0,0};
            const float ENEMY_SPEED = 100.f;
            const float FOLLOW_DISTANCE = 350.f;
            const float ATTACK_DISTANCE = 20.f;
            
            if(!isDead) {

                // set death
                if (currentHealth <= 0) {
                    setAnimation(Enemy::DEATH);
                    isDead = true;
                    if(!(deathSound[0].getStatus() == sf::Sound::Status::Playing)){
                        deathSound[0].play();
                    }
                }

                // set move logic
                if(getDistancetoTarget(target.position) < FOLLOW_DISTANCE){
                    sf::Vector2f direction = getDirectiontoTarget(target.position);
                    direction = avoidWalls(direction, mapRects);
                    movement = ENEMY_SPEED * direction * deltaTime;
                }

                sf::FloatRect originalHitbox = hitbox.getGlobalBounds();
                sf::Vector2f newMovement = {};

                // try x movement
                sf::FloatRect testX = originalHitbox;
                testX.position.x += movement.x;
                bool blockedX = false;
                for (const auto& wall : mapRects) {
                    if (testX.findIntersection(wall)) {
                        blockedX = true;
                        break;
                    }
                }
                if(!blockedX){
                    newMovement.x = movement.x;
                }

                // try y movement
                sf::FloatRect testY = originalHitbox;
                testY.position.y += movement.y;
                bool blockedY = false;
                for (const auto& wall : mapRects) {
                    if (testY.findIntersection(wall)) {
                        blockedY = true;
                        break;
                    }
                }
                if(!blockedY){
                    newMovement.y = movement.y;
                }

                
                //attacking logic
                if(getDistancetoTarget(target.position) < ATTACK_DISTANCE) {
                    isAttacking = true;
                    newMovement = {}; // stop
                    // play a random attack sound effect
                    int index = rand() % 3;
                    if(attackSound[index].getStatus() != sf::Sound::Status::Playing){
                        attackSound[index].play();
                    }
                }

                if (newMovement != sf::Vector2f{0.f, 0.f}) {
                    move(newMovement.x, newMovement.y);
                    if(!isAttacking){
                        setAnimation(MOVE);
                    }
                } else {
                    if(isAttacking == true){
                        setAnimation(ATTACK);

                    } else{
                        setAnimation(IDLE);
                    }
                }
            }
            
            
            std::vector<sf::IntRect>& currentFrames = getCurrentAnimationFrames();
            
            // Apply the current frame to the sprite
            sprite.setTextureRect(currentFrames[currentFrame]);

            // Check if attack animation is finished
            if(isAttacking && currentAnimation == ATTACK && currentFrame >= getCurrentAnimationFrames().size() - 1) {
                isAttacking = false;
            }
            
        }
        
        void setAnimation(AnimationState animation) {
            
            if (animation != currentAnimation) {
                currentAnimation = animation;
                currentFrame = 0;
                
                // Set the appropriate texture for the animation
                switch (animation) {
                    case IDLE:
                        sprite.setTexture(idleTexture);
                        break;
                    case MOVE:
                        sprite.setTexture(moveTexture);
                        break;
                    case ATTACK:
                        sprite.setTexture(attackTexture);
                        break;
                    case DEATH:
                        sprite.setTexture(deathTexture);
                        break;
                    case TAKE_DAMAGE:
                        sprite.setTexture(damageTexture);
                        break;
                    default:
                        sprite.setTexture(idleTexture);
                        break;
                }
            }
        }

        void move(float x, float y) {
            sprite.move(sf::Vector2f(x, y));
            hitbox.move(sf::Vector2f(x,y));
            
            // Update direction based on movement
            if (x > 0) {
                setAnimation(MOVE);
                isFacingRight = true;
            } else if (x < 0) {
                setAnimation(MOVE);
                isFacingRight = false;
            } else if (y < 0) {
                setAnimation(MOVE);
            } else if (y > 0) {
                setAnimation(MOVE);
            }
            sprite.setScale(isFacingRight ? sf::Vector2f(character_SCALE,character_SCALE) : sf::Vector2f(-character_SCALE, character_SCALE));
        }

        void updateHealthBar() {
            // Get sprite bounds to position health bar above sprite
            sf::FloatRect spriteBounds = sprite.getGlobalBounds();
            
            // Position both bars above the sprite
            float xPos = spriteBounds.position.x + sprite.getGlobalBounds().size.x/4 ;
            float yPos = spriteBounds.position.y + 10.f; // 10 pixels above sprite
            
            healthBarBackground.setPosition(sf::Vector2f(xPos, yPos));
            healthBarFill.setPosition(sf::Vector2f(xPos, yPos));
            
            // Update health bar fill width based on current health percentage
            float healthPercentage = currentHealth / maxHealth;
            float currentWidth = healthBarBackground.getSize().x * healthPercentage;
            healthBarFill.setSize(sf::Vector2f(currentWidth, healthBarFill.getSize().y));
        }

        void takeDamage(float amount) {
            if (isDead) return;
            isTakingDamage = true;
            currentHealth = std::max(0.f, currentHealth - amount);
            setAnimation(TAKE_DAMAGE);
            // play a random enemy taking damage sound effect
            int index = rand() % 3;
            enemyDamageSound[index].play();
            
            if (currentHealth <= 0) {
                setAnimation(DEATH);
            }
        }

        void draw(sf::RenderWindow& window) {
            updateHealthBar();
            window.draw(sprite);
            window.draw(healthBarBackground);
            window.draw(healthBarFill);
            // window.draw(hitbox); // for debugging
        }

        float getDistancetoTarget(sf::Vector2f target){
            float dx = target.x - getHitbox().position.x;
            float dy = target.y - getHitbox().position.y;
            float distance = std::sqrt(dx * dx + dy * dy);
            return distance;
        }

        sf::Vector2f avoidWalls(const sf::Vector2f& directionToTarget, const std::vector<sf::FloatRect>& mapRects) {
            sf::Vector2f newDirection = directionToTarget;

            // Get the center of the hitbox (enemy position)
            sf::Vector2f myPos = getHitbox().position + sf::Vector2f(getHitbox().size.x / 2, getHitbox().size.y / 2);

            for (const auto& rect : mapRects) {
                if (rect.findIntersection(getHitbox())) {
                    // Already intersecting, no need to repel further
                    continue;
                }

                sf::Vector2f wallCenter(rect.position.x + rect.size.x / 2, rect.position.y + rect.size.y / 2);
                sf::Vector2f toWall = wallCenter - myPos;
                float dist = std::sqrt(toWall.x * toWall.x + toWall.y * toWall.y);

                if (dist < 60.f) {  // Only repel if close enough
                    sf::Vector2f repelDir = -toWall / dist; // Repel away
                    float strength = 60.f - dist; // Stronger when closer
                    newDirection += repelDir * strength * 0.02f;
                }
            }

            // Normalize final direction
            float len = std::sqrt(newDirection.x * newDirection.x + newDirection.y * newDirection.y);
            if (len != 0)
                newDirection /= len;

            return newDirection;
        }


        sf::Vector2f getDirectiontoTarget(sf::Vector2f target){
            sf::Vector2f direction;
            float dx = target.x - getHitbox().position.x;
            float dy = target.y - getHitbox().position.y;
            float distance = getDistancetoTarget(target);
            if (distance > 0) {
                direction.x = dx / distance;
                direction.y = dy / distance;
            }
            return direction;
        }

        sf::FloatRect getBounds() const {
            return sprite.getGlobalBounds();
        }
        
        sf::FloatRect getHitbox(){
            return hitbox.getGlobalBounds();
        }

        sf::Vector2f getPosition() const {
            return sprite.getPosition();
        }

        // Add getter for current health
        float getHealth() const {
            return currentHealth;
        }
        bool getisDead(){
            return isDead;
        }

        bool getisAttacking(){
            return isAttacking;
        }

    private:
        std::vector<sf::IntRect>& getCurrentAnimationFrames() {
            switch (currentAnimation) {
                case IDLE: return idleFrames;
                case MOVE: return moveFrames;
                case ATTACK: return attackFrames;
                case DEATH: return deathFrames;
                case TAKE_DAMAGE: return damageFrames;
                default: return idleFrames;
            }
        }

        sf::Texture& getCurrentTexture() {
            switch (currentAnimation) {
                case IDLE: return idleTexture;
                case MOVE: return moveTexture;
                case ATTACK: return attackTexture;
                case DEATH: return deathTexture;
                case TAKE_DAMAGE: return damageTexture;
                default: return idleTexture;
            }
        }
};

std::vector<Enemy> spawnEnemiesForLevel(int level, const std::vector<sf::FloatRect>& mapRects) { // spawns enemies in random pre-specified areas
    std::vector<Enemy> enemies;

    // Random number generator
    std::random_device rd;
    std::mt19937 gen(rd());

    // Loop through the spawn areas for the level
    for (const auto& spawnArea : EnemySpawns[level]) {
        if(spawnArea.size != sf::Vector2f()){
            // Two enemies per spawn area
            for (int i = 0; i < 2; ++i) {
                Enemy enemy;
                enemy.load(level); // load the enemy

                bool validPos = false;
                int attempts = 0;
                const int maxAttempts = 500;

                while(!validPos && attempts < maxAttempts){
                    // Random X and Y within spawn area
                    std::uniform_real_distribution<float> distX(spawnArea.position.x, spawnArea.position.x + spawnArea.size.x);
                    std::uniform_real_distribution<float> distY(spawnArea.position.y, spawnArea.position.y + spawnArea.size.y);
                    
                    float randomX = distX(gen);
                    float randomY = distY(gen);
                    
                    // Temporarily move enemy
                    sf::Vector2f delta = { randomX - enemy.getPosition().x, randomY - enemy.getPosition().y };
                    enemy.move(delta.x, delta.y);

                    // Check if enemy hitbox intersects any wall
                    bool intersectsWall = false;
                    for (const auto& rect : mapRects) {
                        if (enemy.getHitbox().findIntersection(rect)) {
                            intersectsWall = true;
                            break;
                        }
                    }
                    if(!intersectsWall){
                        validPos = true;
                    } else{
                        // Move enemy back to a little different position than the original position
                        enemy.move(-delta.x + 0.1f, -delta.y + 0.1f);
                    }
                    attempts++;
                }
                if(validPos){
                    enemies.emplace_back(enemy);
                } else{
                    std::cout << "Failed to find valid spawn for enemy after " << maxAttempts << " attempts.\n";
                }
            }
        }
        
    }
    return enemies;
}