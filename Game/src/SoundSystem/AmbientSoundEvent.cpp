#include "AmbientSoundEvent.h"
#include "LifeComponent.h"

AmbientSoundEvent* AmbientSoundEvent::newSoundEvent(FMOD::Studio::EventInstance* ei)
{
    AmbientSoundEvent* sse = new AmbientSoundEvent(ei);

    return sse;
}

void AmbientSoundEvent::setAttackParameter(bool bol)
{
    FMOD::Studio::ParameterInstance* pParameter = NULL;
    SoundSystem::ErrorCheck(soundInstance->getParameter("ataque", &pParameter));
    //float val = bol? 1.f : 0.f;
    SoundSystem::ErrorCheck(pParameter->setValue(bol));
}

void AmbientSoundEvent::setTensionParameter(bool ten)
{
    FMOD::Studio::ParameterInstance* pParameter = NULL;
    SoundSystem::ErrorCheck(soundInstance->getParameter("tension", &pParameter));
    SoundSystem::ErrorCheck(pParameter->setValue(ten));

}

void AmbientSoundEvent::setVidaParameter(GameObject* player)
{
    FMOD::Studio::ParameterInstance* pParameter = NULL;
    SoundSystem::ErrorCheck(soundInstance->getParameter("Vida", &pParameter));
    SoundSystem::ErrorCheck(pParameter->setValue(player->getComponent<LifeComponent>()->getLife()));

}