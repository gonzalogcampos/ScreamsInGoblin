#include <cstddef>
#include "EndState.h"
#include "Render.h"
#include "Game.h"
#include <SFML/Window.hpp>
#include "ScoreManager.h"
#include <iostream>
#include "HUD.h"
#include "SoundSystem.h"
#include "LoseMenu.h"
#include "WinMenu.h"

void EndState::update(float dt)
{
    menu->update(dt);

    if(sf::Keyboard::isKeyPressed(sf::Keyboard::Space) || sf::Keyboard::isKeyPressed(sf::Keyboard::Enter))
    {
        switch (menu->click())
        {
            case 1:
                /* Inicio */
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
}

void EndState::initState(){

    if(ScoreManager::getInstance()->getWin())
    {
        menu = new WinMenu();
    }else
    {
        menu = new LoseMenu();
    }
    type = IGameState::END; 
};


void EndState::clear()
{
}