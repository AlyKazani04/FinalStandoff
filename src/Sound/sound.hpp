#pragma once

#include <SFML/Audio.hpp>

class BackGroundMusic{
    private:
        int _LevelNumber = 0; // Current level number
        int _volume = 50; // Default volume
        sf::Music _music; // SFML Music object to handle background music
        bool _isMenu = false;
        
    public:
        BackGroundMusic(){}
        
        bool LoadMenuMusic(); // load menu music from file
        bool LoadGameMusic(int level); // load music from file
        void setVolume(int volume); // set volume of music;
        void play(); // play music
        void stop(); //stop music
};