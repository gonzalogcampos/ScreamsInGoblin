#include "ShootSoundEvent.h" 
#include <ctime>
#include <iostream>

ShootSoundEvent* ShootSoundEvent::newSoundEvent(FMOD::Studio::EventInstance* ei)
{
    ShootSoundEvent* sse = new ShootSoundEvent(ei);

    return sse;
}

void ShootSoundEvent::setVoice()
{
    FMOD::Studio::ParameterInstance* pParameter = NULL;
    SoundSystem::ErrorCheck(soundInstance->getParameter("voice", &pParameter));
    std::srand((unsigned) clock());
    int i = (rand()%3)+1;
    float val = i;

    //std::cout<<"tipo de grito "<< val <<" clock " << clock()<< "\n";

    SoundSystem::ErrorCheck(pParameter->setValue(val));
}

