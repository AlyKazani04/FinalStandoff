#include <SFML/Audio.hpp>
#include "sound.hpp"

bool BackGroundMusic::LoadMenuMusic() // Load music from file
{
    if(!_music.openFromFile(MENU_MUSICPATH)){ // open file
        return false;
    }else{
        return true;
    }
}

bool BackGroundMusic::LoadGameMusic(int level) // Load music from file
{
    _LevelNumber = level;
    if(!_music.openFromFile(gamebgmpath[level])){ // open file
        return false;
    }else{
        return true;
    }
}

void BackGroundMusic::setVolume(int volume)
{
    _volume = volume;
    _music.setVolume(_volume); // set volume of music
}

void BackGroundMusic::play() // play music
{
    _music.setVolume(_volume); 

    _music.setLooping(true);
    _music.setPlayingOffset(sf::seconds(2));
    _music.play();
}

void BackGroundMusic::stop() // stop music
{
    _music.stop();
}