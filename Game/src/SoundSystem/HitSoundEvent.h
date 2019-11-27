#include "SoundSystem.h"

class HitSoundEvent : public SoundEvent
{
    public:

    HitSoundEvent(FMOD::Studio::EventInstance* eventInstance): SoundEvent(eventInstance){}
    virtual ~HitSoundEvent() {};

    protected:

    virtual HitSoundEvent* newSoundEvent(FMOD::Studio::EventInstance* ei);

};