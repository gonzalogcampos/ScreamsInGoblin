#pragma once
#include "fmod_studio.hpp"
#include "fmod.hpp"
#include <string>
#include <map>
#include <vector>
#include <math.h>

struct Vector3;
class SoundEvent {
public:
    SoundEvent(FMOD::Studio::EventInstance* eventInstance);
    virtual ~SoundEvent() {}; 
    
    virtual void start();
 
    void stop();
    void pause();
    void resume();
    void setVolume(float vol);
    void setGain(float gain);
    void setPosition(Vector3 pos);
    bool isPlaying();

    FMOD::Studio::EventInstance* getSoundInstance(){return soundInstance;}
    
protected:
    FMOD::Studio::EventInstance* soundInstance;
  
    virtual SoundEvent* newSoundEvent(FMOD::Studio::EventInstance*) = 0;
};

