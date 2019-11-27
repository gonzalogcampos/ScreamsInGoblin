#pragma once
#include <vector>

class Area;

class Waypoint
{

    public:
        Waypoint(float x, float y){_x = x; _y = y;}

        virtual ~Waypoint(){}

        float _x, _y;

};

class Conexion
{
    public:
        Conexion(Waypoint* origin, Waypoint* end, float cost){ origen = origin; destino = end; coste = cost;}
        virtual ~Conexion(){}
        Waypoint* origen;
        Waypoint* destino;

        float coste;

};

struct Pointrecord {
    Waypoint* waypoint;
    Conexion* connection;
    float costeactual;

};
struct pesoPath {
    float peso;
    std::vector<Conexion*> path;
};

class Grafo
{
    public:
        Grafo(){}
        virtual ~Grafo(){
            for(std::vector<Conexion*>::iterator iter = _conexiones.begin(); iter!=_conexiones.end(); iter++){

                delete *iter;
            }
            _conexiones.clear();
                 
        }

        std::vector<Conexion*> _conexiones;

        

        Waypoint* getNearestWaypoint(float X, float Y);
        std::vector<Conexion*> getConections(Waypoint* currentWaypoint);


        pesoPath* pathfindingDijkstra(Waypoint* currentWaypoint, Waypoint* objetiveWaypoint);
        Pointrecord* getSmallest(std::vector<Pointrecord*> list);
        Pointrecord* buscar(std::vector<Pointrecord*> list, Waypoint* nodo);
        bool estaEnLaLista(std::vector<Pointrecord*> list, Waypoint* nodo);

      
        void addConexion(Waypoint* w1, Waypoint* w2);


};

class GPS
{
    private:
        Grafo* graph;
        std::vector<Area*> AML;
        std::vector<Waypoint*> ways;


    public: 
        GPS(){graph = new Grafo();}
        virtual ~GPS(){ Clear();}

        void addArea(float xsup, float ysup, float xinf, float yinf);
        void addWaypoint(float coorX, float coorY);
        void addWaypointToArea(int a, int w);
        void addConexionToGraph(int w1, int w2);

        //void Initialice(int lv);
        void Clear();
        std::vector<float> getWay(float xi, float yi, float xf, float yf );
       const std::vector<Area*>& getAreas(){return AML;}
};