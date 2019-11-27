#include "ItemPickSoundEvent.h"


ItemPickSoundEvent* ItemPickSoundEvent::newSoundEvent(FMOD::Studio::EventInstance* ei)
{
    ItemPickSoundEvent* sse = new ItemPickSoundEvent(ei);

    return sse;
}