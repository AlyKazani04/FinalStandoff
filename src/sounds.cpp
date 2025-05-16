#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include <iostream>
#include "constants.cpp"

class MenuMusic{
    protected:
        sf::Music music;
    public:
        MenuMusic(){}
        
        bool LoadMusic(){ // Load music from file
            if(!music.openFromFile(MENUMUSICFILE)){ // open file
                return false;
            }else{
                return true;
            }
        }
        virtual void play(){ // play music
            
            music.setVolume(40);
            music.setLooping(true);
            music.play();

        }
        void stop(){ // stop music
            music.stop();
        }
};

class BackGroundMusic : public MenuMusic{
    private:
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
        void play() override{ // play music
            
            if(LevelNumber == 0 || LevelNumber == 1){
                music.setVolume(50);
            } else if(LevelNumber == 2){
                music.setVolume(10);
            }
            
            music.setLooping(true);
            music.setPlayingOffset(sf::seconds(2));
            music.play();

        }
        // inherited void stop(); //stop music
};

