#pragma once
#include "IGameState.h"

class Menu;
class CreditsState : public IGameState 
{
    private:
        CreditsState(){}
        Menu* menu;
    public:

    static CreditsState* getInstance(){
        static CreditsState only_instance;
        return &only_instance;
    }
        

    ~CreditsState() {}
    void initState();
    void update(float dt);
    void clear();
};