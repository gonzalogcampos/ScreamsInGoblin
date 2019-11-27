#include "SoundSystem.h"

class FireSoundEvent : public SoundEvent
{
    public:

    FireSoundEvent(FMOD::Studio::EventInstance* eventInstance): SoundEvent(eventInstance){}
    virtual ~FireSoundEvent() {};

    protected:

    virtual FireSoundEvent* newSoundEvent(FMOD::Studio::EventInstance* ei);

};
