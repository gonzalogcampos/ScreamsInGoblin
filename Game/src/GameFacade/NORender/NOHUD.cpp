#include "NOHUD.h"
#include "NORender.h"
#include <iostream>

void NOHUD::init()
{

}

void NOHUD::clear()
{

}

void NOHUD::updateValues(float life, float shield, float fps, int score, int spawns, int weapon)
{
    NORender::getInstance()->loop();  
    std::cout<< "-- \n";
   /* std::cout<<"========= H U D ==========\n";
    std::cout<<"  Life: "<<life<<"\n";
    std::cout<<"  Score: "<<score<<"\n";
    std::cout<<"  Spawns: "<<spawns<<"\n";
    std::cout<<"  FPS: "<<fps<<"\n";
    std::cout<<"==========================\n";*/
}