#pragma once
#include "GameValues.h"
class GameObject;

enum ProjectileType
{
    PARROW,
    PAXE,
    PPEAK
};

struct PType{
    ProjectileType type;
    char* mesh;
    char* texture;
    float velocity;
    float damage;
};


class ProjectileFabric
{
    private:
        PType projectile_types[3] = 
        {
            {
                PARROW,
                (char*)"res/obj/FLECHA.obj",
                (char*)"res/obj/Flecha_Color.bmp",
                gv::ARROW_VELOCITY,
                gv::ARROW_DAMAGE
            },
            {
                PAXE,
                (char*)"res/obj/HACHA.obj",
                (char*)"res/obj/Hacha_Color.bmp",
                gv::AXE_VELOCITY,
                gv::AXE_DAMAGE
            },
            {
                PPEAK,
                (char*)"res/obj/PICO.obj",
                (char*)"res/obj/Pico_Color.bmp",
                gv::PEAK_VELOCITY,
                gv::PEAK_DAMAGE                
            }
        };

    public:
        ProjectileFabric(){}
        virtual ~ProjectileFabric(){}

        GameObject* createProjectile(float x, float y, float rz, ProjectileType type, int team = 1);
};