#pragma once
#include "TResourceMesh.h"

class TResourceOBJ : public TResource
{
    private:
        std::vector<TResourceMesh*> meshes;
        bool animation = false;
    public:
        TResourceOBJ(){};
        TResourceOBJ(bool a) : animation(a){animation = a;}       //Node no entity
        ~TResourceOBJ(){};

        void setMaterial(TResourceMaterial* m);
        void setTexture(TResourceTexture* t);

        bool loadResource();
        void draw();

        std::vector<std::string> split(std::string str,std::string sep);
};