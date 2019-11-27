#include "SoundSystem.h"


class SpawnBreakSoundEvent : public SoundEvent
{
    public:

   SpawnBreakSoundEvent(FMOD::Studio::EventInstance* eventInstance): SoundEvent(eventInstance){}
    virtual ~SpawnBreakSoundEvent() {};
    void setVoice();

    protected:

    virtual SpawnBreakSoundEvent* newSoundEvent(FMOD::Studio::EventInstance* ei);

};