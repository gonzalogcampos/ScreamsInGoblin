#include "Area.h"

bool Area::checkinArea(float pjx, float pjy)
{
    bool inside = false;
    if (pjx>=sx && pjx<=ix && pjy>=iy && pjy<=sy)
        inside = true;

    return inside;
}

void Area::addWaypoint(Waypoint* w)
{
    waypoints.push_back(w);
}

void Area::addPatrulla(std::vector<float> patrulla)
{
    for(std::size_t i = 0; i<patrulla.size(); i++)
        puntosPatrulla.push_back(patrulla[i]);
}