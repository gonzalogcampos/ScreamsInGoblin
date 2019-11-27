#pragma once
#include "FMesh.h"
#include "TNode.h"
#include "NORender.h"

class NOMesh : public FMesh 
{
    private:
    public:
        NOMesh(){}
        ~NOMesh(){}

        void setPosition(float x, float y, float z);
        void setRotation(float x, float y, float z);
        void setVisible(bool b);
        void setTexture(char* s);
        void isMap();


};

