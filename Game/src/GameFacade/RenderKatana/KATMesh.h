#pragma once
#include "FMesh.h"
#include "TNode.h"
#include "KATRender.h"

class KATMesh : public FMesh 
{
    private:
        TNode* mesh;
    public:
        KATMesh(){}
        ~KATMesh(){KATRender::getInstance()->deleteNode(mesh);}

        void setPosition(float x, float y, float z);
        void setRotation(float x, float y, float z);
        void setVisible(bool b);
        void setTexture(char* s);
        void isMap();


        void setMesh(TNode* node){mesh = node;}

        void setAnimation(TNode* node){mesh = node;}

        void deleteNode(){KATRender::getInstance()->deleteNode(mesh); mesh = nullptr;}
};

