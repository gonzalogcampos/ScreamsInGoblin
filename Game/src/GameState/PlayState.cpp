#include <cstddef>
#include "PlayState.h"
#include <SFML/Window.hpp>
#include "Game.h"
#include "InputManager.h"
#include "IAManager.h"
#include "SpawnManager.h"
#include "GameObject.h"
#include "GameManager.h"
#include "ScoreManager.h"
#include "LevelLoader.h"
#include "SpecificSoundEvent.h"
#include "GameResource.h"
#include "KATRender.h"
#include "TCamera.h"
#include "RenderComponent.h"
#include <iostream>

void PlayState::initState()
{
    type = IGameState::PLAY;

    if(!loaded)
    {
        loaded=true;
        LevelLoader::getInstance()->loadLevel();
        GameManager::getInstance()->initAll();
       

    
        AmbientSoundEvent* s = new AmbientSoundEvent(SoundSystem::getInstance()->getEventInstanceFromName("ambiente"));
        s->start();
        SoundSystem::getInstance()->saveEvent(s,"ambiente");

        AmbientSoundEvent* m = new AmbientSoundEvent(SoundSystem::getInstance()->getEventInstanceFromName("musica"));
        m->start();
        SoundSystem::getInstance()->saveEvent(m,"musica");
        m->setTensionParameter(1);

        AmbientSoundEvent* l = new AmbientSoundEvent(SoundSystem::getInstance()->getEventInstanceFromName("latido"));
        l->setVolume(5);
        l->start();
        SoundSystem::getInstance()->saveEvent(l,"latido");
        l->setVidaParameter(GameResource::getInstance()->getPlayer());

    }else{
        AmbientSoundEvent* s = (AmbientSoundEvent*)SoundSystem::getInstance()->getEvent("ambiente");
        AmbientSoundEvent* sm = (AmbientSoundEvent*)SoundSystem::getInstance()->getEvent("musica");
        AmbientSoundEvent* lat = (AmbientSoundEvent*)SoundSystem::getInstance()->getEvent("latido");

        sm->resume();
        s->resume();
        lat->resume();
        SoundSystem::getInstance()->Update();


    }

     ((TCamera*)((KATRender*)Render::getInstance()->getRender())->getKatana()->getNodeCamera()->getEntity())->switchProyection(false);

} 


void PlayState::update(float dt)
{
    AmbientSoundEvent* lat = (AmbientSoundEvent*)SoundSystem::getInstance()->getEvent("latido");
    lat->setVidaParameter(GameResource::getInstance()->getPlayer());

    GameManager::getInstance()->updateAll(dt);
    
    if(sf::Keyboard::isKeyPressed(sf::Keyboard::Escape))
        Game::getInstance()->setState(IGameState::stateType::PAUSE);


    if(IAManager::getInstance()->getPlayer() && IAManager::getInstance()->getPlayer()->getKill())
    {
        clear();
        LevelLoader::getInstance()->resetNext();
        Game::getInstance()->setState(IGameState::stateType::END);
    }else if(SpawnManager::getInstance()->getNumSpawns()<=0)
    {
        clear();
        if(!LevelLoader::getInstance()->hasNext())
        {
            ScoreManager::getInstance()->setWin();
            Game::getInstance()->setState(IGameState::stateType::END);
        }else{

            Game::getInstance()->setState(IGameState::stateType::TONEXT);
        }
    }
}


void PlayState::clear(){
    GameManager::getInstance()->clear();

    loaded=false;
}