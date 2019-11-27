#include "SoundSystem.h"

class WatergetSoundEvent : public SoundEvent
{
    public:

    WatergetSoundEvent(FMOD::Studio::EventInstance* eventInstance): SoundEvent(eventInstance){}
    virtual ~WatergetSoundEvent() {};
    void setVoice();

    protected:

    virtual WatergetSoundEvent* newSoundEvent(FMOD::Studio::EventInstance* ei);

};

class WaterdropSoundEvent : public SoundEvent
{
    public:

    WaterdropSoundEvent(FMOD::Studio::EventInstance* eventInstance): SoundEvent(eventInstance){}
    virtual ~WaterdropSoundEvent() {};
    void setVoice();

    protected:

    virtual WaterdropSoundEvent* newSoundEvent(FMOD::Studio::EventInstance* ei);

};