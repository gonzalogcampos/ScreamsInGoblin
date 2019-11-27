#include "LevelLoader.h"


Level level1 = {
    "res/Mapa00.obj",//Map OBJ
    "res/mapapeque.bmp",//Map BMP
    "res/bullet/Mapa00.bullet",//Map BULLET

    0.f,//Player x
    0.f,//Player y
    -2.f,//Player z

    //Spawns
    {{0.f, -10.f, 0.f, false}},

    //Wells
    { {0.f, 7.f, 0.f, true}
    },

    //Waypoints
    {{5,1},
    {-6,3}
    },

    //Area

    {{-12, 8,13,-17}
    },

    //WaypointToArea

    {{0,0},
    {0,1}
    },

    //ConexToGraph
    {{0,1}
    },
    //Patrulla

    {{0,{7, 1, -8, 3 }}
    }
};