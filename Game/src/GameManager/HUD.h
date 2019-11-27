#pragma once
#include "Render.h"
#include "FHUD.h"


class HUD
{
    private:
        FHUD* facade;
        float life;
        int numSpawns;
        int score;
        bool terror;
        bool berserk;
        float fps;
        int weapon = 1;
        HUD(){};
        
    public:
        static HUD* getInstance()
        {
            static HUD only_instance;
            return &only_instance;
        }

        void update(float dt);
        int getScore(){return score;}
        void init(){Render::getInstance()->getHUD()->init();}
        void clear(){Render::getInstance()->getHUD()->clear();}
        float high = 60.f;
};