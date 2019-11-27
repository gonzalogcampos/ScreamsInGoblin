#pragma once
#include "IGameState.h"

class Game
{
    private:;
        IGameState* state;
    public:
        static Game* getInstance(){
            static Game only_instance;
            return &only_instance;
        }
        
        void run();
        void setState(IGameState::stateType type);
        void initGame();
};