#include "SoundSystem.h"
#include "SoundEvent.h"
#include "SoundEngineData.h"
#include "CameraManager.h"
#include "GameObject.h"
#include "GameResource.h"
#include <iostream>


SoundEvent::SoundEvent(FMOD::Studio::EventInstance* eventInstance)
{
    soundInstance = eventInstance;
    
}


void SoundEvent::start()
{
    SoundSystem::ErrorCheck(soundInstance->start());
}

void SoundEvent::stop()
{
    SoundSystem::ErrorCheck(soundInstance->stop(FMOD_STUDIO_STOP_IMMEDIATE) ); //FMOD_STUDIO_STOP_ALLOWFADEOUT
}

void SoundEvent::pause()
{
    SoundSystem::ErrorCheck(soundInstance->setPaused(true) );
}

void SoundEvent::resume()
{
    SoundSystem::ErrorCheck(soundInstance->setPaused(false) );
}

void SoundEvent::setVolume(float vol)
{
    SoundSystem::ErrorCheck(soundInstance->setVolume(vol) );

}

void SoundEvent::setGain(float gain)
{
    float vol = 0.f;
    SoundSystem::ErrorCheck(soundInstance->getVolume(&vol));
    vol = vol * gain;
    SoundSystem::ErrorCheck(soundInstance->setVolume(vol));
}

void SoundEvent::setPosition(Vector3 pos)
{
    FMOD_3D_ATTRIBUTES atrib;

       atrib.position =  SoundSystem::getInstance()->VectorToFmod(pos);
       atrib.velocity = SoundSystem::getInstance()->VectorToFmod({0,0,0});
       atrib.forward = SoundSystem::getInstance()->VectorToFmod({0,1,0});
       atrib.up = SoundSystem::getInstance()->VectorToFmod({0,0,-1});

    

    SoundSystem::ErrorCheck(soundInstance->set3DAttributes(&atrib));
}

bool SoundEvent::isPlaying()
{
    bool res = false;
    FMOD_STUDIO_PLAYBACK_STATE* state = NULL;
   
    SoundSystem::ErrorCheck(soundInstance->getPlaybackState(state));

    if (*state == FMOD_STUDIO_PLAYBACK_PLAYING) res = true;

    return res;
}