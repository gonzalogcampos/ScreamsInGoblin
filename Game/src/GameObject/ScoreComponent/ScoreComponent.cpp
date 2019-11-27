#include "ScoreComponent.h"
#include "ScoreManager.h"


ScoreComponent::~ScoreComponent()
{
    ((ScoreManager*)manager)->applyScore(score);
}