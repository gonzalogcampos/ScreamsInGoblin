#include "ScoreManager.h"
#include "ScoreComponent.h"
#include "GameObject.h"


void ScoreManager::createComponent(GameObject* owner, int score)
{
    components.push_back(new ScoreComponent(owner, this, score));
    owner->addComponent(components[components.size()-1]);
}


void ScoreManager::applyScore(int score)
{
    this->score+=score;
}

int ScoreManager::resetScore()
{
    int sa = score;
    score = 0;
    return sa;
}


bool ScoreManager::getWin()
{
    bool r = win;
    win = false;
    return r;
}