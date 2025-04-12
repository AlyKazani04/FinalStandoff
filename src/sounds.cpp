#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include <iostream>
#include "constants.cpp"

class BackGroundMusic{
    private:
        sf::Music music;
        int LevelNumber;
    public:
        BackGroundMusic() : LevelNumber(0){
            if(loadMusic(0)){ 
                std::cout<<"Music Loaded Successfully."<<std::endl;
            }else{
                std::cout<<"Music not Loaded."<<std::endl;
                exit(-1);
            }
        }
        bool loadMusic(int level){ // Load music from file
            LevelNumber = level;
            if(!music.openFromFile(filepath[level])){ // open file
                return false;
            }else{
                return true;
            }
        }
        void play(){ // play music
            music.setLooping(true);
            music.play();
        }
        void stop(){ // stop music
            music.stop();
        }
        void setVolume(int level = 70){ // set the volume level
            music.setVolume(level);
            // std::cout<<"Volume: "<<music.getVolume()<<std::endl;
        }
};
