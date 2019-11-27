#include "EnemyHurtsSoundEvent.h"



EnemyHurtsSoundEvent* EnemyHurtsSoundEvent::newSoundEvent(FMOD::Studio::EventInstance* ei)
{
    EnemyHurtsSoundEvent* sse = new EnemyHurtsSoundEvent(ei);

    return sse;
}

void EnemyHurtsSoundEvent::setVoiceParameter()
{
    FMOD::Studio::ParameterInstance* pParameter = NULL;
    SoundSystem::ErrorCheck(soundInstance->getParameter("voice", &pParameter));
    std::srand((unsigned) clock());
    int i = (rand()%3)+1;
    float val = i;

    //std::cout<<"tipo de grito "<< val <<" clock " << clock()<< "\n";

    SoundSystem::ErrorCheck(pParameter->setValue(val));
}
