 #include "SoundSystem.h"


class EnemyDiesSoundEvent : public SoundEvent
{
    public:

    EnemyDiesSoundEvent(FMOD::Studio::EventInstance* eventInstance): SoundEvent(eventInstance){}
    virtual ~EnemyDiesSoundEvent() {};
    protected:

    virtual EnemyDiesSoundEvent* newSoundEvent(FMOD::Studio::EventInstance* ei);

};