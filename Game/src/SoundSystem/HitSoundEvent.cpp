 #include "HitSoundEvent.h"


HitSoundEvent* HitSoundEvent::newSoundEvent(FMOD::Studio::EventInstance* ei)
{
    HitSoundEvent* sse = new HitSoundEvent(ei);

    return sse;
}