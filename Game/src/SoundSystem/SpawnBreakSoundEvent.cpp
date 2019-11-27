#include "SpawnBreakSoundEvent.h"

 SpawnBreakSoundEvent*  SpawnBreakSoundEvent::newSoundEvent(FMOD::Studio::EventInstance* ei)
{
    SpawnBreakSoundEvent* sse = new  SpawnBreakSoundEvent(ei);

    return sse;
}
