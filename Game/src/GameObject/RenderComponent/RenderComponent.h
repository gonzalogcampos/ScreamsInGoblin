#pragma once
#include "FMesh.h"
#include "Component.h"
#include "Render.h"

class GameObject;
class RenderComponent : public Component{
    private:
        FMesh* node;
        bool leviosa = false;
        bool rotates = false;
        float time = 0.f;
    public:
        //Creates the componet, adds the parent g, and creates a node on r, with s mesh path
        RenderComponent(GameObject* g, Manager* m, char* s) : Component(g, m){
            node = Render::getInstance()->createMesh(s);
        }
        //Destructor
        virtual ~RenderComponent(){delete node;}

        //Updates the position and the scale of the mesh
        void update(float dt);

        //Sets the visibility to h
        void setVisible(bool h);

        //Sets the texture
        void setTexture(char s[]);

        void isMap();

        void isLeviosa(){leviosa = true;}
        void isRotates(){rotates = true;}

        void setAnimation(char* a, int n){delete node; node = Render::getInstance()->createAnimation(a, n);}
        void setMesh(char* a){delete node; node = Render::getInstance()->createMesh(a);}
};