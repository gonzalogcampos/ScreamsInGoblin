#pragma once
#include "IGameState.h"

class Menu;
class MenuState : public IGameState 
{
    private:
        Menu* menu;
        MenuState(){}
    public:

        static MenuState* getInstance(){
            static MenuState only_instance;
            return &only_instance;
        }
        
        virtual void initState();
        virtual void update(float dt);
        virtual void clear();
};