#include <stdlib.h>
#include <stdio.h>
#include "Game.h"
#include "Render.h"
#include "Clock.h"
#include "MenuState.h"
#include "PlayState.h"
#include "PauseState.h"
#include "EndState.h"
#include "IntroState.h"
#include "SoundSystem.h"
#include "ToNextState.h"
#include "CreditsState.h"

void Game::run()
{
    initGame();

    Clock clock;
    while(Render::getInstance()->run())
    {
        if(clock.canContinue())
        {
            float t = clock.getElapsedTime();
            state->update(t);
            Render::getInstance()->drawAll(t);
        }
    }
}

void Game::initGame()
{  
    SoundSystem::getInstance()->Init();

    setState(IGameState::stateType::INTRO);
}

void Game::setState(IGameState::stateType type)
{
    switch(type)
    {
        case IGameState::stateType::MENU:
            state = MenuState::getInstance();
            break;
        case IGameState::stateType::PLAY:
            state = PlayState::getInstance();
            break;
        case IGameState::stateType::PAUSE:
            state = PauseState::getInstance();
            break;
        case IGameState::stateType::END:
            state = EndState::getInstance();
            break;
        case IGameState::stateType::INTRO:
            state = IntroState::getInstance();
            break;
        case IGameState::stateType::TONEXT:
            state = ToNextState::getInstance();
            break;
        case IGameState::stateType::CREDITS:
            state = CreditsState::getInstance();
            break;
    }
    state->initState();
}
