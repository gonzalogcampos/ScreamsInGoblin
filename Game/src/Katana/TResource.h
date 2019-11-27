#pragma once
#include "../../lib/assimp/Importer.hpp"
#include "../../lib/assimp/scene.h"
#include "../../lib/assimp/postprocess.h"

#include "../../lib/GL/glew.h"
#include "../../lib/glm/ext.hpp"

class TResource
{
    protected:
        const char* name;
    public:
        TResource(){};
        virtual ~TResource(){};

        virtual bool loadResource() = 0;
        virtual void draw(){};
        virtual void draw(int i){};

        virtual const char* getName(){ return name;};
        virtual void setName(const char* n);
};
