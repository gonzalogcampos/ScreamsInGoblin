
#include "TResource.h"
#include <iostream>
#include <vector>

class TResourceMaterial;
class TResourceTexture;
class TResourceMesh : public TResource
{
private:
    GLuint *buffer, *IBO;
    GLfloat *bufferdata, *textures;
    GLuint  VAO;
    int nFaces;
    TResourceMaterial* material = nullptr;
    TResourceTexture* texture = nullptr;
    bool activated = false;

public:
    TResourceMesh(){};
    ~TResourceMesh();

    void loadMesh(aiMesh* m);
    bool loadResource(){return false;};
    void draw();

    void setMaterial(TResourceMaterial* m){ material = m;};
    void setTexture(TResourceTexture* t){ texture = t;};

    void setActivated(bool a){ activated=a;};
    bool getActivated(){ return activated;};

    TResourceTexture* getTexture(){ return texture;};
};

