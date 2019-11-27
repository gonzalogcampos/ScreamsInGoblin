#include <vector>
class Waypoint;

class Area
{
    private:
    std::vector<Waypoint*> waypoints;
    std::vector<float> puntosPatrulla;

    float sx,sy,ix,iy;

    public:
    Area(float supx, float supy, float infx, float infy){sx=supx;sy=supy;ix=infx;iy=infy;}
    virtual ~Area(){}

    bool checkinArea(float pjx, float pjy);
    std::vector<Waypoint*> getWaypoints(){ return waypoints;}

    void addWaypoint(Waypoint* w);
    void addPatrulla(std::vector<float> patrulla);
    std::vector<float> getPatrulla(){return puntosPatrulla;}

    
};