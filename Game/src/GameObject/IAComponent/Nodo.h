#pragma once
#include <vector>

/*
Estructura basica del behaviour, todos los tipos de nodo heredan de el
*/
class Nodo{


    public:

        Nodo(){}
        virtual ~Nodo(){clear();}

        std::vector<Nodo*> children;

        void clear();
        virtual bool run();
        void addChild(Nodo* child){
            children.push_back(child);
        }


};

class Selector : public Nodo{

    public:

    Selector():Nodo(){}
    virtual ~Selector(){}
    
    bool run() override;

};

class Secuencia : public Nodo{

    public:

    Secuencia():Nodo(){}
    virtual ~Secuencia(){}

    bool run() override;

};