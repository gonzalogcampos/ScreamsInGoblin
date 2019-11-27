#include <cstddef>
#include "ToNextState.h"
#include <SFML/Window.hpp>
#include "Game.h"
#include "PlayState.h"
#include "LevelLoader.h"
#include "Render.h"
#include "FMenu.h"
#include "SpecificSoundEvent.h"
#include "ToNextMenu.h"

void ToNextState::initState()
{
    type = IGameState::TONEXT;
    menu = new ToNextMenu();
}
void ToNextState::update(float dt)
{
    menu->update(dt);

    if(sf::Keyboard::isKeyPressed(sf::Keyboard::Space) || sf::Keyboard::isKeyPressed(sf::Keyboard::Enter))
    {
        switch (menu->click())
        {
            case 1:
                /* Inicio */
                delete menu;
                Game::getInstance()->setState(IGameState::stateType::PLAY);
                break;
            case 2:
                /* Inicio */
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
}

void ToNextState::clear()
{
}