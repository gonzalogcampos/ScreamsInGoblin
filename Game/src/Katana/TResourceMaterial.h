#pragma once
#include "TResource.h"


class TResourceMaterial : public TResource
{
private:
    GLfloat *amb,*dif,*spe;
    float shine;
public:
    TResourceMaterial();
    ~TResourceMaterial(){}

    bool loadResource(){ return true; };
    void loadResource(aiMaterial* m); 
    void draw();
};
