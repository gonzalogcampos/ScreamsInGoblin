#include "SoundSystem.h"


class ItemPickSoundEvent : public SoundEvent
{
    public:

   ItemPickSoundEvent(FMOD::Studio::EventInstance* eventInstance): SoundEvent(eventInstance){}
    virtual ~ItemPickSoundEvent() {};

    protected:

    virtual ItemPickSoundEvent* newSoundEvent(FMOD::Studio::EventInstance* ei);

};