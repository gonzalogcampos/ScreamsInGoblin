#include "SoundSystem.h"

class ShootSoundEvent : public SoundEvent
{
    public:

    ShootSoundEvent(FMOD::Studio::EventInstance* eventInstance): SoundEvent(eventInstance){}
    virtual ~ShootSoundEvent() {};
    void setVoice();

    protected:

    virtual ShootSoundEvent* newSoundEvent(FMOD::Studio::EventInstance* ei);

};

