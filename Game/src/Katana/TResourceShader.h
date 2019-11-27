#pragma once
#include "TResource.h"

class TResource;
class TResourceShader : public TResource
{
private:
    GLuint id;
    GLenum type;

public:
    TResourceShader(){}
    ~TResourceShader(){}

    bool loadResource();
    void draw(){};

    //Get & Set
    GLuint getId(){ return id;};
    GLenum GetAiType(){ return type;};
    void setType(GLenum t){ type = t;};
    void setId(GLuint i){ id = i;};

};

