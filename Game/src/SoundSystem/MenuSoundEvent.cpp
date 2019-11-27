#include "MenuSoundEvent.h"



 MPulseSoundEvent*  MPulseSoundEvent::newSoundEvent(FMOD::Studio::EventInstance* ei)
{
     MPulseSoundEvent* sse = new  MPulseSoundEvent(ei);

    return sse;
}

MStartSoundEvent* MStartSoundEvent::newSoundEvent(FMOD::Studio::EventInstance* ei)
{
    MStartSoundEvent* sse = new MStartSoundEvent(ei);

    return sse;
}

 MSelectSoundEvent*  MSelectSoundEvent::newSoundEvent(FMOD::Studio::EventInstance* ei)
{
     MSelectSoundEvent* sse = new  MSelectSoundEvent(ei);

    return sse;
}