#include "FireSoundEvent.h" 

FireSoundEvent* FireSoundEvent::newSoundEvent(FMOD::Studio::EventInstance* ei)
{
    FireSoundEvent* sse = new FireSoundEvent(ei);

    return sse;
}
