#include "WaterSoundEvent.h"

WatergetSoundEvent* WatergetSoundEvent::newSoundEvent(FMOD::Studio::EventInstance* ei)
{
   WatergetSoundEvent* sse = new WatergetSoundEvent(ei);

    return sse;
}


WaterdropSoundEvent* WaterdropSoundEvent::newSoundEvent(FMOD::Studio::EventInstance* ei)
{
    WaterdropSoundEvent* sse = new WaterdropSoundEvent(ei);

    return sse;
}