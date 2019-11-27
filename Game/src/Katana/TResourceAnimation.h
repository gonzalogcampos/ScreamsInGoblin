#pragma once
#include "TResource.h"
#include "TResourceOBJ.h"
#include "TResourceMaterial.h"
#include "TResourceTexture.h"
#include <vector>
#include <assimp/Importer.hpp>
#include <assimp/scene.h>
#include <assimp/postprocess.h>
#include <iostream>
class TResourceAnimation : public TResource
{
    protected:
        int numFrames = 1;
        std::vector<TResourceOBJ*> frame;
        TResourceMaterial* material = nullptr;
        TResourceTexture* texture = nullptr;
    public:
        TResourceAnimation(int f);
        ~TResourceAnimation();

        void setFrames(int f){numFrames = f;};
        int getFrames(){return numFrames;};
        void setTexture(TResourceTexture* t){ texture = t;};
        TResourceTexture* getTexture(){ return texture;};
        bool loadResource();
        void draw(int f);
};
