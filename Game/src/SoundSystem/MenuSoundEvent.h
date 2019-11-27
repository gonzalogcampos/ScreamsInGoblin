#include "SoundSystem.h"

class MSelectSoundEvent : public SoundEvent
{
    public:

    MSelectSoundEvent(FMOD::Studio::EventInstance* eventInstance): SoundEvent(eventInstance){}
    virtual ~MSelectSoundEvent() {};

    protected:

    virtual MSelectSoundEvent* newSoundEvent(FMOD::Studio::EventInstance* ei);

};

class MStartSoundEvent : public SoundEvent
{
    public:

    MStartSoundEvent(FMOD::Studio::EventInstance* eventInstance): SoundEvent(eventInstance){}
    virtual ~MStartSoundEvent() {};

    protected:

    virtual MStartSoundEvent* newSoundEvent(FMOD::Studio::EventInstance* ei);

};


class MPulseSoundEvent : public SoundEvent
{
    public:

    MPulseSoundEvent(FMOD::Studio::EventInstance* eventInstance): SoundEvent(eventInstance){}
    virtual ~MPulseSoundEvent() {};

    protected:

    virtual MPulseSoundEvent* newSoundEvent(FMOD::Studio::EventInstance* ei);

};


