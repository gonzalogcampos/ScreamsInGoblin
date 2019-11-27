#pragma once
#include "IGameState.h"

class Menu;
class PauseState : public IGameState 
{
    private:
        PauseState(){}
        Menu* menu;
    public:

    static PauseState* getInstance(){
        static PauseState only_instance;
        return &only_instance;
    }
    
    virtual ~PauseState() {}
    virtual void initState();
    virtual void update(float dt);
    virtual void clear(){};
};