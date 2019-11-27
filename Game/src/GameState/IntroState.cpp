#include <cstddef>
#include "IntroState.h"
#include "Game.h"
#include <SFML/Window.hpp>
#include "GameValues.h"
#include "SpecificSoundEvent.h"

void IntroState::initState(){    
};

void IntroState::clear(){
};

void IntroState::update(float dt){
    delta+=dt;
    if(delta>gv::INTRO_DURATION)
    {
        delta = 0;
        clear();
        Game::getInstance()->setState(IGameState::stateType::MENU);
    }

    if(sf::Keyboard::isKeyPressed(sf::Keyboard::Space) || sf::Keyboard::isKeyPressed(sf::Keyboard::Enter))
    {
        delta = 0;
        clear();
        Game::getInstance()->setState(IGameState::stateType::MENU);
    }
    
}