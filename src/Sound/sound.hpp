#pragma once

#include <SFML/Audio.hpp>
#include "../Constants/constants.hpp"

class BackGroundMusic
{
    private:
        int _LevelNumber = 0; // Current level number
        int _volume = 50; // Default volume
        sf::Music _music; // SFML Music object to handle background music
        
    public:
        BackGroundMusic(){}
        
        /// @brief function to load menu music from file
        /// @return returns true if successful or false if failed
        bool LoadMenuMusic();

        /// @brief function to load game music from file
        /// @param level level number
        /// @return returns true if successful or false if failed
        bool LoadGameMusic(int level);

        /// @brief function to set volume for music
        /// @param volume volume level (0-100)
        void setVolume(int volume);

        /// @brief function to play music
        void play();

        /// @brief stop music
        void stop();
};