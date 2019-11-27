#include <cstddef>
#include "CreditsState.h"
#include "Render.h"
#include "FMenu.h"
#include "Game.h"
#include <SFML/Window.hpp>
#include "SpecificSoundEvent.h"
#include "CreditsMenu.h"


void CreditsState::initState()
{
    type = IGameState::CREDITS;
    menu = new CreditsMenu();   
}

void CreditsState::update(float dt)
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

};

void CreditsState::clear()
{
    delete menu;
};