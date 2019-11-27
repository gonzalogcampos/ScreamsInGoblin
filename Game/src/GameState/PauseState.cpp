#include <cstddef>
#include "PauseState.h"
#include <SFML/Window.hpp>
#include "Game.h"
#include "SpecificSoundEvent.h"
#include "LevelLoader.h"
#include "PauseMenu.h"
#include "GameManager.h"
#include "PlayState.h"

void PauseState::initState()
{
    type = IGameState::PAUSE;
    menu = new PauseMenu();
    AmbientSoundEvent* s = (AmbientSoundEvent*)SoundSystem::getInstance()->getEvent("ambiente");
    AmbientSoundEvent* sm = (AmbientSoundEvent*)SoundSystem::getInstance()->getEvent("musica");
    AmbientSoundEvent* lat = (AmbientSoundEvent*)SoundSystem::getInstance()->getEvent("latido");
    lat->pause();
    sm->pause();
    s->pause();
    SoundSystem::getInstance()->Update();

   
}

void PauseState::update(float dt)
{
     menu->update(dt);

    if(sf::Keyboard::isKeyPressed(sf::Keyboard::Space) || sf::Keyboard::isKeyPressed(sf::Keyboard::Enter))
    {
        switch (menu->click())
        {
        MSelectSoundEvent * mse;

            case 1:
                /* Volver */  
                mse = new MSelectSoundEvent(SoundSystem::getInstance()->getEventInstanceFromName("mselect"));  
                mse->start();
             

                delete mse;
                delete menu;
                Game::getInstance()->setState(IGameState::stateType::PLAY);
                break;
            case 2:
                /* Inicio */
                mse = new MSelectSoundEvent(SoundSystem::getInstance()->getEventInstanceFromName("mselect"));  
                mse->start();
               
                SoundSystem::getInstance()->Update();
                delete mse;
                PlayState::getInstance()->clear();
                LevelLoader::getInstance()->resetNext();
                delete menu;
                Game::getInstance()->setState(IGameState::stateType::MENU);
                break;
            default:
                break;
        }
    }

    if(sf::Keyboard::isKeyPressed(sf::Keyboard::W) || sf::Keyboard::isKeyPressed(sf::Keyboard::Up))
        menu->up();
    
    if(sf::Keyboard::isKeyPressed(sf::Keyboard::S) || sf::Keyboard::isKeyPressed(sf::Keyboard::Down))
        menu->down();    

    SoundSystem::getInstance()->Update();
        
}