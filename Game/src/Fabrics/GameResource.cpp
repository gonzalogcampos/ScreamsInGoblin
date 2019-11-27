#include "GameResource.h"
#include "GameObject.h"
#include <iostream>
#include "DropperManager.h"
#include "SpecificSoundEvent.h"
#include "IAComponent.h"

void GameResource::clear()
{
    DropperManager::getInstance()->setDrop(false);
    for(std::size_t i = 0; i<gameobjects.size(); i++)
    {
        delete gameobjects[i];
    }
    gameobjects.clear();
}

GameObject* GameResource::createGameObject(float x, float y, float z, float rz)
{
    gameobjects.push_back(new GameObject(x, y, z, rz));
    return gameobjects[gameobjects.size() - 1];
}
GameObject* GameResource::createPlayer(float x, float y, float z, float rz)
{
    gameobjects.push_back(new GameObject(x, y, z, rz));
    player = gameobjects[gameobjects.size() - 1]; 
    return gameobjects[gameobjects.size() - 1];
}

void GameResource::updateAll()
{   
    std::vector<GameObject*>::iterator it = gameobjects.begin();
    for(std::size_t i = 0; i<gameobjects.size(); i++)
    {
        GameObject* g = *it;
        if(g->getKill())
        {
            if(g->getComponent<IAComponent>())
            {
                EnemyDiesSoundEvent* s = new EnemyDiesSoundEvent(SoundSystem::getInstance()->getEventInstanceFromName("ehit"));
                s->setPosition({g->getX(),g->getY(),g->getZ()});
                s->setVolume(5);
                s->start();
                delete s;
            }
            delete g;
            it = gameobjects.erase(it);
            i--;
        } else
            it++;
    }
}