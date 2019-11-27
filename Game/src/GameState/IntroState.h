#pragma once
#include "IGameState.h"

class IntroState : public IGameState 
{
    private:
        IntroState(){}
        float delta = 0.f;

    public:

    static IntroState* getInstance(){
        static IntroState only_instance;
        return &only_instance;
    }
        

    ~IntroState() {}
    void initState();
    void update(float dt);
    void clear();
};