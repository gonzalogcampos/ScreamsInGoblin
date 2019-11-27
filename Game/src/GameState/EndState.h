#pragma once
#include "IGameState.h"

class Menu;
class EndState : public IGameState 
{
    private:
        EndState(){}
        Menu* menu;
    public:

    static EndState* getInstance(){
        static EndState only_instance;
        return &only_instance;
    }
        

    ~EndState() {}
    void initState();
    void update(float dt);
    void clear();
};