#include "LevelLoader.h"

Level level3 = {
    "res/Mapa02.obj",//Map OBJ
    "res/mapapeque.bmp",//Map BMP
    "res/bullet/Mapa02.bullet",//Map BULLET

    -3.f,//Player x
    9.f,//Player y
    -2.f,//Player z

    //Spawns
    {{1.f, -15.f, 0.f, false}},

    //Wells
    { {8.f, 11.f, 0.f, true}
    },

    //Waypoints
    {{5,-13},
    {9,-3.5},
    {9,4},
    {4,9}
    },

    //Area

    {{-6, -5,11,-18},
    {7,4,11,-5},
    {-6,13,11,4}
    },

    //WaypointToArea

    {{0,0},
    {0,1},
    {1,1},
    {1,2},
    {2,2},
    {2,3}
    },

    //ConexToGraph
    {{0,1},
    {1,2},
    {2,3}
    },
    //Patrulla

    {{0,{-2,-7,5,-7,8,-11,7,-15 }}
    }
};