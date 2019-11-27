#include "EnemyDiesSoundEvent.h"


EnemyDiesSoundEvent* EnemyDiesSoundEvent::newSoundEvent(FMOD::Studio::EventInstance* ei)
{
    EnemyDiesSoundEvent* sse = new EnemyDiesSoundEvent(ei);

    return sse;
}