#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include <iostream>
#include "constants.cpp"

class BackGroundMusic{
    private:
        sf::Music music;
        int LevelNumber;
    public:
        BackGroundMusic() : LevelNumber(0){}
        
        bool LoadMusic(int level){ // Load music from file
            LevelNumber = level;
            if(!music.openFromFile(filepath[level])){ // open file
                return false;
            }else{
                return true;
            }
        }
        void play(){ // play music
            
            if(LevelNumber == 0 || LevelNumber == 1){
                music.setVolume(50);
            } else{
                music.setVolume(20);
            }
            
            music.setLooping(true);
            music.setPlayingOffset(sf::seconds(2));
            music.play();

        }
        void stop(){ // stop music
            music.stop();
        }
};
