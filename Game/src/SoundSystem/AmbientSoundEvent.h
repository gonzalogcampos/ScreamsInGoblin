 #include "SoundSystem.h"
#include "GameObject.h"
class AmbientSoundEvent : public SoundEvent
{
    public:

    AmbientSoundEvent(FMOD::Studio::EventInstance* eventInstance): SoundEvent(eventInstance){}
    virtual ~AmbientSoundEvent() {};

    void setAttackParameter(bool bol);
    void setTensionParameter(bool ten);
    void setVidaParameter(GameObject* player);
    protected:

    virtual AmbientSoundEvent* newSoundEvent(FMOD::Studio::EventInstance* ei);

};