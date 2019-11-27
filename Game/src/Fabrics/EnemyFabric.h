#pragma once
#include "GameValues.h"
#include <string>

class GameObject;


enum EnemyType
{
    ENEMY_1,
    ENEMY_2
};

struct EType{
    EnemyType type;
    int numFrames;
    char* animation;
    char* mesh;
    char* texture;
    float life;
    float vMax;
};

class EnemyFabric
{
    private:
        EType enemytypes [2] = 
        {
            {
                ENEMY_1,
                25,
                (char*)"res/animations/Soldado/Walk/Walk_Soldier_",
                (char*)"res/animations/Soldado/Walk/Walk_Soldier_1.obj",                
                (char*)"res/red.bmp",
                gv::ENEMY_1_LIFE,
                gv::ENEMY_1_VELOCITY
            },
            {
                ENEMY_2,
                24,
                (char*)"res/animations/Aldeana/Walk/Walk_Aldeana_",
                (char*)"res/animations/Aldeana/Walk/Walk_Aldeana_1.obj",
                (char*)"res/green.bmp",
                gv::ENEMY_2_LIFE,
                gv::ENEMY_2_VELOCITY
            },
        };

    public:
        EnemyFabric(){}
        virtual ~EnemyFabric(){}

        GameObject* createEnemy(float x, float y, float z, float rz, EnemyType type);
};