 #include "SoundSystem.h"

class EnemyHurtsSoundEvent : public SoundEvent
{
    public:

    EnemyHurtsSoundEvent(FMOD::Studio::EventInstance* eventInstance): SoundEvent(eventInstance){}
    virtual ~EnemyHurtsSoundEvent() {};

    void setVoiceParameter();
    protected:

    virtual EnemyHurtsSoundEvent* newSoundEvent(FMOD::Studio::EventInstance* ei);

};