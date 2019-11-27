#pragma once
#include "IGameState.h"

class Menu;
class ToNextState : public IGameState 
{
    private:
        ToNextState(){}
        Menu* menu;
    public:

    static ToNextState* getInstance(){
        static ToNextState only_instance;
        return &only_instance;
    }
        

    ~ToNextState() {}
    void initState();
    void update(float dt);
    void clear();
};